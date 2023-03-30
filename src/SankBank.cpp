#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
#include <fstream>
#include <sstream>
#include <string>


#include "classes.h"
#include "functions.h"


int main() {

//	loop:
//	int choice = 0;
//	std::string username;
//	int existingUser = 0;
//
//	do {
//		// Start the inactive function in a separate thread
//		std::thread inactiveThread(inactiveFunction, std::ref(choice));
//
//		printStartMenu();
//		std::cin >> choice;
//
//		switch (choice)
//		{
//		case 1:
//			std::cout << "Enter your name: " << std::endl;
//			std::cin >> username;
//			if (login(username))
//			{
//				choice = 3;
//				existingUser = 1;
//			}
//			break;
//		case 2:
//			std::cout << "Enter your name: " << std::endl;
//			std::cin >> username;
//			createUser(username);
//			choice = 3;
//			existingUser = 0;
//			break;
//		case 3:
//			std::cout << "Confirm exit(1 = yes, 0 = no)" << std::endl;
//			int confirmExit;
//			std::cin >> confirmExit;
//			inactiveThread.join();
//			if(confirmExit)
//			{
//				std::cout << "Goodbye!" << std::endl;
//				return 0;
//			}
//			else
//			{
//				goto loop;
//			}
//		default:
//			inactiveThread.join();
//			std::cout << "Invalid choice." << std::endl;
//			break;
//		}
//		// Join the inactive thread to prevent it from running after the program has exited
//		inactiveThread.join();
//
//	} while (choice != 3);
//
//	//	Create User depending if created new acc or existing user with accounts
//	//	If existingUser, then using a constructor that reads from userdata
//	//	to extract savingsaccount
//	if (existingUser)
//	{
//		User user1(username, existingUser);
//		int returnValue = menuTwoFunc(user1);
//		if (returnValue == 0)
//			return 0;
//	}
//	else
//	{
//		User user1 (username);
//		int returnValue = menuTwoFunc(user1);
//		if (returnValue == 0)
//			return 0;
//	}
//
	User Tom("Tom");

	printUserInterfaceDeposit(Tom);
	printSuccesDeposit(Tom);


	// open the file in
    std::string filename = "C:\\Users\\corne\\eclipse-workspace\\Gamma_Bank\\src\\userdata";
    std::ifstream infile(filename);
    if (!infile) {
        std::cerr << "Error: could not open file '" << filename << "'" << std::endl;
        return 1;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(infile, line)) {
        lines.push_back(line);
    }

    //declaring the index to minus -1. Since the first index i 0 in the vector,
    //this is our error handling if account not found.
    int accountIndex = -1;
    for (int i = 0; i < (int)lines.size(); i++) {
        std::istringstream iss(lines[i]);
        std::string file_name, accNr_str, balance_str;
        iss >> file_name >> accNr_str >> balance_str;

        if (accNr_str == "2222") {
            int balance = std::stoi(balance_str);
            balance += 3333 ;
            balance_str = std::to_string(balance);

            //creates a new updated line with these 3 variables
            std::ostringstream oss;
            oss << file_name << " " << accNr_str << " " << balance_str;

            //convert that specific line (in where we found the matching account) to string
            lines[i] = oss.str();

            accountIndex = i;
            break;
        }
    }

    if (accountIndex == -1) {
        std::cerr << "Error: could not find account" << std::endl;
        return 1;
    }

    // Write the updated lines back to the file
    std::ofstream outfile(filename);
    if (!outfile) {
        std::cerr << "Error: could not write to file '" << filename << "'" << std::endl;
        return 1;
    }
    for (const auto& x : lines) {
        outfile << x << std::endl;
    }
    outfile.close();


    //display the updated balance in that specific line
    std::istringstream iss(lines[accountIndex]);
    std::string file_name, accNr_str, balance_str;
    iss >> file_name >> accNr_str >> balance_str;
    std::cout << "Updated balance for account " << accNr_str << ": " << balance_str << std::endl;

	return 0;
}
