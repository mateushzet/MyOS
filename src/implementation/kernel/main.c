#include "print.h"
#include <stdint.h>

void kernel_main(){
    print_clear();
    print_set_color(PRINT_COLOR_BLACK, PRINT_COLOR_WHITE);
    print_str(" <- your input\n");
}