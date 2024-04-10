#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tic_tac.h"

char PLAYER = '$';
char COMPUTER = '$';
char winner = ' ';
char PLAYER1 = '$';
char PLAYER2 = '%';

int main()
{
    int mode_flag;
    char mode;
    printf("\t\t\t\t\t  ----------------------\n");
    printf("\t\t\t\t\t  | Welcome in Tic Tac |\n");
    printf("\t\t\t\t\t  ----------------------\n");
    restart:
    mode_flag = 0;
    winner = ' ';
    printf("Select the mode you want:-\n");
    printf("---------------------------\n\n");
    printf("1)computer mode\n\n");
    printf("2)two players mode\n\n");
    reset_board();
    check_mode_again:
    printf("Choose: ");
    scanf(" %c", &mode);
    printf("\n\t\t____________________________________________________________________________\n\n");
    if(mode == '1')
    {
        printf("\t\t\t\t\t  -----------------\n");
        printf("\t\t\t\t\t  | Computer mode |\n");
        printf("\t\t\t\t\t  -----------------\n");
        while(!mode_flag)
        {
            printf("Player #(X-O): ");
            scanf(" %c", &PLAYER);
            if(PLAYER == 'X' || PLAYER == 'O')
                mode_flag = 1;
            else
            {
                mode_flag = 0;
                printf("Not match\nTry again!\n");
            }

        }

        if(PLAYER == 'X')
            COMPUTER = 'O';
        else
            COMPUTER = 'X';

        printf("\n\nPlayer is %c\n\n",PLAYER);
        printf("Computer is %c\n",COMPUTER);
        printf("\n\t\t____________________________________________________________________________\n\n\n");
        while(winner == ' ' && check_free_space() != 0)
        {
            playerVsComputer_move(PLAYER);
            printf("\t\t\t\t\t  ----- -----\n");
            printf("\t\t\t\t\t  | Player  |\n");
            printf("\t\t\t\t\t  -----------\n\n\n");
            print_board();
            computer_move(COMPUTER);
            printf("\t\t\t\t\t  -------------\n");
            printf("\t\t\t\t\t  | Computer  |\n");
            printf("\t\t\t\t\t  -------------\n\n\n");
            print_board();
            winner = check_winner();
            if(winner == PLAYER)
            {
                printf("\aYou are the winner!\n");
            }
            else if( winner == COMPUTER)
            {
                printf("\aI am the winner!\n");
            }
        }
    }
    else if(mode == '2')
    {
        while(!mode_flag)
        {
            printf("Player1 #(X-O): ");
            scanf(" %c", &PLAYER1);
            if(PLAYER1 == 'X' || PLAYER1 == 'O')
                mode_flag = 1;
            else
            {
                mode_flag = 0;
                printf("Not match\nTry again!\n");
            }
        }
        if(PLAYER1 == 'X')
            PLAYER2 = 'O';
        else
            PLAYER2 = 'X';
        printf("========================\n\n");
        printf("\n# player1 is %c\n\n# player2 is %c\n",PLAYER1, PLAYER2);
        printf("\n=============================================================\n\n");
        while(winner == ' ' && check_free_space() != 0)
        {
            player_move(PLAYER1, PLAYER2);
            print_board();
            winner = check_winner();
            if(winner == PLAYER1)
            {
                printf("\aplayer1 is the winner!\n");
            }
            else if( winner == PLAYER2)
            {
                printf("\aplayer2 is the winner!\n");
            }
        }
        if(winner == ' ')
        {
            printf("Game over!\nDRAW\n");
        }
    }
    else
    {
        printf("Please choose one of the two modes\n");
        goto check_mode_again;
    }

    char var;
    printf("Do you want to restart (Y \\ N)\n");
    check_again:
    scanf(" %c", &var);
    if(var == 'Y')
    {
        goto restart;
    }
    else if(var == 'N')
    {
        printf("Goodbye!\n");
        return 0;
    }
    else
    {
        printf("Not match!\tTry again\n");
        goto check_again;
    }
    return 0;
}
