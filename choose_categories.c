#include <stdio.h>
#include "TripInfo.h"

void choose_categories() {
    char choice;
    category_count = 0;
    do {
        int option;
        printf("\nSelect a category:\n");
        for (int i = 0; i < 7; i++) {
            printf("%d. %s\n", i + 1, category_names[i]);
        }
        printf("Enter choice (1-7): ");
        scanf("%d", &option);
        if (option >= 1 && option <= 7) {
            category_indices[category_count++] = option - 1;
        } else {
            printf("Invalid option.\n");
        }
        printf("Do You Want To Add More Categories (Y/N)? ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
}