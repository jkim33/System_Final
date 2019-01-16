#include "networking.h"

int main(int argc, char **argv) {

  int server_socket;
  char buffer[BUFFER_SIZE];
  int win = 0;
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
  while (1) {
    printboard(board);
    int i;
    if(win == 1) {
      printf("WINNER\n");
      exit(0);
    }
    char input[256];
    printf("enter slot(1-7): ");
    fgets(input, 256, stdin);
    input[strlen(input)-1] = 0;

    i = atoi(input) - 1;
    insert(board,i,'o');
    write(server_socket, input, sizeof(input));
    read(server_socket, input, sizeof(input));
    i = atoi(input) - 1;
    insert(board,i,'x');
    printboard(board);
    printf("[player 1] received: %s\n", input);
  }
}
