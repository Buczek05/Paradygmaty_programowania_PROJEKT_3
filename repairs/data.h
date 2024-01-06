#ifndef PARADYGMATY_PROGRAMOWANIA_PROJECT_3_REPAIRS_DATA_H
#define PARADYGMATY_PROGRAMOWANIA_PROJECT_3_REPAIRS_DATA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../common.h"

typedef struct REPAIR {
    unsigned long int id;
    unsigned long int car_id;
    unsigned long int workplace_id;
    char *title;
    char *description;
    float parts_cost;
    float work_cost;
    unsigned long int added_time;
    unsigned long int start_time;
    unsigned long int end_time;
    int is_started;
    int is_done;
    int is_paid;
} Repair;

Repair *create_repair(unsigned long int id, unsigned long int car_id, unsigned long int workplace_id, char *title, char *description, float parts_cost, float work_cost, long int added_time, long int start_time, long int end_time, int is_started, int is_done, int is_paid);
char *convert_date(long int timestamp);
float get_total_cost(Repair *repair);
void print_repair(void *data);
void free_repair(void *data);
int search_repair_by_id(void *data, void *search_fraze);
int search_repair_by_car_id(void *data, void *search_fraze);
int search_repair_by_workplace_id(void *data, void *search_fraze);
int search_repair_by_title(void *data, void *search_fraze);
void save_repair(void *data, FILE *file);
void *load_repair(FILE *file);
unsigned long int get_repair_id(void *data);

#endif
