#include "print.h"
#include <stdint.h>
extern void input();
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

void handle_input(uint64_t ascii){
    uint8_t character = (uint8_t) ascii;
    char str[2] = "";
    str[0] = kbd_US[character];
    lastInput = kbd_US[character];
    print_set_color(PRINT_COLOR_BLACK, PRINT_COLOR_WHITE);
    print_str(str);
    print_str("\n ");
    backspace();
}

void kernel_main() {
    print_clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("Welcome to MyOS!\n\nMENU:\n1) files\n2) command list\n3) text editor\n4) terminal \n5) users \n 6) games");
    input();
    char str[14] = "user input =  ";
    str[13] = lastInput;
    print_str(str);
    print_str("\n");
    input();
    str[14] = "user input =  ";
    str[13] = lastInput;
    print_str(str);
    print_str("\n");
    input();
    str[14] = "user input =  ";
    str[13] = lastInput;
    print_str(str);
    print_str("\n");
}

void answer() {
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    char str[14] = "user input =  ";
    str[13] = lastInput;
    print_str(str);
    print_str("\n");
}

void print_user() {
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("\n");
    print_str("USER: ");
}

void clear(){
print_clear();
}