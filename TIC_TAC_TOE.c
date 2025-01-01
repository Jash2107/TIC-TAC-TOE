#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Globally Declared the Game Board

char Board[3][3];

//Function to initialize the Game Board

void initialize_Board(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            Board[i][j] = ' ';
        }
    }
    int count = 1;
    printf("\n\n\t ");
    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%d" , count++);
            if(j < 2){
                printf(" | ");
            }
        }
        if(i < 2){
            printf("\n\t----------------\n\t ");
        }
    }
    printf("\n\n\n");
}

//Function to show the Game Board

void ShowBoard(){
    printf("\n\n\t  ");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
             if (Board[i][j] == 'X') {
                printf("\033[1;33m"); // Yellow for 'X'
            } else if (Board[i][j] == 'O') {
                printf("\033[1;35m"); // Magenta for 'O'
            } else {
                printf("\033[0m"); // Default for empty cells
            }
            printf("%c" , Board[i][j]);
            if(j < 2){
                printf(" | ");
            }
        }
        if(i < 2){
            printf("\n\t----------------\n\t  ");
        }
    }
     printf("\n\n\n");
}

//Function to Update the Game Board

int UpdateBoard(int cell, char PlayerSign){
    int row = (cell - 1) / 3;
    int col = (cell - 1) % 3;
    int isValid = 1;

    //If cell is Already Filled
    if(Board[row][col] != ' '){
        printf("\033[1;31m");
        printf("\nInvalid: The Cell is already filled.\n");
        isValid = 0;
    }
    else{
        Board[row][col] = PlayerSign;
    }
    ShowBoard();
    return isValid;        
}

//Function to Check the Winner Of the Game.

int Check_Winner(char EQ){
    //Check For ROWS
    if(Board[0][0] == EQ && Board[0][1] == EQ && Board[0][2] == EQ ||
      Board[1][0] == EQ && Board[1][1] == EQ && Board[1][2] == EQ ||
      Board[2][0] == EQ && Board[2][1] == EQ && Board[2][2] == EQ){
        return 1;
      }

    //Check For COLUMNS
    else if (Board[0][0] == EQ && Board[1][0] == EQ && Board[2][0] == EQ ||
           Board[0][1] == EQ && Board[1][1] == EQ && Board[2][1] == EQ ||
           Board[0][2] == EQ && Board[1][2] == EQ && Board[2][2] == EQ){
        return 1;
    }

    //Check For DIAGONALS
    else if (Board[0][0] == EQ && Board[1][1] == EQ && Board[2][2] == EQ ||
           Board[0][2] == EQ && Board[1][1] == EQ && Board[2][0] == EQ)
    {
        return 1;
    }
    //No Winner
    return 0;
}

//TIC TAC TOE Game Starts From Here

void Play_TicTacToe(){
    int Game_result = 0;
    int cell = 0;
    int Play_Count = 0;
    int Result_Update = 1;

    char PlayerSign = ' ';

    //Start Playing the Game
    while(!Game_result && Play_Count <= 9){
        if(Play_Count % 2 == 0){
            //Player 1
            printf("\nPlayer 1 [ X ] : ");
            PlayerSign = 'X';
        }
        else{
            // player 2
            printf("\nPlayer 2 [ O ] : ");
            PlayerSign = 'O';
        }
        scanf("%d" , &cell);
        if(cell > 0 && cell < 10){
            Result_Update = UpdateBoard(cell , PlayerSign);
            if(Result_Update){
                Game_result = Check_Winner(PlayerSign);
                //Print Game Winner
                  if (Game_result){
                     printf("\033[1;32m");
                    printf("\t *** Player %d Won!! ***\n", PlayerSign == 'X' ? 1 : 2);
                }
                Play_Count++;
            }
        }
         else if (cell == -1){
            printf("\033[1;31m");
            printf("\n\tGame Terminated\n");
            return;
        }
        else{
            printf("\033[1;31m");
            printf("\nPlease Enter a valid cell value\n");
        }
    }
    //No Winner
    if(!Game_result && Play_Count == 9){

        printf("\n\t *** Draw...  ***\n");
    }
    printf("\n\t --- Game Over --- \n");
}

//Main Function
int main(){
     printf("--------- Tic Tac Toe ----------\n\n");
 
    printf("\n* Instructions \n\n");
    printf("\tPlayer 1 sign = X\n");
    printf("\tPlayer 2 sign = O");
    printf("\n\tTo exit from game, Enter -1\n");
 
    printf("\n\n* Cell Numbers on Board\n");
    initialize_Board();

    char start = ' ';
    printf("\033[1;34m");
    printf("\n> Press Enter to start...");
 
    scanf("%c", &start);
 
    if (start)
    {
        int Choice = 1;
        // restart the game
        while (Choice)
        {
            Play_TicTacToe();
            printf("\n* Menu\n");
            printf("\nPress 1 to Restart");
            printf("\nPress 0 for Exit");
            printf("\n\nChoice: ");
            scanf("%d", &Choice);
            if (Choice)
            {
                initialize_Board();
            }
            printf("\n");
        }
    }
     printf("\033[1;32m");
    printf("\n :: Thanks for playing Tic Tac Toe game! :: \n");
    return 0;
}