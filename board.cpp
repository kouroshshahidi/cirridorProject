#include <stdio.h>
#include <wchar.h>
int placeWall(int board[][50] , int wallx ,int wally , char rotation){
    if(rotation == 'H'){
        for (int i = 0; i < 5; ++i) {
            board[2*wallx + 2][2*wally + i] = 1;
        }
    }
    if(rotation == 'V'){
        for (int i = 0; i < 5; ++i) {
            board[2*wallx + i][2*wally +2] = 1;
        }
    }


    return 0;
}
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
    printf("dimention of board:");
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
    printf("position of p1?");
    scanf("%d %d", &player1[0], &player1[1]);
    printf("position of p2?");
    scanf("%d %d", &player2[0], &player2[1]);
    board[player1[0] * 2 + 1][player1[1] * 2 + 1] = 3;
    board[player2[0] * 2 + 1][player2[1] * 2 + 1] = 4;

//place walls
int p1wall , p2wall;
    printf("how many wall does p1 want to place?");
    scanf("%d" , &p1wall);
    for (int i = 0; i < p1wall; ++i) {
        int wallx , wally;
        char rotation;
        printf("where do you want your wall?");
        scanf("%d %d %c", &wallx , &wally , &rotation);
        placeWall(board ,wallx,wally,rotation);
    }

    printf("how many wall does p2 want to place?");
    scanf("%d" , &p2wall);
    for (int i = 0; i < p2wall; ++i) {
        int wallx , wally;
        char rotation;
        printf("where do you want your wall?");
        scanf("%d %d %c", &wallx , &wally , &rotation);
        placeWall(board ,wallx,wally,rotation);
    }
//test print board

intprintBoard(board, 2 * n + 1);


//print board

//printBoard(board, 2 * n + 1);

    return 0;
}