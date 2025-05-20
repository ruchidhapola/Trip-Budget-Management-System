#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "TripInfo.h"

void expense_record(TripInfo *trip) {
    FILE *exp_file = fopen("expenses.txt", "a");
    if (!exp_file) {
        printf("Error opening expenses file.\n");
        return;
    }

    float daily_budgets[MAX_CATEGORIES] = {0};
    float total_expenses[MAX_CATEGORIES] = {0};

    for (int i = 0; i < category_count; i++) {
        int idx = category_indices[i];
        daily_budgets[i] = budgets[idx];
    }

    for (int day = 1; day <= trip->days; day++) {
        float day_total = 0;
        printf("\nDay %d Expenses:\n", day);
        fprintf(exp_file, "%s-Day%d", trip->name, day);

        for (int i = 0; i < category_count; i++) {
            int idx = category_indices[i];
            float daily_expense;
            printf("Enter expense for %s: ", category_names[idx]);
            scanf("%f", &daily_expense);

            expenses[idx][day - 1] = daily_expense;
            total_expenses[i] += daily_expense;
            fprintf(exp_file, "\t%s(%.2f)", category_names[idx], daily_expense);
            day_total += daily_expense;

            if (daily_expense > daily_budgets[i]) {
                printf("Alert: Overspent in %s by Rs. %.2f\n", category_names[idx], daily_expense - daily_budgets[i]);
                char realloc_choice;
                printf("Do you want to reallocate your budget? (Y/N): ");
                scanf(" %c", &realloc_choice);
                if (realloc_choice == 'Y' || realloc_choice == 'y') {
                    float new_budget;
                    printf("Enter new daily budget for %s: ", category_names[idx]);
                    scanf("%f", &new_budget);
                    if (new_budget * trip->days >= total_expenses[i]) {
                        budgets[idx] = new_budget;
                        daily_budgets[i] = new_budget;
                    } else {
                        printf("New budget is insufficient based on current expenses.\n");
                    }
                }
            }
        }
        fprintf(exp_file, "\n");
        trip->expenses += day_total;
    }
    fclose(exp_file);

    FILE *budget_file = fopen("budget.txt", "r");
    if (!budget_file) {
        printf("Error reading budget file.\n");
        return;
    }
    FILE *temp_file = fopen("temp.txt", "w");
    if (!temp_file) {
        fclose(budget_file);
        printf("Error creating temp file.\n");
        return;
    }

    char line[1024];
    int found = 0;

    while (fgets(line, sizeof(line), budget_file)) {
        char temp[1024];
        strcpy(temp, line);
        char *token = strtok(temp, "\t");

        if (token && strcasecmp(token, trip->name) == 0) {
            found = 1;
            fprintf(temp_file, "%s\t%.2f\t%.2f\t%.2f\t%d", trip->name, trip->budget, trip->budget + trip->funds - trip->expenses, trip->expenses, trip->days);
            for (int i = 0; i < category_count; i++) {
                int idx = category_indices[i];
                fprintf(temp_file, "\t%s(%.2f):%.2f", category_names[idx], budgets[idx], total_expenses[i]);
            }
            fprintf(temp_file, "\n");
        } else {
            fputs(line, temp_file);
        }
    }

    fclose(budget_file);
    fclose(temp_file);

    if (!found) {
        FILE *append_file = fopen("budget.txt", "a");
        fprintf(append_file, "%s\t%.2f\t%.2f\t%.2f\t%d", trip->name, trip->budget, trip->budget + trip->funds - trip->expenses, trip->expenses, trip->days);
        for (int i = 0; i < category_count; i++) {
            int idx = category_indices[i];
            fprintf(append_file, "\t%s(%.2f):%.2f", category_names[idx], budgets[idx], total_expenses[i]);
        }
        fprintf(append_file, "\n");
        fclose(append_file);
    } else {
        remove("budget.txt");
        rename("temp.txt", "budget.txt");
    }

    printf("\nTotal Expenses Recorded: Rs. %.2f\n", trip->expenses);
    printf("Updated Remaining Funds: Rs. %.2f\n", trip->budget + trip->funds - trip->expenses);
    printf("Expense record saved successfully.\n");
}