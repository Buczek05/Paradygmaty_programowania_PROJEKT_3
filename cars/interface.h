#ifndef PARADYGMATY_PROGRAMOWANIA_PROJECT_3_CARS_INTERFACE_H
#define PARADYGMATY_PROGRAMOWANIA_PROJECT_3_CARS_INTERFACE_H

#include "../common.h"
#include "../workplaces/data.h"
#include "../repairs/data.h"
#include "../cars/data.h"
#include "../queue/queue.h"

extern QueueManager *cars_manager, *workplaces_manager, *repairs_manager;

void car_menu();
void add_car();
void delete_car();
void edit_car();
void print_cars();
void search_car();

#endif
