#include <stdio.h>
#include <stdbool.h>

void first_board();
void show_board();
void who_moves(char player);
bool valid(int row, int col);
bool who_wins(char player);

char board[3][3];

void first_board(){
    int i, j;
    
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            board[i][j] = '.'; 
        }
    }
}

void show_board(){
    int i, j;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            printf(" %c ", board[i][j]);
        }
        printf("\n"); 
    }
}

bool valid(int row, int col){
    if (board[row][col] == '.'){ 
        return true;
    }
    else {
        return false;
    }
}

void who_moves(char player){
    int row = 0, col = 0;
    
    do {
        printf("\n %c, make a move!\n ", player);
        scanf("%d%d", &row, &col);
        
        if(!(valid(row - 1, col - 1))){
            printf("Not a valid move, try again!\n ");
        }
    } while (!(valid(row - 1, col - 1)));
    
    board[row - 1][col - 1] = player; //set position to either O or X
}

bool who_wins(char player){
    int i;
    
    for (i = 0; i < 3; i++){
        if ((board[i][0] == player) && //for horizontal check
            (board[i][1] == player) && 
            (board[i][2] == player)){
            
            return true;
        }
        else if ((board[0][0] == player) && //for diagonal check
                (board[1][1] == player) &&
                (board[2][2] == player)){
                    
            return true;
        }
        else if ((board[0][i] == player) && //for vertical check
                (board[1][i] == player) &&
                (board[2][i] == player)){
                    
            return true;
        }
    }
    
    return false;
}
int main(void){
    char player = 'X';
    bool running = true;
    int move = 0;
    char winning = ' '; 
    
    first_board();
    show_board();
    
    while (running){
        
        if (move % 2 == 0){
            player = 'X';
        }
        else {
            player = 'O';
        }
        
        switch (player){
            case 'X':
                who_moves(player);
            break;
            case 'O':
                who_moves(player);
            break;
        }
        
   if (who_wins(player)){ //check if a player has won the game
            winning= player;
            running = false; //set to false to exit the game
        }
        
        move++;
        
        if (move == 9){
            running = false;
        }
        
        show_board();
    }
    
    if (winning == ' '){ //if win is not set, it's a draw
        printf("It's a draw!");
    }
    else {
        printf("%c won the game!", player); //otherwise, print out who won
    }
  
  return 0;
}
