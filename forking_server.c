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
  char buffer[BUFFER_SIZE];
	char buffer1[BUFFER_SIZE];
	
  while (read(client_socket, buffer1, sizeof(buffer1))) {
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
		  printf("enter slot(1-7): ");
		  fgets(input, 256, stdin);
		  input[strlen(input)-1] = 0;
			buffer = input;
		  i = atoi(input) - 1;
		  if (counter%2) 
		    insert(board,i,'x');
		  else 
		    insert(board,i,'o');
		  counter++;
		  printboard(board);
		}
    printf("[player 2] received: %s\n\n", buffer1);
    write(client_socket, buffer, sizeof(buffer));
  }//end read loop
  close(client_socket);
  exit(0);
}

