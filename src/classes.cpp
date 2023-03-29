#include "classes.h"
#include "functions.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <time.h>
/*
 * Functions for classes
 */


// User Constructor Implementation
User::User(std::string name){
	name_ = name;
	srand(time(0));
	SavingsAccount account = {rand() % 900000 + 100000, 0};
	accPairs.push_back(account);
	std::string hashedname = hashFunc(name);

	// Write account number and balance to file
	std::ofstream outFile("C:\\Users\\OlleW\\ecplipse workspace CPP\\"
			"SankBank\\src\\userdata", std::ios::app);
	if (outFile.is_open())
	{
		outFile << hashedname + " " + std::to_string(account.AccNr) + " " +
				std::to_string(account.Balance) << std::endl;
		outFile.close();
	}
}

//constructor used for saved users
User::User(std::string name, int choice)
{
	name_ = name;
	std::string hashedname = hashFunc(name);
	// Open the file for reading
	std::ifstream infile("C:\\Users\\OlleW\\ecplipse workspace CPP\\"
			"SankBank\\src\\userdata");
	std::string line;

	// Iterate over each line in the file
	while (std::getline(infile, line))
	{
		// Split the line into its components
		std::istringstream iss(line);
		std::string file_name, accNr_str, balance_str;
		if (!(iss >> file_name >> accNr_str >> balance_str))
		{
			continue;
		}

		// If the name matches, add the account to the user's accounts vector
		if (file_name == hashedname)
		{
			int accNr = std::stoi(accNr_str);
			int balance = std::stoi(balance_str);

			// Check if account already exists in user's accounts
			bool exists = false;
			for (const SavingsAccount& account : accPairs)
			{
				if (account.AccNr == accNr)
				{
					exists = true;
					break;
				}
			}

			// Add the account to the user's accounts vector if it doesn't already exist
			if (!exists)
			{
				accPairs.push_back(SavingsAccount{ accNr, balance });
			}
		}
	}

	// Close the file
	infile.close();
}


// User Functions
void User::printSavingAccounts()
{
	for (const auto & account : accPairs)
	{
		std::cout << "Account nr: " << account.AccNr << " has current balance of: "
				<< account.Balance << " SEK" << std::endl;
	}

}
std::string User::GetName()
{
	return name_;
}
int User::GetNumAccounts()
{
	return accPairs.size();
}
SavingsAccount User::GetAccount(int index)
{
	return accPairs[index];
}
void User::AddAccount(SavingsAccount account)
{
	accPairs.push_back(account);
}

int User::getAccNr(int index)
{
	return accPairs[index].AccNr;
}

int User::getBalance(int index)
{
	return accPairs[index].Balance;
}
void User::createSavingAcc()
{

}
void User::deposit()
{

}

void User::transaction()
{

}

