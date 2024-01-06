#ifndef PARADYGMATY_PROGRAMOWANIA_PROJECT_3_WORKPLACES_INTERFACE_H
#define PARADYGMATY_PROGRAMOWANIA_PROJECT_3_WORKPLACES_INTERFACE_H

#include "../common.h"
#include "../workplaces/data.h"
#include "../repairs/data.h"
#include "../cars/data.h"
#include "../queue/queue.h"

extern QueueManager *cars_manager, *workplaces_manager, *repairs_manager;

void workplaces_menu();
void add_workplace();
void delete_workplace();
void edit_workplace();
void print_workplaces();
void search_workplace();

#endif
