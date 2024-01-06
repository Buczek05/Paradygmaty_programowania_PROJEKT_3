//
// Created by Kacper Bukowski on 06/01/2024.
//

#include "data.h"

Car *create_car(unsigned long int id, char *brand, char *model, int year, char *registration_number) {
    Car *car = malloc(sizeof(Car));
    car->brand = malloc(strlen(brand) + 1);
    car->model = malloc(strlen(model) + 1);
    car->registration_number = malloc(strlen(registration_number) + 1);
    car->id = id;
    strcpy(car->brand, brand);
    strcpy(car->model, model);
    car->year = year;
    strcpy(car->registration_number, registration_number);
    return car;
}

void print_car(void *data) {
    Car *car = (Car *) data;
    printf("ID: %ld\n", car->id);
    printf("Brand: %s\n", car->brand);
    printf("Model: %s\n", car->model);
    printf("Year: %d\n", car->year);
    printf("Registration number: %s\n", car->registration_number);
}

void free_car(void *data) {
    Car *car = (Car *) data;
    free(car->brand);
    free(car->model);
    free(car->registration_number);
    free(car);
}

int search_car_by_id(void *data, void *search_fraze) {
    Car *car = (Car *) data;
    unsigned long int *id = (unsigned long int *) search_fraze;
    return car->id - *id;
}

int search_car_by_brand(void *data, void *search_fraze) {
    Car *car = (Car *) data;
    char *brand = (char *) search_fraze;
    return strcmp(car->brand, brand);
}

int search_car_by_model(void *data, void *search_fraze) {
    Car *car = (Car *) data;
    char *model = (char *) search_fraze;
    return strcmp(car->model, model);
}

int search_car_by_year(void *data, void *search_fraze) {
    Car *car = (Car *) data;
    int *year = (int *) search_fraze;
    return car->year - *year;
}

int search_car_by_registration_number(void *data, void *search_fraze) {
    Car *car = (Car *) data;
    char *registration_number = (char *) search_fraze;
    return strcmp(car->registration_number, registration_number);
}

void save_car(void *data, FILE *file) {
    Car *car = (Car *) data;
    fwrite(car, sizeof(Car), 1, file);
    fwrite(car->brand, sizeof(char), MAX_STRING_LENGTH, file);
    fwrite(car->model, sizeof(char), MAX_STRING_LENGTH, file);
    fwrite(car->registration_number, sizeof(char), MAX_STRING_LENGTH, file);
}

void *load_car(FILE *file) {
    Car *car = malloc(sizeof(Car));
    char *text = malloc(MAX_STRING_LENGTH);
    fread(car, sizeof(Car), 1, file);
    if (feof(file)) {
        return NULL;
    }
    fread(text, sizeof(char), MAX_STRING_LENGTH, file);
    car->brand = malloc(strlen(text) + 1);
    strcpy(car->brand, text);
    fread(text, sizeof(char), MAX_STRING_LENGTH, file);
    car->model = malloc(strlen(text) + 1);
    strcpy(car->model, text);
    fread(text, sizeof(char), MAX_STRING_LENGTH, file);
    car->registration_number = malloc(strlen(text) + 1);
    strcpy(car->registration_number, text);
    return car;
}

unsigned long int get_car_id(void *data) {
    Car *car = (Car *) data;
    return car->id;
}