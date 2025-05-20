#include <stdio.h>
#include "TripInfo.h"

void budget_allotment(TripInfo* trip) {
    float total = 0;
    do {
        total = 0;
        for (int i = 0; i < category_count; i++) {
            printf("Enter daily budget for %s: ", category_names[category_indices[i]]);
            scanf("%f", &budgets[category_indices[i]]);
            total += budgets[category_indices[i]] * trip->days;
        }
        if (total > trip->budget) {
            printf("\nTotal daily allocation exceeds your overall budget (%.2f > %.2f).\n", total, trip->budget);
            printf("Please re-enter the daily budgets.\n\n");
        }
    } while (total > trip->budget);

    FILE *fp = fopen("budget.txt", "a");
    if (!fp) {
        printf("Error saving budget.\n");
        return;
    }
    fclose(fp);
    printf("Budget allotment saved successfully.\n");
}