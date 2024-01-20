#include "interface.h"


void car_menu(){
    int choice;
    printf("1. Dodaj samochod\n");
    printf("2. Usun samochod\n");
    printf("3. Edytuj samochod\n");
    printf("4. Wyswietl samochody\n");
    printf("5. Wyszukaj samochod\n");
    printf("0. Wroc\n");
    printf("Wybor: ");
    choice = get_int_from_console();
    switch (choice) {
        case 1:
            add_car();
            break;
        case 2:
            delete_car();
            break;
        case 3:
            edit_car();
            break;
        case 4:
            print_cars();
            break;
        case 5:
            search_car();
            break;
        case 0:
            return;
        default:
            printf("Nie ma takiej opcji\n");
            break;
    }
    car_menu();
}

void add_car(){
    char *brand = malloc(MAX_STRING_LENGTH);
    char *model = malloc(MAX_STRING_LENGTH);
    int year;
    char *registration_number = malloc(MAX_STRING_LENGTH);
    printf("Podaj marke: ");
    strcpy(brand, get_string_from_console());
    printf("Podaj model: ");
    strcpy(model, get_string_from_console());
    printf("Podaj rok produkcji: ");
    year = get_int_from_console();
    printf("Podaj numer rejestracyjny: ");
    strcpy(registration_number, get_string_from_console());
    unsigned long int id = get_next_id(cars_manager, get_car_id);
    Car *car = create_car(id, brand, model, year, registration_number);
    add_to_queue_as_last(cars_manager, car);
    printf("Dodano samochod: \n");
}

void delete_car(){
    unsigned long int id;
    printf("Podaj ID: ");
    id = get_unsigned_long_int_from_console();
    SearchResult *search_result = search_queue(cars_manager, &id, search_car_by_id);
    if (search_result->found) {
        delete_element(cars_manager, search_result->element, free_car);
        printf("Usunieto warsztat: \n");
    } else {
        printf("Nie znaleziono!\n");
    }
    free(search_result);
}

void edit_car(){
    unsigned long int id;
    printf("Podaj ID: ");
    id = get_unsigned_long_int_from_console();
    SearchResult *search_result = search_queue(cars_manager, &id, search_car_by_id);
    if (search_result->found) {
        int choice;
        char *text = malloc(MAX_STRING_LENGTH);
        do{
            printf("Wybierz co chcesz edytowac: \n");
            printf("1. Marke\n");
            printf("2. Model\n");
            printf("3. Rok produkcji\n");
            printf("4. Numer rejestracyjny\n");
            printf("0. Wroc\n");
            printf("Wybor: ");
            choice = get_int_from_console();
            switch (choice) {
                case 1:
                    printf("Podaj marke: ");
                    text = get_string_from_console();
                    ((Car *) search_result->element->data)->brand = realloc(((Car *) search_result->element->data)->brand, strlen(text) + 1);
                    strcpy(((Car *) search_result->element->data)->brand, text);
                    break;
                case 2:
                    printf("Podaj model: ");
                    text = get_string_from_console();
                    ((Car *) search_result->element->data)->model = realloc(((Car *) search_result->element->data)->model, strlen(text) + 1);
                    strcpy(((Car *) search_result->element->data)->model, text);
                    break;
                case 3:
                    printf("Podaj rok produkcji: ");
                    ((Car *) search_result->element->data)->year = get_int_from_console();
                    break;
                case 4:
                    printf("Podaj numer rejestracyjny: ");
                    text = get_string_from_console();
                    ((Car *) search_result->element->data)->registration_number = realloc(((Car *) search_result->element->data)->registration_number, strlen(text) + 1);
                    strcpy(((Car *) search_result->element->data)->registration_number, text);
                    break;
                case 0:
                    printf("Wyjscie\n");
                    break;
                default:
                    printf("Nie ma takiej opcji\n");
                    break;
            }
        } while(choice != 0);
    } else {
        printf("Nie znaleziono!\n");
    }
    free(search_result);
}

void print_cars(){
    print_queue(cars_manager, print_car);
}

void search_car(){
    int choice;
    printf("Wybierz po czym chcesz wyszukac: \n");
    printf("1. ID\n");
    printf("2. Marka\n");
    printf("3. Model\n");
    printf("4. Rok produkcji\n");
    printf("5. Numer rejestracyjny\n");
    printf("0. Wroc\n");
    printf("Wybor: ");
    choice = get_int_from_console();
    MultiSearchResult *multi_search_result = NULL;
    unsigned long int id;
    int year;
    char *text = malloc(MAX_STRING_LENGTH);
    switch (choice) {
        case 1:
            printf("Podaj ID: ");
            id = get_unsigned_long_int_from_console();
            multi_search_result = multi_search_queue(cars_manager, &id, search_car_by_id);
            break;
        case 2:
            printf("Podaj marke: ");
            strcpy(text, get_string_from_console());
            multi_search_result = multi_search_queue(cars_manager, text, search_car_by_brand);
            break;
        case 3:
            printf("Podaj model: ");
            strcpy(text, get_string_from_console());
            multi_search_result = multi_search_queue(cars_manager, text, search_car_by_model);
            break;
        case 4:
            printf("Podaj rok produkcji: ");
            year = get_int_from_console();
            multi_search_result = multi_search_queue(cars_manager, &year, search_car_by_year);
            break;
        case 5:
            printf("Podaj numer rejestracyjny: ");
            strcpy(text, get_string_from_console());
            multi_search_result = multi_search_queue(cars_manager, text, search_car_by_registration_number);
            break;
        case 0:
            return;
        default:
            printf("Nie ma takiej opcji\n");
            break;
    }
    if (multi_search_result->found) {
        printf("Znaleziono: \n");
        print_queue(multi_search_result->queue_manager, print_car);
    } else {
        printf("Nie znaleziono!\n");
    }
}
