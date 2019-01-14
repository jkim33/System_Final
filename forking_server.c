#include "networking.h"

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
	char board[100] = "1 2 3 4 5 6 7\n_ _ _ _ _ _ _\n_ _ _ _ _ _ _\n_ _ _ _ _ _ _\n_ _ _ _ _ _ _\n_ _ _ _ _ _ _\n_ _ _ _ _ _ _\n";

  while (read(client_socket, buffer1, sizeof(buffer1))) {
		printf("%s\n", board);

		printf("enter slot(1-7): ");
    fgets(buffer, sizeof(buffer), stdin);
    printf("[player 2] received: %s\n\n", buffer1);
    write(client_socket, buffer, sizeof(buffer));
  }//end read loop
  close(client_socket);
  exit(0);
}

