#pragma once
#include <iostream>
#include <conio.h>//for 
#include <string>//for std::string
#include <vector>// for std::vector
#include <iomanip>//for setw()

void makeBoard(int numberOfShips);
void makeEmptyBoard();
int randomRow();
int randomColumn();
void writeLetters();
int checkForWin();
int gameMain();
const int M = 6, N = 6;
const char BLANK = ' ';
const char SHIP = 'S';
const char MISS = 'M';
const char HIT = 'H';
char board[M][N]; // 2d array with M rows and N columns
int numberOfHits;
int numberOfShots;
int row;
char column;
int columnNum;
char lowerColumn
