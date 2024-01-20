//
// Created by Kacper Bukowski on 06/01/2024.
//

#include "data.h"

Repair *create_repair(unsigned long int id, unsigned long int car_id, unsigned long int workplace_id, char *title, char *description,
                      float parts_cost, float work_cost, long int added_time, long int start_time, long int end_time,
                      int is_started, int is_done, int is_paid) {
    Repair *repair = malloc(sizeof(Repair));
    repair->title = malloc(strlen(title) + 1);
    repair->description = malloc(strlen(description) + 1);
    repair->id = id;
    repair->car_id = car_id;
    repair->workplace_id = workplace_id;
    strcpy(repair->title, title);
    strcpy(repair->description, description);
    repair->parts_cost = parts_cost;
    repair->work_cost = work_cost;
    repair->added_time = added_time;
    repair->start_time = start_time;
    repair->end_time = end_time;
    repair->is_started = is_started;
    repair->is_done = is_done;
    repair->is_paid = is_paid;
    return repair;
}

float get_total_cost(Repair *repair) {
    return repair->parts_cost + repair->work_cost;
}

void print_repair(void *data) {
    Repair *repair = (Repair *) data;
    printf("ID: %ld\n", repair->id);
    printf("Pojazd ID: %ld\n", repair->car_id);
    printf("Stanowisko pracy ID: %ld\n", repair->workplace_id);
    printf("Tytul: %s\n", repair->title);
    printf("Opis: %s\n", repair->description);
    printf("Koszt czesci: %.2f\n", repair->parts_cost);
    printf("Koszt pracy: %.2f\n", repair->work_cost);
    printf("Calkowity koszt: %.2f\n", get_total_cost(repair));
    printf("Czas dodania: %s\n", convert_date(repair->added_time));
    printf("Czas rozpoczecia: %s\n", convert_date(repair->start_time));
    printf("Czas zakonczenia: %s\n", convert_date(repair->end_time));
    printf("Czy rozpoczeta: %d\n", repair->is_started);
    printf("Czy skonczona: %d\n", repair->is_done);
    printf("Czy zaplacona: %d\n", repair->is_paid);
    printf("\n");
}

char *convert_date(unsigned long int timestamp) {
    if (timestamp == 0) {
        return "-";
    }
    char *date = malloc(20);
    time_t time = timestamp;
    struct tm *timeinfo;
    timeinfo = localtime(&time);
    strftime(date, 20, "%d/%m/%Y %H:%M:%S", timeinfo);
    return date;
}

void free_repair(void *data) {
    Repair *repair = (Repair *) data;
    free(repair->title);
    free(repair->description);
    free(repair);
}

int search_repair_by_id(void *data, void *search_fraze) {
    Repair *repair = (Repair *) data;
    unsigned long int *id = (unsigned long int *) search_fraze;
    return repair->id - *id;
}

int search_repair_by_car_id(void *data, void *search_fraze) {
    Repair *repair = (Repair *) data;
    unsigned long int *car_id = (unsigned long int *) search_fraze;
    return repair->car_id - *car_id;
}

int search_repair_by_workplace_id(void *data, void *search_fraze) {
    Repair *repair = (Repair *) data;
    unsigned long int *workplace_id = (unsigned long int *) search_fraze;
    return repair->workplace_id - *workplace_id;
}

int search_repair_by_title(void *data, void *search_fraze) {
    Repair *repair = (Repair *) data;
    char *title = (char *) search_fraze;
    return strcmp(repair->title, title);
}

void save_repair(void *data, FILE *file) {
    Repair *repair = (Repair *) data;
    fwrite(repair, sizeof(Repair), 1, file);
    fwrite(repair->title, sizeof(char), MAX_STRING_LENGTH, file);
    fwrite(repair->description, sizeof(char), MAX_DESCRIPTION_LENGTH, file);
}

void *load_repair(FILE *file) {
    Repair *repair = malloc(sizeof(Repair));
    char *text = malloc(MAX_STRING_LENGTH);
    char *description = malloc(MAX_DESCRIPTION_LENGTH);
    fread(repair, sizeof(Repair), 1, file);
    if (feof(file)) {
        return NULL;
    }
    fread(text, sizeof(char), MAX_STRING_LENGTH, file);
    repair->title = malloc(strlen(text) + 1);
    strcpy(repair->title, text);
    fread(description, sizeof(char), MAX_DESCRIPTION_LENGTH, file);
    repair->description = malloc(strlen(description) + 1);
    strcpy(repair->description, description);
    return repair;
}

unsigned long int get_repair_id(void *data) {
    Repair *repair = (Repair *) data;
    return repair->id;
}