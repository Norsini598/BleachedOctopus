/*
  Print Board Functions:
	Gridlines-- are gridlines being printed? Vertical/Hortizontal/both
	Whole Print Shift: RIGHTSHIFT
	Cell Height
	Cell Width
	Cells can have characteristics--randomize cell's width and height but will sum to X each time:
		X = c1_wi + c2_wi + c3_wi [c#_wi-cell number in column direction's cell width and of the ith row]
		X = c1_wj + c2_wj + c3_wj [c#_wj-cell number in column direction's cell width and of the jth row]
*/

#ifndef CELL_H
#define CELL_H

#include <iostream>

template<typename T>
class Cell {
	private:
		short cell_w, cell_h;
		//short cell_area;
		T data; //in the example of the game I want to make this would be 'Land'
		std::string representation; //a string of length cell_w * ceLL_h, with a \n every cell_w interval


	public:
		Cell();
		~Cell();

		friend std::osteam& operator<<(std::ostream&, const Cell<T>&);
		
		T getdata() { return data; }
		short getcell_w() { return cell_w; }
		short getcell_h() { return cell_h; }
		std::string getrepresentation() { return representation; }
		
		void setcell_w(short cell) { cell_w = cell; }
		void setcell_h(short cell) { cell_h = cell; }
		void setrepresentation(std::string set) {representation = set; } //set each index to the index of set--depends on setting in 'data' can be color of tile, info about what is on the tile, etc.
		//if the input is > that cell_w * cell_h characters then it will be cutoff.
		void set_ij_representation(short i, short j, char item) { representation[i][j] = item; }




};

struct CellRepresentation {
	Cell cell;
	char char_representation; //on a print out of the 
}
