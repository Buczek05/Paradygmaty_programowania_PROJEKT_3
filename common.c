#include "common.h"

char *get_string_from_console() {
    char *string = malloc(MAX_STRING_LENGTH * sizeof(char));
    fgets(string, MAX_STRING_LENGTH, stdin);
    string[strlen(string) - 1] = '\0';
    return string;
}