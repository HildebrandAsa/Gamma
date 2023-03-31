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
	accounts_.push_back(account);
	std::string hashedname = hashFunc(name);

	// Write account number and balance to file
	std::ofstream outFile("C:\\Users\\corne\\eclipse\\bank_testing\\userdata", std::ios::app);
	if (outFile.is_open())
	{
		outFile << hashedname + " " + std::to_string(account.AccNr) + " " +
				std::to_string(account.balance) << std::endl;
		outFile.close();
	}
}

//constructor used for saved users
User::User(std::string name, int choice)
{
	name_ = name;
	std::string hashedname = hashFunc(name);
	// Open the file for reading
	std::ifstream infile("C:\\Users\\corne\\eclipse\\bank_testing\\userdata");
	std::string line;

	// Iterate over each line in the file
	while (std::getline(infile, line))
	{
		// Split the line into its components
		std::istringstream iss(line);
		std::string fileName, accNrStr, balanceStr;
		if (!(iss >> fileName >> accNrStr >> balanceStr))
		{
			continue;
		}

		// If the name matches, add the account to the user's accounts vector
		if (fileName == hashedname)
		{
			int accNr = std::stoi(accNrStr);
			int balance = std::stoi(balanceStr);

			// Check if account already exists in user's accounts
			bool exists = false;
			for (const SavingsAccount& account : accounts_)
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
				accounts_.push_back(SavingsAccount{ accNr, balance });
			}
		}
	}

	// Close the file
	infile.close();
}


// User Functions
std::string User::GetName()
{
	return name_;
}
int User::GetNumAccounts()
{
	return accounts_.size();
}
SavingsAccount User::GetAccount(int index)
{
	return accounts_[index];
}
void User::AddAccount(SavingsAccount account)
{
	accounts_.push_back(account);
}

int User::getAccNr(int index)
{
	return accounts_[index].AccNr;
}


int User::getBalance(int index)
{
	return accounts_[index].balance;

}
void User::createSavingAcc()
{
	// Generate a new random account number
	srand(time(0));
	int accNr = rand() % 900000 + 100000;
	SavingsAccount account = { accNr, 0 };
	// Adds Acc to classvector
	accounts_.push_back(account);

	// Write the new account to file
	std::string hashedname = hashFunc(name_);
	std::ofstream outFile("C:\\Users\\corne\\eclipse\\bank_testing\\userdata", std::ios::app);
	if (outFile.is_open())
	{
		outFile << hashedname + " " + std::to_string(account.AccNr) + " " +
				std::to_string(account.balance) << std::endl;
		outFile.close();
	}
	std::cout << "New savingsaccount " + std::to_string(account.AccNr) +
			" created successfully!" << std::endl;

}
void User::deposit()
{


	std::cout << "========================" << std::endl;
	std::cout << "       *DEPOSIT* 		  " << std::endl;
	std::cout << "   Show me the money!   " << std::endl;
	std::cout << "========================" << std::endl;
	std::cout << std::endl;


	for (int i = 0; i < (int)accounts_.size(); i++)
		{

		std::cout << "Account["<<i+1<<"] " << accounts_[i].AccNr << std::endl;
		std::cout << "Balance    " 		   << accounts_[i].balance << " $" << std::endl;
		std::cout << std::endl;
		}

	std::cout << "========================"<< std::endl;
	std::cout << "Select account: ";

	int accIndex;
	std::cin >> accIndex;
	accIndex--;
	std::cout << "========================"<< std::endl;

	//check if account chose is within index
	int accountSize = (int)accounts_.size();
	if (accIndex >= accountSize || accIndex < 0)
	{
		std::cout << "Invalid Account" << std::endl;
		return;
	}

	// Ask the user how much money to deposit
	std::cout << "Amount to deposit: ";
	double amount;
	std::cin >> amount;

	// Update the account balance in memory
	accounts_[accIndex].balance += amount;

	// Update the account balance in file
	std::string hashedname = hashFunc(name_);
	std::ifstream infile("C:\\Users\\corne\\eclipse\\bank_testing\\userdata");
	std::string line;
	std::vector<std::string> fileLines;
	while (std::getline(infile, line))
	{
		fileLines.push_back(line);
	}
	infile.close();
	std::ofstream outFile("C:\\Users\\corne\\eclipse\\bank_testing\\userdata", std::ios::trunc);
	// Iterate over each line in the file
	for (std::string& fileLine : fileLines)
	{
		// Split the line into its components
		std::istringstream iss(fileLine);
		std::string fileName, accNrStr, balanceStr;
		if (!(iss >> fileName >> accNrStr >> balanceStr))
		{
			continue;
		}

		// If the account number matches, update the balance and write the new line to file
		if (std::stoi(accNrStr) == accounts_[accIndex].AccNr && fileName == hashedname)
		{
			outFile << hashedname + " " + std::to_string(accounts_[accIndex].AccNr) + " " +
					std::to_string(accounts_[accIndex].balance) << std::endl;
		}
		else
		{
			//also add all other lines back as they were
			outFile << fileName + " " + accNrStr + " " + balanceStr << std::endl;
		}
	}
	outFile.close();

	std::cout << "===============================" << std::endl;
	std::cout << "Fantastic, deposit of "		   << amount<<" $ done" << std::endl;
	std::cout << "Thanks for the money!" 		   << std::endl;
	std::cout << "===============================" << std::endl;
}

void User::transaction()
{
	std::cout << "========================" << std::endl;
	std::cout << "     *TRANSACTION*"       << std::endl;
	std::cout << "     Move the money!    " << std::endl;
	std::cout << "========================" << std::endl;
	std::cout  << std::endl;


	for (int i = 0; i < (int)accounts_.size(); i++)
		{
		std::cout << "Account["<<i+1<<"] " << accounts_[i].AccNr << std::endl;
		std::cout << "Balance    " << accounts_[i].balance << " $" << std::endl;
		std::cout << std::endl;
		}


	std::cout << "========================" << std::endl;
	std::cout << "Transfer from account: ";

	int accIndex;
	std::cin >> accIndex;
	accIndex--;

	//check if account chose is within index
	int accountSize = accounts_.size();
	if (accIndex >= accountSize || accIndex < 0)
	{
		std::cout << "Invalid Account" << std::endl;
		return;
	}

	//Ask how much and check if balance is sufficient
	std::cout << "Amount: ";
	double amount;
	std::cin >> amount;


	//checks balance, continues if it is enough
	if (amount > accounts_[accIndex].balance)
	{
		std::cout << "The account is missing sufficient funds" << std::endl;
		return;

	}

	// Ask the user which account to deposit money into
	std::cout << "Transer to account " <<std::endl;
	std::cout << "Enter 6 digits: ";
	std::string depositAcc;
	std::cin >> depositAcc;


	//checks if account given is same users and corrects balance
	for (int i = 0; i < (int)accounts_.size(); i++ )
	{
		if (std::stoi(depositAcc) == accounts_[i].AccNr)
		{
			accounts_[i].balance += amount;
		}

	}

	//Read file and store lines in vector
	std::ifstream infile("C:\\Users\\corne\\eclipse\\bank_testing\\userdata");
	std::string line;
	std::vector<std::string> fileLines;
	while (std::getline(infile, line))
	{
		fileLines.push_back(line);
	}
	infile.close();

	//Check if depositAcc is an existing account in file
	std::ofstream outFile("C:\\Users\\corne\\eclipse\\bank_testing\\userdata", std::ios::trunc);
	int accNrFlag = 0;
	// Iterate over each line in the file
	for (std::string& fileLine : fileLines)
	{
		// Split the line into its components
		std::istringstream iss(fileLine);
		std::string fileName, accNrStr, balanceStr;
		if (!(iss >> fileName >> accNrStr >> balanceStr))
		{
			continue;
		}
		if (accNrStr == depositAcc)
		{
			accNrFlag = 1;
		}
	}
	outFile.close();

	//If account is existing, do transfer, else tell user that acc not exist
	if (accNrFlag)
	{
		accounts_[accIndex].balance -= amount;
		std::ofstream outFile("C:\\Users\\corne\\eclipse\\bank_testing\\userdata", std::ios::trunc);
		for (std::string& fileLine : fileLines)
		{
			// Split the line into its components
			std::istringstream iss(fileLine);
			std::string fileName, accNrStr, balanceStr;
			if (!(iss >> fileName >> accNrStr >> balanceStr))
			{
				continue;
			}
			// If the account number matches, update the balance and write the new line to file
			if (std::stoi(accNrStr) == accounts_[accIndex].AccNr)
			{
				outFile << fileName + " " + accNrStr + " " +
						std::to_string(accounts_[accIndex].balance) << std::endl;
			}
			else if (std::stoi(accNrStr) == std::stoi(depositAcc))
			{
				int newBalance = std::stoi(balanceStr) + amount;
				outFile << fileName + " " + accNrStr + " " +
						std::to_string(newBalance) << std::endl;
			}
			else
			{
				//also add all other lines back as they were
				outFile << fileName + " " + accNrStr + " " + balanceStr << std::endl;
			}
		}
		outFile.close();
		std::cout << "================================" << std::endl;
		std::cout << "Great, transaction of "<< amount  <<" $ done" << std::endl;
		std::cout << "================================" << std::endl;
	}
	else
	{
		std::cout << "That account does not exist" << std::endl;
	}

}
