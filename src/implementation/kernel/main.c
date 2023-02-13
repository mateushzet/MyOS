#include "print.h"
#include <stdint.h>
extern void input();
extern void open();
char lastInput;
char* notes [1840];
int notes_len = 0;
int notes_rows = 0;
int backspace_flag = 0;
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
    if(character == 14){
        backspace_flag = 1;
    }
}
void print_input(){
    char str[2] = "";
    str[0] = lastInput;
    print_set_color(PRINT_COLOR_BLACK, PRINT_COLOR_WHITE);
    print_str(str);
    if(backspace_flag == 1){
        backspace_flag = 0;
    }
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
    char winner[2] = " ";
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

        if(counter == 9){
            notfinished = 0;
        }
        for (int i = 0; i <= 3; ++i) {
            if(arr[i][0] == arr[i][2] && arr[i][2] == arr[i][4] && arr[i][2] != ' ') {
                notfinished = 0;
                winner[0] = arr[i][0];
            }
        }
            for (int i = 0; i <= 4; i+=2) {
            if(arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[1][i] != ' ') {
                notfinished = 0;
                winner[0] = arr[0][i];
            }
        }

        if(arr[0][0] == arr[1][2] && arr[1][2] == arr[2][4] && arr[1][2] != ' ') {
            notfinished = 0;
            winner[0] = arr[0][0];
        }

        if(arr[2][0] == arr[1][2] && arr[1][2] == arr[0][4] && arr[1][2] != ' ') {
            notfinished = 0;
            winner[0] = arr[0][4];
        }



        if(notfinished){
            print_str("\n\nit is ");
            print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
            if(turn == 0 ){
                print_str("X");
            }else{
                print_str("O");
            }
            print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
            print_str(" turn\n");
            print_str("use wasd to navigate\n");
            print_str("press space or special key to set\n");
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
    print_str("\n\nGAME OVER\n");
    if(winner[0] != ' '){
    if(turn == 0){
        print_str("O wins!\n");
    } else{
        print_str("X wins!\n");
    }} else  {
        print_str("draw!\n");
    }
}

void games(){
    print_str("You have selected Games.\n");
    print_str("\nGAMES:\n1) start\n2) exit\n");
    input();
    print_answear();
    print_set_color(PRINT_COLOR_RED, PRINT_COLOR_BLACK);
    switch (lastInput) {
        case '1':
            print_str("start\n");
            ttt(1);
            break;
        case '2':
            print_str("exit\n");
            break;
        default:
            print_str("Invalid choice.\n");
            break;
    }
}

void print_menu() {
    clear();
    print_set_color(PRINT_COLOR_GREEN, PRINT_COLOR_BLACK);
    print_str("Welcome to MyOS!\n\n");
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("\nMENU:\n1) command list\n2) text editor\n3) terminal \n4) tik tak toe\n");
    print_prompt();
    input();
    print_answear();
    while(1){
        print_set_color(PRINT_COLOR_BLACK, PRINT_COLOR_BLACK);
        clear();
        print_set_color(PRINT_COLOR_RED, PRINT_COLOR_BLACK);
    switch (lastInput) {
        case '1':
            print_str("You have selected command list.\n");
            break;
        case '2':
            print_str("TEXT EDITOR (stored only in ram!):\n");
            print_str("press X to exit\n");
            for (int i = 0; i < notes_len; ++i) {
                char temp[2] = " ";
                temp[0] = notes[i];
                print_str(temp);
            }
            while(lastInput != 'X'){
                input();
                if(notes_rows<=21 || backspace_flag == 1 || get_row()<24){
                notes[notes_len]=lastInput;
                if(lastInput == '\n'){
                    notes_rows++;
                }
                notes_len++;
                print_input();
                }
            }
            break;
        case '3':
            print_str("You have selected terminal.\n");
            break;
        case '4':
            games();
            break;
        default:
            print_str("Invalid choice.\n");
            break;
    }
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("\nMENU:\n1) command list\n2) text editor\n3) terminal \n4) tik tak toe\n");
    input();
    print_answear();
}
}
void kernel_main() {
    print_menu();
}