#include <stdio.h>
#include <wchar.h>
#include <time.h>
#include <stdlib.h>
//data storage
struct player{
    int id;
    char name[20];
    int x ,y;
    int wallNumber;

};
char directions[4]{'w' , 'a' , 's' , 'd'};
int bot(int movementStage , int n){
    srand (time(NULL));
    if(movementStage == 1)return rand() % 2 + 1;
    if(movementStage == 2)return rand() % 4;
    if(movementStage == 3)return rand() % 4;
    return 0;
}
int checkObstruction(int board[][50] , player player , char direction){
    int currentX =2*(player.x)+1, currentY = 2*(player.y)+1;
    if(direction == 'w'){
        if(board[currentY-1][currentX]== 1 || board[currentY-2][currentX] >2) return 1;
    }
    else if(direction == 's'){
        if(board[currentY +1][currentX]== 1 || board[currentY+2][currentX] >2) return 1;
    }
    else if(direction == 'a'){
        if(board[currentY][currentX-1]== 1 || board[currentY][currentX-2] >2) return 1;
    }
    else if(direction == 'd'){
        if(board[currentY][currentX+1]== 1 || board[currentY][currentX+2] >2) return 1;
    }

    return 0;
}

void makeClone (int n, int board[][50], int clonedBoard[][50]) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            clonedBoard[i][j] = board[i][j];
        }
    }
}

int placeWall(int n ,int board[][50] , int wallx ,int wally , char rotation){

        if (rotation == 'H') {
            if(board[2 * wallx][2 * wally + 2] == 1)return -1;
            if (wallx != 0 && 2*wallx < 2*n + 1 &&  2 * wally + 4 < 2*n +1 && wally >= 0) {
                for (int i = 0; i < 3; ++i) {
                    board[2 * wallx][2 * wally + 1 + i] = 1;
                }
                return 0;
            } else{
                return -1;
            }
        }
        if (rotation == 'V') {
            if(board[2 * wallx + 2][2 * wally] == 1)return -1;
            if (wally != 0 && 2*wally < 2*n + 1 &&  2 * wallx + 4 < 2*n +1 && wallx >= 0) {
                for (int i = 0; i < 3; ++i) {
                    board[2 * wallx +1 + i][2 * wally] = 1;
                }
                return 0;
            } else{
                return -1;
            }
        }

    return -1;
}

int deleteWall(int n ,int board[][50] , int wallx ,int wally , char rotation){

    if (rotation == 'H') {
        if (wallx != 0 && 2*wallx < 2*n + 1 &&  2 * wally + 4 < 2*n +1 && wally >= 0) {
            for (int i = 0; i < 3; ++i) {
                board[2 * wallx][2 * wally + i +1] = 0;
            }
            return 0;
        } else{
            return -1;
        }
    }
    if (rotation == 'V') {
        if (wally != 0 && 2*wally < 2*n + 1 &&  2 * wallx + 4 < 2*n +1 && wallx >= 0) {
            for (int i = 0; i < 3; ++i) {
                board[2 * wallx + 1 +i][2 * wally] = 0;
            }
            return 0;
        } else{
            return -1;
        }
    }

    return -1;
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

int move(int board[][50],player &player , char direction){
    if(direction == 'w' && !checkObstruction(board, player, 'w')){
        board[2*(player.y) +1][2*(player.x) +1] = 2;
        player.y--;
        if(player.id == 1)
            board[2*(player.y) +1][2*(player.x) +1] = 3;
        else
            board[2*(player.y) +1][2*(player.x) +1] = 4;
        return 1;
    }

    else if(direction == 'a' && !checkObstruction(board, player, 'a')){
        board[2*(player.y) +1][2*(player.x) +1] = 2;
        player.x--;
        if(player.id == 1)
            board[2*(player.y) +1][2*(player.x) +1] = 3;
        else
            board[2*(player.y) +1][2*(player.x) +1] = 4;
        return 1;
    }

    else if(direction == 'd' && !checkObstruction(board, player, 'd')){
        board[2*(player.y) +1][2*(player.x) +1] = 2;
        player.x++;
        if(player.id == 1)
            board[2*(player.y) +1][2*(player.x) +1] = 3;
        else
            board[2*(player.y) +1][2*(player.x) +1] = 4;
        return 1;
    }

    else if(direction == 's' && !checkObstruction(board, player, 's')){
        board[2*(player.y) +1][2*(player.x) +1] = 2;
        player.y++;
        if(player.id == 1)
            board[2*(player.y) +1][2*(player.x) +1] = 3;
        else
            board[2*(player.y) +1][2*(player.x) +1] = 4;
        return 1;
    }
    return 0;
}

int cloneMove(int board[][50],player &player , char direction){
    if(direction == 'w' && !checkObstruction(board, player, 'w')){
        player.y--;
        if(player.id == 1)
            board[2*(player.y) +1][2*(player.x) +1] = 3;
        else
            board[2*(player.y) +1][2*(player.x) +1] = 4;
        return 1;
    }

    else if(direction == 'a' && !checkObstruction(board, player, 'a')){
        player.x--;
        if(player.id == 1)
            board[2*(player.y) +1][2*(player.x) +1] = 3;
        else
            board[2*(player.y) +1][2*(player.x) +1] = 4;
        return 1;
    }

    else if(direction == 'd' && !checkObstruction(board, player, 'd')){
        player.x++;
        if(player.id == 1)
            board[2*(player.y) +1][2*(player.x) +1] = 3;
        else
            board[2*(player.y) +1][2*(player.x) +1] = 4;
        return 1;
    }

    else if(direction == 's' && !checkObstruction(board, player, 's')){
        player.y++;
        if(player.id == 1)
            board[2*(player.y) +1][2*(player.x) +1] = 3;
        else
            board[2*(player.y) +1][2*(player.x) +1] = 4;
        return 1;
    }
    return 0;
}

int castraydown(int n ,const int board[][50],int x ,int y){
        while(y != 2*n  && board[y][x] != 1)
            y++;
    if(y == n-1){
        return 1;
    }
    else return 0;
}

int castrayUp(int n ,const int board[][50],int x ,int y){
    while(y != 1  && board[y][x] != 1)
        y--;
    if(y == 1){
        return 1;
    }
    else return 0;
}

int dfs(int n ,int board[][50],player targetPlayer){
    int cloneboard[50][50];
    player clonePlayer;
    clonePlayer = targetPlayer;
    makeClone(n, board, cloneboard);
if((castraydown(n,cloneboard , clonePlayer.x*2+1 , clonePlayer.y*2+1) == 1 && clonePlayer.id == 1)|| (castrayUp(n,cloneboard , clonePlayer.x*2+1 , clonePlayer.y*2+1) == 1 && clonePlayer.id == 2) ){
    return 1;
} else {
    int swW = 0, swA = 0 ,swS =0, swD =0;
    if (checkObstruction(cloneboard, clonePlayer, 'w') != 1) {
        cloneMove(cloneboard, clonePlayer, 'w');
        swW = dfs(n, cloneboard, clonePlayer);
        clonePlayer.y++;
    }
    if (checkObstruction(cloneboard, clonePlayer, 'a') != 1){
        cloneMove(cloneboard, clonePlayer, 'a');
        swA = dfs(n, cloneboard, clonePlayer);
        clonePlayer.x++;
    }
    if (checkObstruction(cloneboard, clonePlayer, 's') != 1){
        cloneMove(cloneboard, clonePlayer, 's');
        swS = dfs(n, cloneboard, clonePlayer);
        clonePlayer.y--;
    }
    if (checkObstruction(cloneboard, clonePlayer, 'd') != 1){
        cloneMove(cloneboard, clonePlayer, 'd');
        swD = dfs(n, cloneboard, clonePlayer);
        clonePlayer.x--;
    }
    if(swW ==1 || swA ==1 || swS ==1 || swD ==1){
        return 1;
    } else return 0;


}
}

int main(void) {
    //makes n by n board and makes it look good
    int n;
    printf("dimention of board:");
    scanf("%d", &n);
    int board[50][50] = {{0}};
    int swBoard[50][50] = {{0}};
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
            printf("what do you wanna do %s?\n 1:move 2:place wall" , p1.name);
            scanf("%d" , &moveID);
            if(moveID == 1)
                break;
        }while(p1.wallNumber == 0);
        if(moveID == 1){
            int sw;
            char dir;
            do {
                printf("use WASD to move");
                scanf(" %c" , &dir);
                sw = move(board,p1, dir);
            } while (!sw);
        }else{
            int x , y , sw = -1 , sw1 = 0;
            char r;
            do {
                sw1 =0;
                printf("give me the location and rotation\n");
                scanf("%d %d %c" , &x , &y , &r);
                sw = placeWall(n,board,x , y , r);
                if(dfs( 2*n +1 , board , p1) == 0 || dfs( 2*n +1 , board , p2) == 0 ){
                    deleteWall(n,board,x , y , r);
                    printf("cannot block someone\n");
                    sw1 = -1;
                }
            } while (sw == -1 || sw1 == -1);
            p1.wallNumber--;
        }
        printBoard(board , 2*n +1);

if(p1.y == n-1) break;
        //player 2 does something


        do{
            printf("what do you wanna do %s?\n 1:move 2:place wall" , p2.name);
            scanf("%d" , &moveID);
            if(moveID == 1)
                break;
        }while(p2.wallNumber == 0);
        if(moveID == 1){
            int sw;
            char dir;
            do {
                printf("use WASD to move");
                scanf(" %c" , &dir);
                sw = move(board,p2, dir);
            } while (!sw);
        }else{
            int x , y ,sw = -1 , sw1 =0;
            char r;
            do {
                sw1 =0;
                printf("give me the location and rotation\n");
                scanf("%d %d %c" , &x , &y , &r);
                sw = placeWall(n,board,x , y , r);
                if(dfs( 2*n +1 , board , p1) == 0 || dfs( 2*n +1 , board , p2) == 0 ){
                    deleteWall(n,board,x , y , r);
                    printf("cannot block someone\n");
                    sw1 = -1;
                }
            } while (sw == -1 || sw1 == -1);
            p2.wallNumber--;
        }
        printBoard(board, 2 * n + 1);

    }
    if(p1.y == n-1)printf("p1 win");
    else printf("p2 win");
    return 0;
}