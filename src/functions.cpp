#include "functions.h"
#include "classes.h"

#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <thread>
#include <chrono>


//General functions
void printStartMenu()

{
	std::cout << "========================" << std::endl;
	std::cout << " Welcome to Sank Bank" << std::endl;
	std::cout << "========================" << std::endl;
	std::cout << "Make a choice:" << std::endl;
	std::cout << "1. Login" << std::endl;
	std::cout << "2. Create account" << std::endl;
	std::cout << "3. Quit" << std::endl;
	std::cout << "========================" << std::endl;
}
//manipulates string (username and password) to store in file
std::string hashFunc(std::string password)
{
	std::string hash = password;
	std::reverse(hash.begin(), hash.end());
	std::transform(hash.begin(), hash.end(), hash.begin(), [](unsigned char c)
	{
		return c ^ 0x55;
	});
	return hash;
}

// Function to create a new user
void createUser(std::string name)
{
	std::string password;
	std::cout << "Enter a password: ";
	std::cin >> password;
	std::string hashedPassword = hashFunc(password);
	std::string hashedname = hashFunc(name);

	//Stores hashed name and password in file
	std::ofstream file("C:\\Users\\OlleW\\ecplipse workspace CPP\\"
			"SankBank\\src\\logindata", std::ios::app);
	if (file.is_open())
	{
		file << hashedname << " " << hashedPassword << std::endl;
		file.close();
	}
	else
	{
		std::cout << "Error: Unable to open file." << std::endl;
	}
	std::cout << std::endl << "User created successfully!" << std::endl;
	std::cout << "Please wait while loading..." << std::endl << std::endl;
}

//login function that returns true if user enters correct inlogg
bool login(std::string name)
{
	std::string password;
	std::cout << "Enter your password: ";
	std::cin >> password;
	std::string hashedPassword = hashFunc(password);
	std::string hashedname = hashFunc(name);

	//Reads file and checks if hashed name and password matches
	std::ifstream file("C:\\Users\\OlleW\\ecplipse workspace CPP\\"
			"SankBank\\src\\logindata");
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			size_t pos = line.find(' ');
			if (pos != std::string::npos)
			{
				std::string fileName = line.substr(0, pos);
				std::string filePassword = line.substr(pos+1);
				if (hashedname == fileName && hashedPassword == filePassword)
				{
					std::cout << std::endl << "Login successful!" << std::endl;
					std::cout << "Please wait while loading..." << std::endl
							<< std::endl;

					return true;
				}
			}
		}
		std::cout << "Invalid name or password." << std::endl;
		return false;
	}
	else
	{
		std::cout << "Error: Unable to open file." << std::endl;
		return false;
	}
}

void printUserInterface(User user1)
{
	std::cout << "========================" << std::endl;
	std::cout << "Welcome " << user1.GetName() << std::endl;
	std::cout << "========================" << std::endl;

	for (int i = 0; i < user1.GetNumAccounts(); i++)
	{
		std::cout << "Account: " << user1.getAccNr(i) << std::endl;
		std::cout << "Balance: " << user1.getBalance(i) << std::endl;
	}

	std::cout << "========================" << std::endl;
	std::cout << std::endl;
	std::cout << "1. Create account" << std::endl;
	std::cout << "2. Deposit" << std::endl;
	std::cout << "3. Transaction" << std::endl;
	std::cout << "4. Quit" << std::endl;
	std::cout << "========================" << std::endl;
}

void inactiveFunction(int& choice)
{
	std::cout << "You have 10 seconds before inactivity" << std::endl;


	// Wait for 10 seconds
	std::this_thread::sleep_for(std::chrono::seconds(10));

	// Check if the user has made a choice
	if (choice == 0)
	{
		std::cout << "Exiting program due to inactivity." << std::endl;
		exit(0);
	}
}

int menuTwoFunc(User user1)
{
	loop2:
	int choice2 = 0;

	do{
		//clearscreen?
		std::thread inactiveThread(inactiveFunction, std::ref(choice2));
		printUserInterface(user1);
		std::cin >> choice2;
		switch(choice2)
		{
		case 1:
//			user1.createSavingAcc();
			break;
		case 2:
//			user1.deposit();
			break;
		case 3:
			// Transfer
		case 4:
			std::cout << "Confirm exit(1 = yes, 0 = no)" << std::endl;
			int confirmExit;
			std::cin >> confirmExit;
			inactiveThread.join();
			if(confirmExit)
			{
				std::cout << "Goodbye!" << std::endl;
				return 0;
			}
			else
			{
				goto loop2;
			}

		default:
			std::cout << "Invalid choice." << std::endl;
			break;
		}
		inactiveThread.join();

	} while (choice2 != 4);
	return 1;
}


