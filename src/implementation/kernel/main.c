#include "print.h"
#include <stdint.h>

char lastInput;

char* kbd_US [128] =
        {
                ' ',
                ' ',
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
        };

void single_input(uint64_t ascii){

    uint8_t character = (uint8_t) ascii;
    char str[2] = "";
    str[0] = kbd_US[character];
    lastInput = kbd_US[character];
    print_set_color(PRINT_COLOR_BLACK, PRINT_COLOR_WHITE);
    print_str(str);
    print_str("\n ");
    backspace();
}


void user_input(uint64_t ascii){
    uint8_t character = (uint8_t) ascii;
    char str[2] = "";
    if((character) == 14){
        backspace();
    }else{
    str[0] = kbd_US[character];
    print_set_color(PRINT_COLOR_BLACK, PRINT_COLOR_WHITE);
    print_str(str);
    }
}

void kernel_main() {
    print_clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("Welcome to MyOS!\nMENU:\n1) option1\n2) option2\n3) option3\n");
}

void odpowiedz() {
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    char str[14] = "user input =  ";
    str[13] = lastInput;
    print_str(str);
    print_str("\n");
}

void write_user() {
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("\n");
    print_str("USER: ");
}


void clear(){
print_clear();
}

