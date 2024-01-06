#ifndef PARADYGMATY_PROGRAMOWANIA_PROJECT_3_REPAIRS_INTERFACE_H
#define PARADYGMATY_PROGRAMOWANIA_PROJECT_3_REPAIRS_INTERFACE_H

#include "../common.h"
#include "../workplaces/data.h"
#include "../repairs/data.h"
#include "../cars/data.h"
#include "../queue/queue.h"

extern QueueManager *cars_manager, *workplaces_manager, *repairs_manager;

void repairs_menu();
void add_repair();
void delete_repair();
void edit_repair();
void edit_information(Repair *repair);
void edit_costs(Repair *repair);
void edit_times(Repair *repair);
void edit_statuses(Repair *repair);
void print_repairs();
void search_repair();

#endif
