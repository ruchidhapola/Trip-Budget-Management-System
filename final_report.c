#include <stdio.h>
#include "TripInfo.h"

void final_report(TripInfo* trip) {
    printf("\nFinal Report for %s:\n", trip->name);
    printf("Total Budget: Rs. %.2f\n", trip->budget);
    printf("Fund Money: Rs. %.2f\n", trip->funds);
    printf("Trip Duration: %d days\n", trip->days);
    printf("Total Expenses: Rs. %.2f\n", trip->expenses);
    printf("Remaining Funds: Rs. %.2f\n", (trip->budget + trip->funds) - trip->expenses);
}