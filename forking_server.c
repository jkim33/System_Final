#include "networking.h"
#include "connect4.h"

void process(char *s);
void subserver(int from_client);

int main() {

  int listen_socket;
  int f;
  listen_socket = server_setup();

  while (1) {

    int client_socket = server_connect(listen_socket);
    f = fork();
    if (f == 0)
      subserver(client_socket);
    else
      close(client_socket);
  }
}

void subserver(int client_socket) {
  char input[BUFFER_SIZE];
	int win = 0;
  int i;
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

  while (read(client_socket, input, sizeof(input))) {
    i = atoi(input) - 1;
    insert(board,i,'o');
		printboard(board);

	  if(win == 1) {
	    printf("WINNER\n");
	    exit(0);
	  }

	  printf("enter slot(1-7): ");
	  fgets(input, 256, stdin);
	  input[strlen(input)-1] = 0;

    write(client_socket, input, sizeof(input));
	  i = atoi(input) - 1;
	  insert(board,i,'x');
	  printboard(board);

    printf("[player 2] received: %s\n\n", input);
  }//end read loop
  close(client_socket);
  exit(0);
}
