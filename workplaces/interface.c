#include "interface.h"

void workplaces_menu() {
    int choice;
    do {
        printf("1. Dodaj warsztat\n");
        printf("2. Usun warsztat\n");
        printf("3. Edytuj warsztat\n");
        printf("4. Wyswietl warsztaty\n");
        printf("5. Wyszukaj warsztat\n");
        printf("0. Powrot\n");
        printf("Wybor: ");
        choice = get_int_from_console();
        switch (choice) {
            case 1:
                add_workplace();
                break;
            case 2:
                delete_workplace();
                break;
            case 3:
                edit_workplace();
                break;
            case 4:
                print_workplaces();
                break;
            case 5:
                search_workplace();
                break;
            case 0:
                break;
            default:
                printf("Niepoprawny wybor!\n");
        }
    } while (choice != 0);
}

void add_workplace() {
    char *name = malloc(MAX_STRING_LENGTH);
    printf("Podaj nazwe: ");
    strcpy(name, get_string_from_console());
    unsigned long int id = get_next_id(workplaces_manager, get_workplace_id);
    Workplace *workplace = create_workplace(id, name);
    add_to_queue_as_last(workplaces_manager, workplace);
    printf("Dodano warsztat: \n");
}

void delete_workplace() {
    unsigned long int id;
    printf("Podaj ID: ");
    id = get_unsigned_long_int_from_console();
    SearchResult *search_result = search_queue(workplaces_manager, &id, search_workplace_by_id);
    if (search_result->found) {
        delete_element(workplaces_manager, search_result->element, free_workplace);
        printf("Usunieto warsztat: \n");
    } else {
        printf("Nie znaleziono!\n");
    }
    free(search_result);
}

void edit_workplace() {
    unsigned long int id;
    printf("Podaj ID: ");
    id = get_unsigned_long_int_from_console();
    SearchResult *search_result = search_queue(workplaces_manager, &id, search_workplace_by_id);
    if (search_result->found) {
        Workplace *workplace = (Workplace *) search_result->element->data;
        char *name = malloc(MAX_STRING_LENGTH);
        printf("Podaj nazwe: ");
        strcpy(name, get_string_from_console());
        free(workplace->name);
        workplace->name = malloc(strlen(name) + 1);
        strcpy(workplace->name, name);
    } else {
        printf("Nie znaleziono!\n");
    }
    free(search_result);
    printf("Edytowano warsztat: \n");
}

void print_workplaces() {
    print_queue(workplaces_manager, print_workplace);
}

void search_workplace() {
    char *name = malloc(MAX_STRING_LENGTH);
    printf("Podaj nazwe: ");
    strcpy(name, get_string_from_console());
    MultiSearchResult *search_result = multi_search_queue(workplaces_manager, name, search_workplace_by_name);
    if (search_result->found) {
        printf("Znaleziono: \n");
        print_queue(search_result->queue_manager, print_workplace);
    } else {
        printf("Nie znaleziono!\n");
    }
    free(search_result->queue_manager);
    free(search_result);
}