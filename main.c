#include <stdio.h>
#include "interface/interface.h"

int main() {
    int choice;
    do{
        printf("Witaj w programie do zarzadzania warsztatem!\nWybierz jedna z opcji:\n");
        printf("1 - Tryb testowy, program wczyta przygotowane pliki i nie bedzie mozna ich nadpisac\n");
        printf("9 - Tryb normalny, program wczyta ostatnie zapisane dane\n");
        printf("0 - Wyjscie\n");
        printf("Wybor: ");
        choice = get_int_from_console();
        switch (choice) {
            case 1:
                init_interface(1);
                main_menu();
                break;
            case 9:
                init_interface(0);
                main_menu();
                break;
            case 0:
                return 0;
            default:
                printf("Nie ma takiej opcji\n");
                break;
        }
    }while (choice != 0);
}
