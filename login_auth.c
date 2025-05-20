// login_auth.c
#include <stdio.h>
#include <string.h>
#include "login_auth.h"

int login() {
    char username[50], password[50];
    const char valid_username[] = "admin";
    const char valid_password[] = "1234";

    printf("Login Required\n");
    printf("Username: ");
    scanf(" %s", username);
    printf("Password: ");
    scanf(" %s", password);

    if (strcmp(username, valid_username) == 0 && strcmp(password, valid_password) == 0) {
        printf("Login successful.\n");
        return 1;
    } else {
        printf("Invalid credentials.\n");
        return 0;
    }
}
