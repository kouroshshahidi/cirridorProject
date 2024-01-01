#include <stdio.h>
#include <wchar.h>
//data storage
struct player{
    int id;
    char name[20];
    int x ,y;
    int wallNumber;

};

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
void move(int board[][50],player &player , char direction){
    if(direction == 'w'){
        board[2*(player.y) +1][2*(player.x) +1] = 2;
        player.y--;
        if(player.id == 1)
            board[2*(player.y) +1][2*(player.x) +1] = 3;
        else
            board[2*(player.y) +1][2*(player.x) +1] = 4;
    }

    else if(direction == 'a'){
        board[2*(player.y) +1][2*(player.x) +1] = 2;
        player.x--;
        if(player.id == 1)
            board[2*(player.y) +1][2*(player.x) +1] = 3;
        else
            board[2*(player.y) +1][2*(player.x) +1] = 4;
    }

    else if(direction == 'd'){
        board[2*(player.y) +1][2*(player.x) +1] = 2;
        player.x++;
        if(player.id == 1)
            board[2*(player.y) +1][2*(player.x) +1] = 3;
        else
            board[2*(player.y) +1][2*(player.x) +1] = 4;
    }

    else if(direction == 's'){
        board[2*(player.y) +1][2*(player.x) +1] = 2;
        player.y++;
        if(player.id == 1)
        board[2*(player.y) +1][2*(player.x) +1] = 3;
        else
            board[2*(player.y) +1][2*(player.x) +1] = 4;
    }


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

            if (arr[i][j] == 1 && (j == 0 || j == n - 1))printf("%c%c%c", 124, 254, 124);
            else if (arr[i][j] == 1 && (j == 0 || j == n - 1))printf("%c%c%c", 124, 254, 124);
            else if (arr[i][j] == 0 && j % 2 == 0) printf("%c %c", 124, 124);
            else if (arr[i][j] == 1 && j % 2 == 0) printf("|%c|", 254);
            else if (arr[i][j] == 1 && j % 2 == 1) printf("%c%c%c%c%c", 196, 124, 254, 124, 196);
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
    int board[50][50] = {{0}};
    for (int i = 0; i < 2 * n + 1; ++i) {
        for (int j = 0; j < 2 * n + 1; ++j) {
            if (i == 0 || i == 2 * n || j == 0 || j == 2 * n) { board[i][j] = 1; }
            if (i % 2 == 0 || j % 2 == 0) {

            } else {
                board[i][j] = 2;
            }
        }
    }



    //establish parameters
    player p1 , p2;
    p1.id =1 , p2.id = 2;
    p1.x = (n-1)/2 , p1.y = 0 , p2.x = (n-1)/2 , p2.y = n-1;
    printf("give me how many walls each player can place");
    scanf("%d %d" , &p1.wallNumber , &p2.wallNumber);
    printf("p1...what is your name?");
    scanf("%19s" , p1.name);
    printf("p2...what is your name?");
    scanf("%19s" , p2.name);
//places players in position
    board[2*(p1.y) +1][2*(p1.x) +1] = 3;
    board[2*(p2.y) +1][2*(p2.x) +1] = 4;
//move system
while(p2.y != 0 && p1.y != n-1){
    //player 1 does something
    int moveID;
    do{
        printf("what do you wanna do %s?\n 1:move   2:place wall" , p1.name);
        scanf("%d" , &moveID);
        if(moveID == 1)
            break;
    }while(p1.wallNumber == 0);
    if(moveID == 1){
        char dir;
        printf("use WASD to move");
        scanf(" %c" , &dir);
        move(board , p1, dir);
    }else{
        int x , y ;
        char r;
        printf("give me the location and rotation");
        scanf("%d %d %c" , &x , &y , &r);
        placeWall(board,x , y , r);
        p1.wallNumber--;
    }
    printBoard(board, 2 * n + 1);


    //player 2 does something


    do{
        printf("what do you wanna do %s?\n 1:move   2:place wall" , p2.name);
        scanf("%d" , &moveID);
        if(moveID == 1)
            break;
    }while(p2.wallNumber == 0);
    if(moveID == 1){
        char dir;
        printf("use WASD to move");
        scanf(" %c" , &dir);
        move(board,p2, dir);
    }else{
        int x , y ;
        char r;
        printf("give me the location and rotation");
        scanf("%d %d %c" , &x , &y , &r);
        placeWall(board,x , y , r);
        p2.wallNumber--;
    }
    printBoard(board, 2 * n + 1);




}










printBoard(board, 2 * n + 1);

    return 0;
}