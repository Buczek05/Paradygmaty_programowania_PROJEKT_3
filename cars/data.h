#ifndef PARADYGMATY_PROGRAMOWANIA_PROJECT_3_CARS_DATA_H
#define PARADYGMATY_PROGRAMOWANIA_PROJECT_3_CARS_DATA_H
#define MAX_STRING_LENGTH 256
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CAR {
    unsigned long int id;
    char *brand;
    char *model;
    int year;
    char *registration_number;
} Car;

Car *create_car(unsigned long int id, char *brand, char *model, int year, char *registration_number);
void print_car(void *data);
void free_car(void *data);
int search_car_by_id(void *data, void *search_fraze);
int search_car_by_brand(void *data, void *search_fraze);
int search_car_by_model(void *data, void *search_fraze);
int search_car_by_year(void *data, void *search_fraze);
int search_car_by_registration_number(void *data, void *search_fraze);
void save_car(void *data, FILE *file);
void *load_car(FILE *file);
unsigned long int get_car_id(void *data);

#endif
