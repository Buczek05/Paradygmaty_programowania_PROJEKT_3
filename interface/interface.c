#include "interface.h"

char cars_file[MAX_STRING_LENGTH] = "data_cars.data";
char workplaces_file[MAX_STRING_LENGTH] = "data_workplaces.data";
char repairs_file[MAX_STRING_LENGTH] = "data_repairs.data";
char test_cars_file[MAX_STRING_LENGTH] = "test_data_cars.data";
char test_workplaces_file[MAX_STRING_LENGTH] = "test_data_workplaces.data";
char test_repairs_file[MAX_STRING_LENGTH] = "test_data_repairs.data";
int test_mode = 0;

void init_interface(int test_mode_local) {
    test_mode = test_mode_local;
    if (test_mode) {
        cars_manager = load_queue(test_cars_file, load_car);
        workplaces_manager = load_queue(test_workplaces_file, load_workplace);
        repairs_manager = load_queue(test_repairs_file, load_repair);
    }
    else{
        cars_manager = load_queue(cars_file, load_car);
        workplaces_manager = load_queue(workplaces_file, load_workplace);
        repairs_manager = load_queue(repairs_file, load_repair);
    }
}

void main_menu() {
    int choice;
    do {
        printf("1. Pojazdy\n");
        printf("2. Warsztaty\n");
        printf("3. Naprawy\n");
        if (test_mode) {
            printf("0. Wyjdz\n");
        }
        else{
            printf("0. Zapisz i wyjdz\n");
        }
        printf("Wybor: ");
        choice = get_int_from_console();
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
    if (!test_mode) {
        save_queue(cars_manager, cars_file, save_car);
        save_queue(workplaces_manager, workplaces_file, save_workplace);
        save_queue(repairs_manager, repairs_file, save_repair);
    }
}