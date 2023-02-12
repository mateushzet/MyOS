#include "print.h"
#include <stdint.h>
extern void input();
extern void open();
char lastInput;

char* scan_code_map [128] =
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
    lastInput = scan_code_map[character];
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

void print_prompt() {
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("\n");
    print_str("PRESS A KEY: ");
}

void answer() {
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    char str[14] = "user input =  ";
    str[13] = lastInput;
    print_str(str);
    print_str("\n");
}

void clear(){
print_clear();
}

void kernel_main() {
    print_menu();
}

void ttt(){
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);

    char arr[3][5] = {
    {' ', '|', ' ', '|', ' ',},
    {' ', '|', ' ', '|', ' ',},
    {' ', '|', ' ', '|', ' ',}};
    int turn = 0;
    int y_of_x = 1;
    int x_of_x = 2;
    int counter = 0;
    char letter_under_x;
    char txt[2] = " ";
    txt[1] = '\0';
    int notfinished = 1;
    while(notfinished){
        clear();
        letter_under_x = arr[y_of_x][x_of_x];


        for (int i = 0; i < 5; ++i) {

            txt[0] = arr[0][i];
            if (y_of_x == 0 && x_of_x == i) {
                print_set_color(PRINT_COLOR_RED, PRINT_COLOR_BLACK);
                if (arr[0][i] == ' ') {
                    txt[0] = '#';
                }
            }
            print_str(txt);
            if (y_of_x == 0 && x_of_x == i) {
                print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
            }
        }
        print_str("\n-----\n");
        for (int i = 0; i < 5; ++i) {
            txt[0] = arr[1][i];
            if (y_of_x == 1 && x_of_x == i) {
                print_set_color(PRINT_COLOR_RED, PRINT_COLOR_BLACK);
                if (arr[1][i] == ' ') {
                    txt[0] = '#';
                }
            }
            print_str(txt);
            if (y_of_x == 1 && x_of_x == i) {
                print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
            }
        }
        print_str("\n-----\n");
        for (int i = 0; i < 5; ++i) {

            txt[0] = arr[2][i];
            if (y_of_x == 2 && x_of_x == i) {
                print_set_color(PRINT_COLOR_RED, PRINT_COLOR_BLACK);
                if (arr[2][i] == ' ') {
                    txt[0] = '#';
                }
            }
            print_str(txt);
            if (y_of_x == 2 && x_of_x == i) {
                print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
            }
        }
        arr[y_of_x][x_of_x] = letter_under_x;
        print_str("\n\nuse wasd to navigate\n");
        print_str("press enter to set\n");
        if(counter == 9){
            notfinished = 0;
        }

        if(notfinished){
        input();
        switch (lastInput) {
            case 'A':
                if (x_of_x > 0) {
                    x_of_x -= 2;
                }
                break;
            case 'D':
                if (x_of_x < 5) {
                    x_of_x += 2;
                }
                break;
            case 'S':
                if (y_of_x < 2) {
                    y_of_x++;
                }
                break;
            case 'W':
                if (y_of_x > 0) {
                    y_of_x--;
                }
                break;
            case ' ':
                if (arr[y_of_x][x_of_x] == ' ') {
                    if (turn == 0) {
                        arr[y_of_x][x_of_x] = 'X';
                        counter++;
                        turn = 1;
                    } else {
                        arr[y_of_x][x_of_x] = 'O';
                        turn = 0;
                        counter++;
                    }

                }
                break;
            default:
                print_str("Invalid choice.\n");
                break;
        }}



    }
    print_str("GAME OVER\n");
}

void games(){
    print_str("You have selected Games.\n");
    print_str("\nGAMES:\n1) tik tak toe\n2) exit\n");
    input();
    print_answear();
    print_set_color(PRINT_COLOR_RED, PRINT_COLOR_BLACK);
    switch (lastInput) {
        case '1':
            print_str("tik tak toe\n");
            ttt();
            break;
        case '2':
            print_str("You have selected Command exit.\n");
            break;
        default:
            print_str("Invalid choice.\n");
            break;
    }
}

void print_menu() {
    print_set_color(PRINT_COLOR_GREEN, PRINT_COLOR_BLACK);
    print_clear();
    print_str("Welcome to MyOS!\n\n");
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("\nMENU:\n1) files\n2) command list\n3) text editor\n4) terminal \n5) users \n6) games\n");
    print_prompt();
    input();
    print_answear();
    while(1){
        print_set_color(PRINT_COLOR_RED, PRINT_COLOR_BLACK);
    switch (lastInput) {
        case '1':
            print_str("You have selected Files.\n");
            break;
        case '2':
            print_str("You have selected Command list.\n");
            break;
        case '3':
            print_str("You have selected Text editor.\n");
            break;
        case '4':
            print_str("You have selected Terminal.\n");
            break;
        case '5':
            print_str("You have selected Users.\n");
            break;
        case '6':
            games();
            break;
        default:
            print_str("Invalid choice.\n");
            break;
    }
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("\nMENU:\n1) files\n2) command list\n3) text editor\n4) terminal \n5) users \n6) games\n");
    input();
    print_answear();
}
}