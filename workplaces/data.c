#include "data.h"

Workplace *create_workplace(unsigned long int id, char *name) {
    Workplace *workplace = malloc(sizeof(Workplace));
    workplace->name = malloc(strlen(name) + 1);
    workplace->id = id;
    strcpy(workplace->name, name);
    return workplace;
}

void print_workplace(void *data) {
    Workplace *workplace = (Workplace *) data;
    printf("ID: %ld\n", workplace->id);
    printf("Name: %s\n", workplace->name);
    printf("\n");
}

void free_workplace(void *data) {
    Workplace *workplace = (Workplace *) data;
    free(workplace->name);
    free(workplace);
}

int search_workplace_by_id(void *data, void *search_fraze) {
    Workplace *workplace = (Workplace *) data;
    unsigned long int *id = (unsigned long int *) search_fraze;
    return workplace->id - *id;
}

int search_workplace_by_name(void *data, void *search_fraze) {
    Workplace *workplace = (Workplace *) data;
    char *name = (char *) search_fraze;
    return strcmp(workplace->name, name);
}

void save_workplace(void *data, FILE *file) {
    Workplace *workplace = (Workplace *) data;
    fwrite(workplace, sizeof(Workplace), 1, file);
    fwrite(workplace->name, sizeof(char), MAX_STRING_LENGTH, file);
}

void *load_workplace(FILE *file) {
    Workplace *workplace = malloc(sizeof(Workplace));
    char *text = malloc(MAX_STRING_LENGTH);
    fread(workplace, sizeof(Workplace), 1, file);
    if (feof(file)) {
        return NULL;
    }
    fread(text, sizeof(char), MAX_STRING_LENGTH, file);
    workplace->name = malloc(strlen(text) + 1);
    strcpy(workplace->name, text);
    return workplace;
}

unsigned long int get_workplace_id(void *data) {
    Workplace *workplace = (Workplace *) data;
    return workplace->id;
}