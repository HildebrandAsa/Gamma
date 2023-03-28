#include "functions.h"

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <conio.h>
#include <sstream>
#include <iomanip>
#include <algorithm>


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

std::string hashFunc(std::string password)
{
    std::string hash = password;
    std::reverse(hash.begin(), hash.end());
    std::transform(hash.begin(), hash.end(), hash.begin(), [](unsigned char c) {
        return c ^ 0x55;
    });
    return hash;
}

// Function to create a new user
void createUser()
{
	std::string name, password;
	std::cout << "Enter your name: ";
	std::cin >> name;
	std::cout << "Enter a password: ";
	std::cin >> password;
	std::string hashedPassword = hashFunc(password);

	std::ofstream file("C:\\Users\\OlleWigarthsson\\ecplipse workspace CPP"
			"\\SankBank\\src\\logindata", std::ios::app);
	if (file.is_open()) {
		file << name << " " << hashedPassword << std::endl;
		file.close();
	} else {
		std::cout << "Error: Unable to open file." << std::endl;
	}
	std::cout << "User created successfully!" << std::endl;
}

//login function that returns true if user enters correct inlogg
bool login(std::string name)
{
	std::string password;
	std::cout << "Enter your password: ";
	std::cin >> password;
	std::string hashedPassword = hashFunc(password);

	std::ifstream file("C:\\Users\\OlleWigarthsson\\ecplipse workspace CPP"
			"\\SankBank\\src\\logindata");
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			size_t pos = line.find(' ');
			if (pos != std::string::npos) {
				std::string file_name = line.substr(0, pos);
				std::string file_password = line.substr(pos+1);
				if (name == file_name && hashedPassword == file_password) {
					std::cout << "Login successful!" << std::endl;
					return true;
				}
			}
		}
		std::cout << "Invalid name or password." << std::endl;
		return false;
	} else {
		std::cout << "Error: Unable to open file." << std::endl;
		return false;
	}
}
