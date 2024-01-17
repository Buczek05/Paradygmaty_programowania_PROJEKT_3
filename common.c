#include "common.h"

char *get_string_from_console() {
    char *string = malloc(MAX_STRING_LENGTH * sizeof(char));
    fgets(string, MAX_STRING_LENGTH, stdin);
    string[strlen(string) - 1] = '\0';
    return string;
}

int get_int_from_console() {
    int number, result;
    do{
        result = scanf("%d", &number);
        getchar();
        if (result != 1) {
            printf("Podaj liczbe!\n");
        }
    } while (result != 1);
    return number;
}

int get_unsigned_long_int_from_console() {
    unsigned long number;
    int result;
    do{
        result = scanf("%lu", &number);
        getchar();
        if (result != 1) {
            printf("Podaj liczbe!\n");
        }
    } while (result != 1);
    return number;
}

float get_float_from_console() {
    float number, result;
    do{
        result = scanf("%f", &number);
        getchar();
        if (result != 1) {
            printf("Podaj liczbe!\n");
        }
    } while (result != 1);
    return number;
}
