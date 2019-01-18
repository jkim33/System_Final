#include "networking.h"
#include "connect4.h"

int main(int argc, char **argv) {

  int server_socket;
  int i,e;
  char input[BUFFER_SIZE];
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

  if (argc == 2)
    server_socket = client_setup( argv[1]);
  else
    server_socket = client_setup( TEST_IP );

  printf("WELCOME TO CONNECT 4\n\n");
  printboard(board);
  while (1) {
    printf("\nenter slot(1-7): ");
    fgets(input, 256, stdin);
    input[strlen(input)-1] = 0;
    write(server_socket, input, sizeof(input));
    i = atoi(input) - 1;
    e = insert(board,i,'o');
    if(e == 2){
      printf("IT'S A DRAW!\n");
      //printf("enter control + c to exit\n");
      //printf("If you want to play again , wait for the player to reconnnect\n\n");
      exit(0);
    }
    printboard(board);
    if(e){
      printf("PLAYER WINS! CONGRATS~\n");
      exit(0);
    }
    printf("waiting for host... \n\n");

    read(server_socket, input, sizeof(input));
    i = atoi(input) - 1;
    e = insert(board,i,'x');
    printboard(board);
    if(e == 2){
      printf("IT'S A DRAW!\n");
      //printf("enter control + c to exit\n");
      //printf("If you want to play again , wait for the player to reconnnect\n\n");
      exit(0);
    }
    if(e){
      printf("HOST WINS! better luck next time~\n");
      exit(0);
    }
  }
}
