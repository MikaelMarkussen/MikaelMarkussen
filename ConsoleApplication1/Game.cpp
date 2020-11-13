#include "Battleships.h"
#include "Comp3.h"



void makeEmptyBoard() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			board[i][j] = BLANK;
		}
	}

}
int randomRow() {
	return std::rand() % 6;
}
int randomColumn() {
	return std::rand() % 6;
}

void writeLetters() {
	std::vector<char> Letters{ 'A','B','C','D','E','F' };//Not sure why I did it this way
	char letters[6];
	for (int i = 0; i < 6; i++) {
		letters[i] = Letters[i];
		std::cout << std::setw(2) << "|" << letters[i] << "|";
	}

}
void makeBoard(int numberOfShips) {
	int count=0; 
	while (count != 11){
		int row = randomRow();
		int column = randomColumn();
		if (board[row][column] != SHIP) {
			board[row][column] = SHIP;
			count++;
		}
	}	
}
void printBoard() {
	std::cout << "-------Battleships-------";
	int k = 6;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (j % 6 == 0) {
				std::cout << "\n" << k;

			}
			board[i][j];
			std::cout << std::setw(2) << "|" << board[i][j] << "|";

		}
		k--;

	}
	std::cout << "\n ";
	writeLetters();
}
void shoot() {
	std::cout << "\nWhat cell do you want to shoot?\n First enter column(Vertical)(A-F)\n then enter Row(Horizontal)(1-6): ";
	std::cin >> column >> row;
	lowerColumn =std::tolower(column);

	switch (lowerColumn)
	{
	case 'a':
		columnNum = 0;
		break;
	case 'b':
		columnNum = 1;
		break;
	case 'c':
		columnNum = 2;
		break;
	case 'd':
		columnNum = 3;
		break;
	case 'e':
		columnNum = 4;
		break;
	case 'f':
		columnNum = 5;
		break;
	default:
		std::cout << "\nWrong letter\n";
		break;
	}
	switch (board[row][columnNum])
	{
	case SHIP:
		board[row][columnNum] = HIT;
		numberOfHits++;
		numberOfShots--;
		break;
	case BLANK:
		board[row][columnNum] = MISS;
		numberOfShots--;
		break;
	case HIT:
		numberOfShots--;
		break;
	}
}
void play() {
	numberOfHits = 0;
	numberOfShots = 13;
		switch (numberOfShots)
		{
		case 0:
			if (numberOfHits < 11) {
				std::cout << "You lost.";
			}
			else if (numberOfHits == 11) {
				std::cout << "You Won";
			}
			break;
		default:
			break;
		}
		switch (numberOfHits)
		{
		case 11:
			std::cout << "You won";
			break;
		}

}
int gameMain() {
	char answer;
	int win = checkForWin();
	makeEmptyBoard();
	makeBoard(1);
	do{
		printBoard();
		shoot();
		checkForWin();

	} while (win==0);
	std::cout << "\ndo you want to play again?(Y/N) ";
	std::cin >> answer;
	char lowerAnswer = std::tolower(answer);
	switch (answer)
	{
	case 'y':
		gameMain();
		break;
	case 'n':
		//main();
		break;
	}
}
int checkForWin() {
	int count=0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (board[i][j] == HIT) {
				count++;
				if (count == 11) {
					return 1;
				}
				else {
					return 0;
				}
			}
		
		}
	}
}