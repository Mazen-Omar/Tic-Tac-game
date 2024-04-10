#include "tic_tac.h"

int player_flag;

void print_board()
{
    printf("\t\t\t\t\t %c  | %c  | %c \n",board[0][0], board[0][1], board[0][2]);
    printf("\t\t\t\t\t----|----|----\n");
    printf("\t\t\t\t\t %c  | %c  | %c \n",board[1][0], board[1][1], board[1][2]);
    printf("\t\t\t\t\t----|----|----\n");
    printf("\t\t\t\t\t %c  | %c  | %c \n\n\n",board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

void reset_board()
{
    int i,j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }

}

char check_winner()
{
    int i;
            /** Vertical win **/
    for(i = 0; i < 3; i++)
    {
         if((board[0][i] == board[1][i]) && (board[0][i] == board[2][i]))
        {
            if(board[0][i] != ' ')
                return board[0][i];
        }
    }
                /** Diagonal win **/
    if((board[0][0] == board[1][1]) && (board[0][0] == board[2][2]))
    {
            return board[0][0];
    }
    else if((board[0][2] == board[1][1]) &&(board[0][2] == board[2][0]))
    {
            return board[0][2];
    }
                /** Horizontal win **/
    for(i = 0; i < 3; i++)
    {
        if((board[i][0] == board[i][1]) && (board[i][0] == board[i][2]))
        {
            if(board[i][0] != ' ')
                return board[i][0];
        }
    }
    return ' ';
}

int check_free_space()
{
    int free_spaces = 9;
    int i,j;
    for(i = 0; i < 3; i++)
    {
        for(j = 0; j < 3; j++)
        {
            if(board[i][j] != ' ')
            {
                free_spaces--;
            }
        }
    }
    return free_spaces;
}

void player_move(char player1 , char player2)
{
    int row, column, tic_flag , row_flag , column_flag;
    char tic;
    again:
    if(player_flag == 0)
    {
        printf("\t\t\t\t\t-----------\n");
        printf("\t\t\t\t\t| player1 |\n");
        printf("\t\t\t\t\t-----------\n");
    }
    else
    {
        printf("\t\t\t\t\t-----------\n");
        printf("\t\t\t\t\t| player2 |\n");
        printf("\t\t\t\t\t-----------\n");
    }
    do
    {
        printf("enter row(1-3): ");
        scanf("%d", &row);
        if(row <= 3 && row >= 1)
        {
            row_flag = 1;
        }
        else
        {
            row_flag = 0;
            printf("Not match\nTry again!\n");
        }
    }while(!row_flag);

     do
    {
        printf("enter column(1-3): ");
        scanf("%d", &column);
        if(column <= 3 && column >= 1)
        {
            column_flag = 1;
        }
        else
        {
            column_flag = 0;
            printf("Not match\nTry again!\n");
        }
    }while(!column_flag);

   /* do
    {
        printf("enter (X-O): ");
        scanf(" %c", &tic);
        if(tic == 'X' || tic == 'O')
           {
               tic_flag = 1;
           }
            else
            {
                tic_flag = 0;
                printf("Not match\nTry again!\n");
            }
    }while(!tic_flag); */
    do
    {

        if(player_flag == 0)
        {
            if(board[row-1][column-1] != ' ')
            {
                printf("This is position is taken\t choose another one\n");
                goto again;
            }
            else
            {
                board[row-1][column-1] = player1;
                player_flag = 1;
            }

        }
        else
        {
            if(board[row-1][column-1] != ' ')
            {
                printf("This is position is taken\nchoose another one\n");
                goto again;
            }
            else
            {
                board[row-1][column-1] = player2;
                player_flag = 0;
            }

        }
    }while(board[row-1][column-1] == ' ');
    /*if(board[row-1][column-1] != ' ')
    {
        printf("This position is already filled!\nTry again\n");
        goto again;
    }*/
    //board[row-1][column-1] = tic;
    printf("\n");
}


void computer_move(char computer)
{
    srand(time(0));
    int c_row, c_column;
    if(check_free_space() > 0)
    {
         do {
            c_row = rand() % 3;
            c_column = rand() % 3;
        }while (board[c_row][c_column] != ' ');
        board[c_row][c_column] = computer;
    }
    else
    {
        printf("Game over!\nDRAW\n");
    }

}

void playerVsComputer_move(char player)
{
    int row, column, tic_flag , row_flag , column_flag;
    char tic;
    again:
    do
    {
        printf("enter row(1-3): ");
        scanf("%d", &row);
        if(row <= 3 && row >= 1)
        {
            row_flag = 1;
        }
        else
        {
            row_flag = 0;
            printf("Not match\nTry again!\n");
        }
    }while(!row_flag);

     do
    {
        printf("enter column(1-3): ");
        scanf("%d", &column);
        if(column <= 3 && column >= 1)
        {
            column_flag = 1;
        }
        else
        {
            column_flag = 0;
            printf("Not match\nTry again!\n");
        }
    }while(!column_flag);

    if(board[row-1][column-1] == ' ')
    {
        board[row-1][column-1] = player;
    }
    else
    {
        printf("This position is taken\nTry again!\n\n");
        goto again;
    }
    printf("\n");
}
