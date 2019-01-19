# Systems_Final
# System Level Programming - Final Project
# Connect-4
### Jason Kim, Angela Li, Kathleen Wong (Period 5)

## Description

This is a recreation of Connect-4 in the terminal. In a 6 by 7 grid, the two players will take turns dropping a piece into a column. The objective is to get 4 of your pieces in a row; This could be horizontally, vertically, or diagonally. We have also taken advantage of sockets so two players can play using IP Addresses.

## How to START

*Instructions for HOST

Type in terminal:
```
$ hostname -I // give your IP address to PLAYER
$ make
$ ./host
```
*Instructions for PLAYER

Type in terminal:
```
$ make
$ ./player [HOST IP ADDRESS]
```

## How to PLAY

1. Enter a number from 1 - 7 to place your coin into a column
2. Wait for opposing player to move
3. Have four of your coins connected horizontally, vertically, or diagonally to WIN
4. Host should press control + c to exit the game
5. Play again !

## BUGS and ISSUES

1. There are some issues involving user-input. If it's valid, it's perfectly fine. However, once a user inputs something illegal or just random gibberish, there is a high chance the program will go wrong.
2. If the player ever quits (control + c), the host should quit as well to ensure correct playing. 
