#include "Array2D.h"

//Infrastructural:
template<typename T>
Array2D<T>::Array2D(int row, int col, T init) {
	this->row = row;
	this->col = col;
	initval = init;
	Array = new T* [this->row];
	for (int i = 0; i < row; i++) {
		Array[i] = new T[this->col];
		for (int j = 0; j < col; j++)
			Array[i][j] = initval;
	}
}
template<typename T>
Array2D<T>::~Array2D() {
	if (Array)
		DeleteArray();
}

//----------------------------------------------------------

//Utility Functions:
template<typename T>
void Array2D<T>::Print() {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (Array[i][j])
				std::cout << Array[i][j] << " ";
			else
				std::cout << "NA" << i << j << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

template<typename T>
void Array2D<T>::DeleteArray() {
	for (int i = 0; i < row; i++) {
		delete[] Array[i];
	}
	delete[] Array;
	Array = NULL;
}

//----------------------------------------------------------

template<typename T>
void Array2D<T>::AddCol() {
	T** temp;
	temp = new T* [row];

	for (int i = 0; i < row; i++) {
		temp[i] = new T[col + 1];
		for (int j = 0; j < col + 1; j++) {
			if (j < col)
				temp[i][j] = Array[i][j];
			else
				temp[i][j] = initval;
		}
	}
	DeleteArray();
	col++;
	Array = temp;
}

template<typename T>
void Array2D<T>::AddRow() {
	T** temp;
	temp = new T* [row + 1];

	for (int i = 0; i < row + 1; i++) {
		temp[i] = new T[col];
		for (int j = 0; j < col; j++) {
			if (i < row)
				temp[i][j] = Array[i][j];
			else
				temp[i][j] = initval;
		}
	}
	DeleteArray();
	row++;
	Array = temp;
}

template<typename T>
void Array2D<T>::Resize(int newr, int newc) {
	T** temp;
	temp = new T* [newr];

	for (int i = 0; i < newr; i++) {
		temp[i] = new T[newc];
		for (int j = 0; j < newc; j++) {
			if (i < row && j < col)
				temp[i][j] = Array[i][j];
			else
				temp[i][j] = initval;
		}
	}
	DeleteArray();
	col = newc;
	row = newr;
	Array = temp;
}
//swap the ith and jth rows
template<typename T>
void Array2D<T>::SwapRows(int i, int j) {
	T temp;
	if (i < row && j < row) {
		for (int k = 0; k < col; k++) {
			temp = Array[i][k];
			Array[i][k] = Array[j][k];
			Array[j][k] = temp;
		}
	}
}

//swap the ith and jth columns
template<typename T>
void Array2D<T>::SwapCols(int i, int j) {
	if (i < col && j < col) {
		T temp;
		for (int k = 0; k < row; k++) {
			temp = Array[k][i];
			Array[k][i] = Array[k][j];
			Array[k][j] = temp;
		}
	}
}

//remove ith row- default last row
template<typename T>
void Array2D<T>::RemoveRow(int r) {
	if(r == INT_MIN)
		r = row - 1;

	T** temp;
	temp = new T * [row - 1];

	for (int i = 0; i < row; i++) {
		if(i < row - 1)
			temp[i] = new T[col];
		for (int j = 0; j < col; j++) {
			if (i < r)
				temp[i][j] = Array[i][j];
			else if (i > r)
				temp[i - 1][j] = Array[i][j];
		}
	}
	DeleteArray();
	Array = temp;
	row--;
}

//remove ith column- default last row
template<typename T>
void Array2D<T>::RemoveColumn(int c) {
	if (c == INT_MIN)
		c = col - 1;

	T** temp;
	temp = new T * [row];

	for (int i = 0; i < row; i++) {
		temp[i] = new T[col - 1];
		for (int j = 0; j < col; j++) {
			if (j < c)
				temp[i][j] = Array[i][j];
			else if (j > c)
				temp[i][j - 1] = Array[i][j];
		}
	}
	DeleteArray();
	Array = temp;
	col--;
}
//----------------------------------------------------------

//Operator Overloads:
template<typename T>
T* Array2D<T>::operator[](int i) {
	return Array[i];
}

template<typename T>
void Array2D<T>::operator++() {
	AddCol(); //append column to end of array
}

template<typename T>
void Array2D<T>::operator--() {
	RemoveColumn(); //remove the last column
}