#include <stdio.h>
#include "TripInfo.h"

void fund_track(TripInfo* trip) {
    float remaining_funds = (trip->budget + trip->funds) - trip->expenses;
    printf("\nFund Tracking Report:\n");
    printf("Total Budget: Rs. %.2f\n", trip->budget);
    printf("Fund Money: Rs. %.2f\n", trip->funds);
    printf("Total Expenses: Rs. %.2f\n", trip->expenses);
    printf("Remaining Funds: Rs. %.2f\n", remaining_funds);
}