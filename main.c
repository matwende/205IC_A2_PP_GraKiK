#include <stdio.h>

void generateBoard(char board[3][3]);

void drawBoard(char board[3][3]);

void drawDemo();

char setOorX(char board[3][3], char player);

int checkForWin(char board[3][3], char player);


int main() {
    char plansza[3][3];
    char playerX = 'X', playerO = 'O';
    drawDemo();
    generateBoard(plansza);
    drawBoard(plansza);
    for (int i = 0; i < 9; i++) {
        if (i % 2 == 0) {
            setOorX(plansza, playerO);
            if (checkForWin(plansza, playerO) == 1) {
                printf("Gracz %c wygrywa!\n", playerO);
                drawBoard(plansza);
                return 0;
            }
        } else {
            setOorX(plansza, playerX);
            if (checkForWin(plansza, playerX) == 1) {
                printf("Gracz %c wygrywa!\n", playerX);
                drawBoard(plansza);
                return 0;
            }
        }
        drawBoard(plansza);
    }
}

void generateBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void drawBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 2) {
                printf("%c\n", board[i][j]);
            } else {
                printf("%c | ", board[i][j]);
            }
        }
    }
}

void drawDemo() {
    printf("Wybierz pole wedlug wzoru: ");
    printf("\n 1 | 2 | 3 \n 4 | 5 | 6 \n 7 | 8 | 9 \n");
}

char setOorX(char board[3][3], char player) {
    int wybor;
    printf("\nGracz %c - Gdzie umiescic znak? \n", player);
     scanf("%i", &wybor);
    if (wybor < 4) {
        if (board[0][(wybor - 1) % 3] == ' ') {
            board[0][(wybor - 1) % 3] = player;
        } else {
            printf("To miejsce jest juz zajete. Wybierz inne: \n");
            setOorX(board, player);
        }
    }
    if (wybor > 3 && wybor < 7) {
        if (board[1][(wybor - 1) % 3] == ' ') {
            board[1][(wybor - 1) % 3] = player;
        } else {
            printf("To miejsce jest juz zajete. Wybierz inne: \n");
            setOorX(board, player);
        }
    }
    if (wybor > 6) {
        if (board[2][(wybor - 1) % 3] == ' ') {
            board[2][(wybor - 1) % 3] = player;
        } else {
            printf("To miejsce jest juz zajete. Wybierz inne: \n");
            setOorX(board, player);
        }
    }
}

int checkForWin(char board[3][3], char player) {
    if (board[0][0] == board[0][1] && board[0][1] == board[0][2] && board[0][0] != ' ')
        return 1;

    else if (board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][0] != ' ')
        return 1;

    else if (board[2][0] == board[2][1] && board[2][1] == board[2][2] && board[2][0] != ' ')
        return 1;

    else if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != ' ')
        return 1;

    else if (board[0][1] == board[1][1] && board[1][1] == board[2][1] && board[0][1] != ' ')
        return 1;

    else if (board[0][2] == board[1][2] && board[1][2] == board[2][2] && board[0][2] != ' ')
        return 1;

    else if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
        return 1;

    else if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
        return 1;
}
