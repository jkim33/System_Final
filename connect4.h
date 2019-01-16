#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>

#ifndef CONNECT4_H
#define CONNECT4_H

int legal(char** board, int col) ;
void insert(char** board, int col, char piece);
void checkWin2(char** board);
void checkWin(char** board, int col, int row);
void printboard(char** board) ;

#endif