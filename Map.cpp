#include "Map.h"
//#include <cctype>
//#include <chrono>
//#include <thread>
//#include <cstdlib>

Board::Board(int row, int col, int cellheight, int cellwidth, std::string PlyrClr) {
	map = new Array2D<char>(row, col, '-');
	PlayerPos_x = PlayerPos_y = 0;

	this->cellheight = cellheight; 
	this->cellheight = cellheight;

	PlayerColor = PlyrClr;
	PlayerIcon = 'P';

	gridlines = true;

	board_wrapping = true;
	
	printcurplyrpos = true;
	
}

Board::~Board() {
	delete map;
	map = NULL;
}

char* Board::operator[](const int i ) {
	return (*map)[i];
}

void Board::PrintBoard(int rightshift) {
	if (printcurplyrpos) {
		int spacing = cellheight;
		if (gridlines)
			spacing++;
		for (int k = 0; k < rightshift; k++)
			std::cout << RIGHT;

		std::cout << "Player Position: (" << PlayerPos_x << ", " << PlayerPos_y << ")" << std::endl;
	}
	//top row gridline
	if (gridlines) {
		for (int k = 0; k < rightshift; k++)
			std::cout << RIGHT;

		for (int j = 0; j < map->getC(); j++) {
			for (int c = 0; c < cellheight; c++)
				std::cout << "-";
			std::cout << "--";
		}
		std::cout << "-";
	}
	std::cout << std::endl;

	for (int i = 0; i < map->getR(); i++) { //for the number of rows
		for (int rspace = 0; rspace < cellheight; rspace++) { //for the extra spacing of the map type, for printing purposes (height per cell)
			//first row contains player's location and Array2D data
			for (int k = 0; k < rightshift; k++)
				std::cout << RIGHT;
			if (rspace == 0) { //height 0 of the current cell
				for (int j = 0; j < map->getC(); j++) {
					if (gridlines)
						std::cout << "| ";
					if(i == PlayerPos_y && j == PlayerPos_x)
						std::cout << PlayerColor << std::setw(cellheight/2) << PlayerIcon << DEFAULT << std::setw(cellheight / 2) << " ";
					else
						std::cout << std::setw(cellheight / 2) << (*map)[i][j] << std::setw(cellheight / 2) << " ";
					
					if(gridlines)
						std::cout << " ";
					else
						std::cout << " ";
					
					if(gridlines)
						if (j == map->getC() - 1)
							std::cout << "|";
				}
				std::cout << std::endl;
			}
			else {
				if (gridlines) {
					std::cout << "|";
					for (int j = 0; j < map->getC(); j++) {
						std::cout << std::setw(cellheight + 2) << "|";
					}
				}
				std::cout << std::endl;
			}
		}
		if (gridlines) {
			for (int k = 0; k < rightshift; k++)
				std::cout << RIGHT;
			for (int j = 0; j < map->getC(); j++) {
				for (int c = 0; c < cellheight; c++)
					std::cout << "-";
				std::cout << "--";
			}
			std::cout << "-";
		}
		std::cout << std::endl;

	}
}

void Board::MoveN() {
	ModifyXY(0, -1);
}
void Board::MoveNE() {
	ModifyXY(1, -1 );
}
void Board::MoveE() {
	ModifyXY(1);
}
void Board::MoveSE() {
	ModifyXY(1, 1);
}
void Board::MoveS() {
	ModifyXY(0, 1);
}
void Board::MoveSW() {
	ModifyXY(-1, 1);
}
void Board::MoveW() {
	ModifyXY(-1);
}
void Board::MoveNW() {
	ModifyXY(-1, -1);
}

void Board::ModifyXY(int xaffect, int yaffect) {
	if (not board_wrapping) {
		//checking for a xward movement (decrease (0) or increase (column max)
		PlayerPos_x = (xaffect > 0) ? (PlayerPos_x + xaffect < map->getC()) ? PlayerPos_x + xaffect : PlayerPos_x : PlayerPos_x;
		PlayerPos_x = (xaffect < 0) ? (PlayerPos_x + xaffect > 0) ? PlayerPos_x + xaffect : PlayerPos_x : PlayerPos_x;

		//checking for a yward movement (decrease (0) or increase (row max)
		PlayerPos_y = (yaffect > 0) ? (PlayerPos_y + yaffect < map->getR()) ? PlayerPos_y + yaffect : PlayerPos_y : PlayerPos_y;
		PlayerPos_y = (yaffect < 0) ? (PlayerPos_y + yaffect > 0) ? PlayerPos_y + yaffect : PlayerPos_y : PlayerPos_y;
	}

	else {
		PlayerPos_x = ((PlayerPos_x + xaffect) % map->getC());
		if (PlayerPos_x < 0) { PlayerPos_x += map->getC(); }

		//checking for a yward movement (decrease (0) or increase (row max)
		PlayerPos_y = ((PlayerPos_y + yaffect) % map->getR());
		if (PlayerPos_y < 0) { PlayerPos_y += map->getR(); }
	}

}

void Board::RunMapApp() {
	char input = ' ';
	bool stop = false;
	int rightshift = 2;
	std::cout << "Input \"W\", \"A\", \"S\", \'D\", or \"Esc\" to quit: " << std::endl;
	int outterloopcount = 0;
	while (!stop) {
		std::cout << ERASELINE;
		PrintBoard(rightshift);
		
		//get the user's input		
		int loopcount = 0;
		do {
			loopcount++;
			if (loopcount > 1) {
				std::cout << UP;
				std::cout << ERASELINE;
			}
			//make input line up with board print
			for (int x = 0; x < rightshift; x++)
				std::cout << RIGHT;
			std::cin >> input;
			
			for (int x = 0; x < rightshift + 1; x++)
				std::cout << LEFT;

			//std::cout << UP;

		} while (tolower(input) != 'w' && tolower(input) != 'a' && tolower(input) != 's' && tolower(input) != 'd' && input != 27 && tolower(input) != 'e' && tolower(input) != 'q' && tolower(input) != 'z' && tolower(input) != 'x');
		//based on input move the character
		switch (input) {
		case 'w':
			MoveN();
			//std::cout << PlayerPos_y;
			break;
		case 'a':
			MoveW();
			break;
		case 's':
			MoveS();
			break;
		case 'd':
			MoveE();
			break;
		case 'e':
			MoveNE();
			break;
		case 'q':
			MoveNW();
			break;
		case 'z':
			MoveSW();
			break;
		case 'x':
			MoveSE();
			break;
		case 27:
			stop = true;
			break;
		}
		/*
		for (int x = 0; x < rightshift; x++)
			std::cout << RIGHT;
		std::cout << "Player Position: (" << PlayerPos_x << ", " << PlayerPos_y << ")";*/


		if (!stop) {
			/*
			for (int x = 0; x < rightshift; x++)
				std::cout << RIGHT;

			std::cout << "Player Position: (" << PlayerPos_x << ", " << PlayerPos_y << ")";
			*/
			//return to the first line of the print board statement
			int sizemultiplier = cellheight;
			int modifier = 2; //potentially wrong if gridlines == false
			if (gridlines)
				sizemultiplier ++;
			if (printcurplyrpos)
				modifier++;
			for (int i = 0; i < (map->getR() * sizemultiplier) + modifier; i++) {
				std::cout << ERASELINE;
				std::cout << UP;
			}
		}
	}
}