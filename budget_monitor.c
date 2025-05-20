#include <stdio.h>
#include "TripInfo.h"

void budget_monitor(TripInfo* trip) {
    float total_exp = 0;
    printf("\nBudget Monitoring Report:\n");

    for (int i = 0; i < category_count; i++) {
        int idx = category_indices[i];
        float category_budget = budgets[idx] * trip->days;
        float category_exp = 0;
        for (int d = 0; d < trip->days; d++) {
            category_exp += expenses[idx][d];
        }
        total_exp += category_exp;
        if (category_exp > category_budget)
            printf("You overspent Rs. %.2f in %s.\n", category_exp - category_budget, category_names[idx]);
        else if (category_exp < category_budget)
            printf("You saved Rs. %.2f in %s.\n", category_budget - category_exp, category_names[idx]);
        else
            printf("You met the budget exactly in %s.\n", category_names[idx]);
    }

    float remaining_funds = (trip->budget + trip->funds) - total_exp;
    printf("\nTotal Budget: Rs. %.2f\nTotal Expenses: Rs. %.2f\nRemaining Funds: Rs. %.2f\n",
           trip->budget, total_exp, remaining_funds);
}