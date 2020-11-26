#ifndef Array_2d_H
#define Array_2d_H
#include <iostream>
#include <climits> //for INT_MIN

#include "EscapeSequences.h"

template<typename T>
class Array2D {
private:
	T** Array;
	int row, col;
	T initval;

public:
	Array2D(int = 2, int  = 2, T = NULL);
	virtual ~Array2D();

	void DeleteArray();
	
	T* operator[](const int);

	void operator++(); 
	void operator--();
	void operator+=(Array2D<T>); //Add an array into this array

	inline int getR() const { return row; }
	inline int getC() const { return col; }

	void AddRow();
	void AddCol();
	void Resize(int, int);//resize the array with the new additions. cells now out of the array are discarded new ones set to initval
	void SwapRows(int, int);
	void SwapCols(int, int);
	void RemoveColumn(int = INT_MIN);
	void RemoveRow(int = INT_MIN);
	
	virtual void Print();

};
/*template<typename T>
	friend std::ostream& operator<<(std::ofstream& out, Array2D<T>& A){
		for (short i = 0; i < w; i++) {
			for (short j = 0; j < l; j++) {
				if (Array[i][j] == NULL)
					out << "NULL" << " ";
				else
					out << Array[i][j] << " ";
			}
			out << std::endl;
		}
		out << std::endl;

		return out;
	}*/

#endif // !2dArray_H

