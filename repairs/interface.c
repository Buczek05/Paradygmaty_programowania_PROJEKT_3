#include "interface.h"
void repairs_menu(){
    int choice;
    do{
        printf("1. Dodaj naprawe\n");
        printf("2. Usun naprawe\n");
        printf("3. Edytuj naprawe\n");
        printf("4. Wyswietl naprawy\n");
        printf("5. Wyszukaj naprawe\n");
        printf("0. Powrot\n");
        scanf("%d", &choice);
        getchar();
        switch(choice){
            case 1:
                add_repair();
                break;
            case 2:
                delete_repair();
                break;
            case 3:
                edit_repair();
                break;
            case 4:
                print_repairs();
                break;
            case 5:
                search_repair();
                break;
            case 0:
                break;
            default:
                printf("Nie ma takiej opcji\n");
                break;
        }
    }while(choice != 0);
}

void add_repair(){
    unsigned long int id = get_next_id(repairs_manager, get_repair_id), car_id, workplace_id;
    char *title = malloc(MAX_STRING_LENGTH), *description = malloc(MAX_DESCRIPTION_LENGTH);
    long int add_date = time(NULL);
    float parts_cost, work_cost;
    printf("Podaj ID samochodu: ");
    scanf("%ld", &car_id);
    getchar();
    if (search_queue(cars_manager, &car_id, search_car_by_id)->found == 0) {
        printf("Nie znaleziono samochodu!\n");
        return;
    }
    printf("Podaj ID warsztatu: ");
    scanf("%ld", &workplace_id);
    getchar();
    if (search_queue(workplaces_manager, &workplace_id, search_workplace_by_id)->found == 0) {
        printf("Nie znaleziono warsztatu!\n");
        return;
    }
    printf("Podaj tytul: ");
    strcpy(title, get_string_from_console());
    printf("Podaj opis: ");
    strcpy(description, get_string_from_console());
    printf("Podaj koszt czesci: ");
    scanf("%f", &parts_cost);
    getchar();
    printf("Podaj koszt pracy: ");
    scanf("%f", &work_cost);
    getchar();
    Repair *repair = create_repair(id, car_id, workplace_id, title, description, parts_cost, work_cost, add_date, 0, 0, 0, 0, 0);
    add_to_queue_as_last(repairs_manager, repair);
    printf("Dodano naprawe: \n");
}

void delete_repair(){
    unsigned long int id;
    printf("Podaj ID: ");
    scanf("%ld", &id);
    getchar();
    SearchResult *search_result = search_queue(repairs_manager, &id, search_repair_by_id);
    if(search_result->found){
        delete_element(repairs_manager, search_result->element, free_repair);
        printf("Usunieto naprawe: \n");
    }else{
        printf("Nie znaleziono!\n");
    }
    free(search_result);
}

void edit_repair(){
    unsigned long int id;
    printf("Podaj ID: ");
    scanf("%ld", &id);
    getchar();
    SearchResult *search_result = search_queue(repairs_manager, &id, search_repair_by_id);
    if(search_result->found){
        Repair *repair = (Repair *) search_result->element->data;
        int choice;
        do{
            print_repair(repair);
            printf("1. Edytuj informacje\n");
            printf("2. Edytuj koszta\n");
            printf("3. Edytuj czasy\n");
            printf("4. Edytuj statusy\n");
            printf("0. Powrot\n");
            scanf("%d", &choice);
            getchar();
            switch(choice){
                case 1:
                    edit_information(repair);
                    break;
                case 2:
                    edit_costs(repair);
                    break;
                case 3:
                    edit_times(repair);
                    break;
                case 4:
                    edit_statuses(repair);
                    break;
                case 0:
                    break;
                default:
                    printf("Nie ma takiej opcji\n");
                    break;
            }
        } while(choice != 0);
    }
    else{
        printf("Nie znaleziono!\n");
    }
    free(search_result);
}

void edit_information(Repair *repair){
    printf("1. Edytuj tytul\n");
    printf("2. Edytuj opis\n");
    printf("3. Edytuj ID samochodu\n");
    printf("4. Edytuj ID warsztatu\n");
    printf("0. Powrot\n");
    int choice, id;
    scanf("%d", &choice);
    getchar();
    switch(choice){
        case 1:
            printf("Podaj tytul: ");
            repair->title = realloc(repair->title, MAX_STRING_LENGTH);
            strcpy(repair->title, get_string_from_console());
            break;
        case 2:
            printf("Podaj opis: ");
            repair->description = realloc(repair->description, MAX_DESCRIPTION_LENGTH);
            strcpy(repair->description, get_string_from_console());
            break;
        case 3:
            printf("Podaj ID samochodu: ");
            scanf("%ld", &id);
            getchar();
            if (search_queue(cars_manager, &id, search_car_by_id)->found == 0) {
                printf("Nie znaleziono samochodu!\n");
                return;
            }
            break;
        case 4:
            printf("Podaj ID warsztatu: ");
            scanf("%ld", &id);
            getchar();
            if (search_queue(workplaces_manager, &id, search_workplace_by_id)->found == 0) {
                printf("Nie znaleziono warsztatu!\n");
                return;
            }
            break;
        case 0:
            break;
        default:
            printf("Nie ma takiej opcji\n");
            break;
    }
}

void edit_costs(Repair *repair){
    printf("1. Edytuj koszt czesci\n");
    printf("2. Edytuj koszt pracy\n");
    printf("0. Powrot\n");
    int choice;
    scanf("%d", &choice);
    getchar();
    switch(choice){
        case 1:
            printf("Podaj koszt czesci: ");
            scanf("%f", &repair->parts_cost);
            getchar();
            break;
        case 2:
            printf("Podaj koszt pracy: ");
            scanf("%f", &repair->work_cost);
            getchar();
            break;
        case 0:
            break;
        default:
            printf("Nie ma takiej opcji\n");
            break;
    }
}

void edit_times(Repair *repair){
    printf("UWAGA - Czasy sa podawane w formacie timestamp\n");
    printf("1. Edytuj czas dodania\n");
    printf("2. Edytuj czas rozpoczecia\n");
    printf("3. Edytuj czas zakonczenia\n");
    printf("0. Powrot\n");
    int choice;
    scanf("%d", &choice);
    getchar();
    switch(choice){
        case 1:
            printf("Podaj czas dodania: ");
            scanf("%ld", &repair->added_time);
            getchar();
            break;
        case 2:
            printf("Podaj czas rozpoczecia: ");
            scanf("%ld", &repair->start_time);
            getchar();
            break;
        case 3:
            printf("Podaj czas zakonczenia: ");
            scanf("%ld", &repair->end_time);
            getchar();
            break;
        case 0:
            break;
        default:
            printf("Nie ma takiej opcji\n");
            break;
    }
}

void edit_statuses(Repair *repair){
    printf("1. Oznacz jako rozpoczeta\n");
    printf("2. Oznacz jako nie rozpoczeta\n");
    printf("3. Oznacz jako zakonczona\n");
    printf("4. Oznacz jako nie zakonczona\n");
    printf("5. Oznacz jako zaplacona\n");
    printf("6. Oznacz jako nie zaplacona\n");
    printf("0. Powrot\n");
    int choice;
    scanf("%d", &choice);
    getchar();
    switch(choice){
        case 1:
            repair->is_started = 1;
            repair->start_time = time(NULL);
            break;
        case 2:
            repair->is_started = 0;
            repair->start_time = 0;
            break;
        case 3:
            repair->is_done = 1;
            repair->end_time = time(NULL);
            break;
        case 4:
            repair->is_done = 0;
            repair->end_time = 0;
            break;
        case 5:
            repair->is_paid = 1;
            break;
        case 6:
            repair->is_paid = 0;
            break;
        case 0:
            break;
        default:
            printf("Nie ma takiej opcji\n");
            break;
    }
}

void print_repairs(){
    print_queue(repairs_manager, print_repair);
}

void search_repair(){
    MultiSearchResult *multi_search_result = NULL;
    int choice, id;
    char *title = malloc(MAX_STRING_LENGTH);
    do {
        printf("1. Szukaj po ID\n");
        printf("2. Szukaj po ID Pojazdu\n");
        printf("3. Szukaj po ID Warsztatu\n");
        printf("4. Szukaj po Nazwie\n");
        printf("0. Powrot\n");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                printf("Podaj ID: ");
                scanf("%d", &id);
                getchar();
                multi_search_result = multi_search_queue(repairs_manager, &id, search_repair_by_id);
                break;
            case 2:
                printf("Podaj ID Pojazdu: ");
                scanf("%d", &id);
                getchar();
                multi_search_result = multi_search_queue(repairs_manager, &id, search_repair_by_car_id);
                break;
            case 3:
                printf("Podaj ID Warsztatu: ");
                scanf("%d", &id);
                getchar();
                multi_search_result = multi_search_queue(repairs_manager, &id, search_repair_by_workplace_id);
                break;
            case 4:
                printf("Podaj nazwe: ");
                strcpy(title, get_string_from_console());
                multi_search_result = multi_search_queue(repairs_manager, title,
                                                         search_repair_by_title);
                break;
            case 0:
                return;
            default:
                printf("Nie ma takiej opcji\n");
                break;
        }
    } while (choice != 0 && multi_search_result == NULL);
    print_queue(multi_search_result->queue_manager, print_repair);
}