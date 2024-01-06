#ifndef PARADYGMATY_PROGRAMOWANIA_PROJECT_3_WORKPLACE_DATA_H
#define PARADYGMATY_PROGRAMOWANIA_PROJECT_3_WORKPLACE_DATA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../common.h"

typedef struct WORKPLACE {
    unsigned long int id;
    char *name;
} Workplace;

Workplace *create_workplace(unsigned long int id, char *name);
void print_workplace(void *data);
void free_workplace(void *data);
int search_workplace_by_id(void *data, void *search_fraze);
int search_workplace_by_name(void *data, void *search_fraze);
void save_workplace(void *data, FILE *file);
void *load_workplace(FILE *file);
unsigned long int get_workplace_id(void *data);

#endif
