//============================================================================
// Name        : SankBank.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>

#include "classes.h"
#include "functions.h"


int main() {

	loop:
	int choice = 0;
	std::string username;
	int existingUser = 0;

	do {
		// Start the inactive function in a separate thread
//		std::thread inactiveThread(inactiveFunction, std::ref(choice));

		printStartMenu();
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			std::cout << "Enter your name: " << std::endl;
			std::cin >> username;
			if (login(username))
			{
				choice = 3;
				existingUser = 1;
			}
			break;
		case 2:
			std::cout << "Enter your name: " << std::endl;
			std::cin >> username;
			createUser(username);
			choice = 3;
			existingUser = 0;
			break;
		case 3:
			std::cout << "Confirm exit(1 = yes, 0 = no)" << std::endl;
			int confirmExit;
			std::cin >> confirmExit;
//			inactiveThread.join();
			if(confirmExit)
			{
				std::cout << "Goodbye!" << std::endl;
				return 0;
			}
			else
			{
				goto loop;
			}
		default:
//			inactiveThread.join();
			std::cout << "Invalid choice." << std::endl;
			break;
		}
		// Join the inactive thread to prevent it from running after the program has exited
//		inactiveThread.join();

	} while (choice != 3);

	//	Create User depending if created new acc or existing user with accounts
	//	If existingUser, then using a constructor that reads from userdata
	//	to extract savingsaccount
	if (existingUser)
	{
		User user1(username, existingUser);
		int returnValue = menuTwoFunc(user1);
		if (returnValue == 0)
			return 0;
	}
	else
	{
		User user1 (username);
		int returnValue = menuTwoFunc(user1);
		if (returnValue == 0)
			return 0;
	}



	return 0;
}
