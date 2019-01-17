#include "connect4.h"

int legal(char** board, int col) {
  if (board[col][0] == '-')
    return 1;
  return 0;
}

int insert(char** board, int col, char piece) {
  if (legal(board, col)) {
    int r = 0;
    while(board[col][r+1] == '-' && r < 5) {
      r++;
    }
    board[col][r] = piece;
    return checkWin(board, col, r);
  }
  return 0;
}

int checkWin(char** board) {
  for (int r = 0; r<6; r++) {
    for (int c = 0; c<7; c++) {
      if (r>=3 && c<=3) {
      	if (board[c][r] == board[c+1][r-1] &&
      	    board[c][r] == board[c+2][r-2] &&
      	    board[c][r] == board[c+3][r-3] &&
      	    board[c][r] != '-')
      	  return 1;
      }
      if (r>=3 && c>=3) {
      	if (board[c][r] == board[c-1][r-1] &&
      	    board[c][r] == board[c-2][r-2] &&
      	    board[c][r] == board[c-3][r-3] &&
      	    board[c][r] != '-')
      	  return 1;
      }
      if (c<=3) {
	if (board[c][r] == board[c+1][r] &&
      	    board[c][r] == board[c+2][r] &&
      	    board[c][r] == board[c+3][r] &&
      	    board[c][r] != '-')
      	  return 1;
      }
      if (r<=2) {
	if (board[c][r] == board[c][r+1] &&
      	    board[c][r] == board[c][r+2] &&
      	    board[c][r] == board[c][r+3] &&
      	    board[c][r] != '-')
      	  return 1;
      }
    }
  }
  return 0;
}

/*
int checkWin(char** board, int col, int row) {
  int i = 0;
  for (i=col-3; i>=0 && i<=3; i++) {
    if (board[i][row] == board[i+1][row] &&
      	board[i][row] == board[i+2][row] &&
      	board[i][row] == board[i+3][row] &&
      	board[i][row] != '-')
      return 1;
  }
  for (i=col+3; i>=3 && i<=6; i++) {
    if (board[i][row] == board[i-1][row] &&
	      board[i][row] == board[i-2][row] &&
	      board[i][row] == board[i-3][row] &&
	      board[i][row] != '-')
      return 1;
  }
  for (i=row+3; i>=3 && i<=5; i++) {
    if (board[col][i] == board[col][i-1] &&
	      board[col][i] == board[col][i-2] &&
	      board[col][i] == board[col][i-3] &&
	      board[col][i] != '-')
      return 1;
  }
  for (i=row-3; i>=0 && i<=2; i++) {
    if (board[col][i] == board[col][i+1] &&
	      board[col][i] == board[col][i+2] &&
	      board[col][i] == board[col][i+3] &&
        board[col][i] != '-')
      return 1;
  }
  return checkWin2(board);
}

void printboard(char** board) {
  for (int i = 1; i <=7; i++) {
    printf("%d ", i);
  }
  printf("\n");
  for (int r = 0; r<6; r++) {
    for (int c = 0; c<7; c++) {
      printf("%c ",board[c][r]);
    }
    printf("\n");
  }
}


int main() {
  char* board[7];
  for (int i = 0; i<7; i++) {
    board[i] = malloc(6);
  }
  int r, c;
  for (r = 0; r<6; r++) {
    for (c = 0; c<7; c++) {
      board[c][r] = '-';
    }
  }
  printboard(board);
  int counter = 0;
  int i;
  while(1) {
    if(win == 1) {
      printf("WINNER\n");
      exit(0);
    }
    char input[256];
    printf("Which column? (1-7): ");
    fgets(input, 256, stdin);
    input[strlen(input)-1] = 0;
    i = atoi(input) - 1;
    if (counter%2) {
      insert(board,i,'x');
    }
    else {
      insert(board,i,'o');
    }
    counter++;
    printboard(board);
  }
}
*/
