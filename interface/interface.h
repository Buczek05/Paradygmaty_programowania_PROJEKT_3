#ifndef PARADYGMATY_PROGRAMOWANIA_PROJECT_3_INTERFACE_H
#define PARADYGMATY_PROGRAMOWANIA_PROJECT_3_INTERFACE_H

#include "../workplaces/data.h"
#include "../workplaces/interface.h"
#include "../repairs/data.h"
#include "../repairs/interface.h"
#include "../cars/data.h"
#include "../cars/interface.h"
#include "../queue/queue.h"

QueueManager *cars_manager, *workplaces_manager, *repairs_manager;

void init_interface(int test_mode);
void save();
void main_menu();


#endif
