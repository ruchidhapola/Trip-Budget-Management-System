#ifndef TRIPINFO_H
#define TRIPINFO_H

#define MAX_CATEGORIES 10
#define MAX_DAYS 30

extern const char* category_names[7];

typedef struct {
    char name[50];
    float budget;
    float funds;
    float expenses;
    int days;
} TripInfo;

extern float budgets[MAX_CATEGORIES];
extern float expenses[MAX_CATEGORIES][MAX_DAYS];
extern int category_indices[MAX_CATEGORIES];
extern int category_count;

#endif