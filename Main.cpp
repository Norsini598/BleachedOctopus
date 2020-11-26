#include <iostream>
#include <chrono>
#include <thread>

#include "Map.h"
const bool TestingGameBoard = true;
const bool TestingArray2D = false;
int main() {
	if (TestingArray2D) {
		Array2D<char> x(5, 5, ';');
		x.Print();
		x.Resize(6, 6);
		x.Print();
		char val;
		std::cin >> val;
		std::cout << (int)val;
		std::cout << std::endl;
	}
	/*std::cout << "HELLO";
	std::cout << UP << "OH MY";
	std::this_thread::sleep_until(std::chrono::system_clock::now() + std::chrono::seconds(2));*/
	if (TestingGameBoard) {
		Board GameBoad(8, 8);

		/*
		std::cout << "A basic print:" << std::endl;
		GameBoad.BasicPrint();
		std::cout << std::endl;

		std::cout << "Custom print:" << std::endl;
		GameBoad.PrintBoard(0);
		std::cout << std::endl;
		*/

		std::cout << "Running app: " << std::endl;
		GameBoad.RunMapApp();
		/*
		for(int i = 0; i < 3; i++)
			std::cout << RIGHT;
		*/


		//GameBoad[0][0] = '2';
		//GameBoad.BasicPrint();


		/*std::cout << std::endl << std::endl;
		std::cout << "Hello";
		std::cout << "\rGoodbye";
		std::cout << "Tatos";
		std::cout << "\r!";*/



	}
	
	return 0;
}