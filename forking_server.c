#include "networking.h"
#include "connect4.h"

void process(char *s);
void subserver(int from_client);

static void sighandler(int signo){
if(signo == SIGINT){
  printf("\nGOODBYE, THANKS FOR PLAYING!\n");
  exit(0);
}
 else if(signo == SIGUSR1){
  printf("\nGOODBYE, THANKS FOR PLAYING!\n");
  exit(0);
}
}

int main() {
  signal(SIGINT,sighandler);
  signal(SIGUSR1,sighandler);
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
  int i,e;
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
  printf("waiting for player... \n\n");
  while (read(client_socket, input, sizeof(input))) {

    i = atoi(input) - 1;
    e = insert(board,i,'o');
    printboard(board);
    if(e == 2){
      printf("IT'S A DRAW!\n");
      printf("enter control + c to exit\n");
      printf("If you want to play again , wait for the player to reconnnect\n\n");
      exit(0);
    }
    if(e){
      printf("PLAYER WINS! better luck next time~\n");
      printf("enter control + c to exit\n");
      printf("If you want to play again , wait for the player to reconnnect\n\n");
      exit(0);
    }

	  printf("\nenter slot(1-7): ");
	  fgets(input, 256, stdin);
	  input[strlen(input)-1] = 0;

    write(client_socket, input, sizeof(input));
	  i = atoi(input) - 1;
    e = insert(board,i,'x');
    printboard(board);
    if(e == 2){
      printf("IT'S A DRAW!\n");
      printf("enter control + c to exit\n");
      printf("If you want to play again , wait for the player to reconnnect\n\n");
        exit(0);
    }
    if(e){
      printf("HOST WINS! congrats~\n");
      printf("enter control + c to exit\n");
      printf("If you want to play again , wait for the player to reconnnect\n\n");
      exit(0);
    }
    printf("waiting for player... \n\n");
  }//end read loop
  close(client_socket);
  exit(0);
}
