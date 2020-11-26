#ifndef MAP_H
#define MAP_H

#include "Array2D.h"
#include <iomanip>

class Board {
	/*
	A map is a type of board 
	It is a 2d char array. Grouped in characters of 2. 
	00 01 02 03 04 ... N
	*/
private:
	int PlayerPos_x, PlayerPos_y;
	char PlayerIcon;
	std::string PlayerColor;
	
	bool gridlines;
	bool board_wrapping;
	bool printcurplyrpos; //print current player position ?

	int cellheight, cellwidth;
	Array2D<char>* map;
public:
	Board(int = 5, int = 5, int = 3, int = 5, std::string = YELLOW); //row col, rowspacing, colspacing
	~Board();

	void BasicPrint() { map->Print(); } //uses the print from Array2D, no formatting or razzle dazzels

	void PrintBoard(int = 0); //rightshift quantity

	char* operator[](const int);

	void MoveE();
	void MoveN();
	void MoveW();
	void MoveS();
	void MoveNE();
	void MoveNW();
	void MoveSE();
	void MoveSW();
	void ModifyXY(int = 0, int = 0);

	void RunMapApp();


};
#endif // !MAP_

