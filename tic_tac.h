#ifndef TIC_TAC_H_INCLUDED
#define TIC_TAC_H_INCLUDED

char board[3][3];


void print_board();
void reset_board();
int check_free_space();
void player_move(char player1 , char player2);
void playerVsComputer_move(char player);
void computer_move(char computer);
char check_winner();


#endif // TIC_TAC_H_INCLUDED
