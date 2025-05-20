#include <stdio.h>
#include "TripInfo.h"
#include "choose_categories.h"
#include "budget_allotment.h"
#include "expense_record.h"
#include "budget_monitor.h"
#include "fund_track.h"
#include "final_report.h"
#include "login_auth.h"  // <-- Added

const char* category_names[] = {
    "Food", "Hotel Stay", "Shopping", "Vehicle Cost", "Travel", "Fun Activity", "Others"
};

float budgets[MAX_CATEGORIES] = {0};
float expenses[MAX_CATEGORIES][MAX_DAYS] = {0};
int category_indices[MAX_CATEGORIES];
int category_count = 0;

int main() {
    if (!login()) {  // <-- Added login check
        return 1;    // exit if login fails
    }

    TripInfo trip;
    printf("Enter Your Name: ");
    scanf(" %[^\n]", trip.name);
    printf("Enter Total Budget: ");
    scanf("%f", &trip.budget);
    printf("Enter Fund Money: ");
    scanf("%f", &trip.funds);
    printf("Enter Number of Days of Trip: ");
    scanf("%d", &trip.days);
    trip.expenses = 0;

    choose_categories();

    int choice;
    char cont;
    do {
        printf("\nSelect an option:\n");
        printf("1. Budget Allotment\n2. Expense Record\n3. Budget Monitor\n4. Fund Track\n5. Final Report\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: budget_allotment(&trip); break;
            case 2: expense_record(&trip); break;
            case 3: budget_monitor(&trip); break;
            case 4: fund_track(&trip); break;
            case 5: final_report(&trip); break;
            default: printf("Invalid choice.\n");
        }
        printf("Do you want to perform another function? (Y/N): ");
        scanf(" %c", &cont);
    } while (cont == 'y' || cont == 'Y');

    return 0;
}
