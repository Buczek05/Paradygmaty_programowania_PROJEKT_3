#include <stdio.h>
#include "interface/interface.h"

int main() {
    fopen("data/cars", "w");
    init_interface();
    main_menu();
    return 0;
}
