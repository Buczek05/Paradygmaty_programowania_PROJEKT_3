#include "interface.h"

char cars_file[MAX_STRING_LENGTH] = "data_cars";
char workplaces_file[MAX_STRING_LENGTH] = "data_workplaces";
char repairs_file[MAX_STRING_LENGTH] = "data_repairs";

void init_interface() {
    cars_manager = load_queue(cars_file, load_car);
    workplaces_manager = load_queue(workplaces_file, load_workplace);
    repairs_manager = load_queue(repairs_file, load_repair);
}

void main_menu() {
    int choice;
    do {
        printf("1. Pojazdy\n");
        printf("2. Warsztaty\n");
        printf("3. Naprawy\n");
        printf("0. Save and Exit\n");
        printf("Wybor: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                car_menu();
                break;
            case 2:
                workplaces_menu();
                break;
            case 3:
                repairs_menu();
                break;
            case 0:
                save();
                break;
            default:
                printf("Zly wybor!\n");
                break;
        }
    } while (choice != 0);
}

void save() {
    save_queue(cars_manager, cars_file, save_car);
    save_queue(workplaces_manager, workplaces_file, save_workplace);
    save_queue(repairs_manager, repairs_file, save_repair);
}