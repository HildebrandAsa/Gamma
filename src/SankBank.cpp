//============================================================================
// Name        : SankBank.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <limits>
#include <conio.h>

#include "classes.h"
#include "functions.h"



int main() {

	int choice;
	std::string username;
	do {
		// clear screen?
		printStartMenu();
		std::cin >> choice;
		switch (choice) {
		case 1:
			std::cout << "Enter your name: " << std::endl;
			std::cin >> username;
			if (login(username))
			{
				choice = 3;
			}
			break;
		case 2:
			createUser();
			choice = 3;
			break;
		case 3:
			std::cout << "Goodbye!" << std::endl;
			break;
		default:
			std::cout << "Invalid choice." << std::endl;
		    std::cin.clear();
		    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}
	} while (choice != 3);

	User user1 (username);
	std::cout <<"End of program" << std::endl;



	return 0;
}
