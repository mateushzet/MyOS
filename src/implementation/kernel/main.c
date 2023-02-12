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
                '\b',
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
    lastInput = kbd_US[character];
}
void print_input(){
    char str[2] = "";
    str[0] = lastInput;
    print_set_color(PRINT_COLOR_BLACK, PRINT_COLOR_WHITE);
    print_str(str);
}
void print_answear(){
    print_str("\n");
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    char str[15] = "user input = ";
    str[13] = lastInput;
    print_str(str);
    print_set_color(PRINT_COLOR_BLACK, PRINT_COLOR_WHITE);
    print_str("\n ");
    backspace();
}


void kernel_main() {
    print_clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("Welcome to MyOS!\n\nMENU:\n1) files\n2) command list\n3) text editor\n4) terminal \n5) users \n6) games\n");
    print_prompt();
    input();
    print_answear();
    while(1){
        input();
        print_input();
    }

}

void answer() {
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    char str[14] = "user input =  ";
    str[13] = lastInput;
    print_str(str);
    print_str("\n");
}

void print_prompt() {
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("\n");
    print_str("PRESS A KEY: ");
}

void clear(){
print_clear();
}