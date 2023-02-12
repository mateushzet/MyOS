#include "print.h"
#include <stdint.h>

void user_input(uint64_t ascii){
    char* kbd_US [128] =
            {
            '1',
            '2',
            '3',
            '4',
            '5',
            '6',
            '7',
            '8',
            '9',
            '0',
            '-',
            '=',
            ' ',
            ' ',
            'Q',
            'W',
            'E',
            'R',
            'T',
            'Y',
            'U',
            'I',
            'O',
            'P',
            '[',
            ']',
            '\n',
            ' ',
            'A',
            'S',
            'D',
            'F',
            'G',
            'H',
            'J',
            'K',
            'L',
            ';',
            ' ',
            '`',
            ' ',
            ' ',
            'Z',
            'X',
            'C',
            'V',
            'B',
            'N',
            'M',
            ',',
            '.',
            '/',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            '-',
            ' ',
            ' ',
            ' ',
            '+',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            ' ',
            };
    uint8_t character = (uint8_t) ascii;
    char str[2] = "";
    if((character-2) == 12){
        backspace();
    }else{
    str[0] = kbd_US[character-2];
    print_set_color(PRINT_COLOR_BLACK, PRINT_COLOR_WHITE);
    print_str(str);
    }
}

void kernel_main() {
    print_clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("Welcome to MyOS!");
}

void clear(){
print_clear();
}