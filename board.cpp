#include <stdio.h>
#include <wchar.h>

int intprintBoard(int arr[][50], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int printBoard(int arr[][50], int n) {
    int sw = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr[i][j] == 1 && j % 2 == 0) printf("%c%c%c", 124, 254, 124);
            else if (arr[i][j] == 0 && j % 2 == 0) printf("%c %c", 124, 124);
            else if (arr[i][j] == 1 && (j == 0 || j == n - 1))printf("%c%c%c", 124, 254, 124);
            else if (arr[i][j] == 1 && (i == 0 || i == n - 1) && sw % 2 == 0)printf("-----|");
            else if (arr[i][j] == 0 && j % 2 == 1) printf("%c%c%c%c%c", 196, 196, 196, 196, 196);
            else if (arr[i][j] == 2) printf("     ");
            else if (arr[i][j] == 3) wprintf(L"  %c  ", 0x2606);
            else if (arr[i][j] == 4) wprintf(L"  %c  ", 0x2604);
            sw++;
        }
        printf("\n");
    }

    return 0;
}

int main(void) {
    //makes n by n board and makes it look good
    int n;
    scanf("%d", &n);
    int board[50][50] = {{0}}; // board[2n +1][2n+1]
    for (int i = 0; i < 2 * n + 1; ++i) {
        for (int j = 0; j < 2 * n + 1; ++j) {
            if (i == 0 || i == 2 * n || j == 0 || j == 2 * n) { board[i][j] = 1; }
            if (i % 2 == 0 || j % 2 == 0) {

            } else {
                board[i][j] = 2;
            }
        }
    }

//places players in position
    int player1[2], player2[2];
    scanf("%d %d", &player1[0], &player1[1]);
    scanf("%d %d", &player2[0], &player2[1]);
    board[player1[0] * 2 + 1][player1[1] * 2 + 1] = 3;
    board[player2[0] * 2 + 1][player2[1] * 2 + 1] = 4;
    board[3][2] = 1;

//sdfsdfdsf

    printBoard(board, 2 * n + 1);
    return 0;
}