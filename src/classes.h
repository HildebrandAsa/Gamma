#pragma once
#include <iostream>
#include <string>
#include <vector>


//Declaration of classes

//changed to savingsaccount to not be confused with useraccount
struct SavingsAccount
{
	int AccNr;
	int Balance;
};

//User
class User
{
private:
	std::string name_;
	std::vector<SavingsAccount> accPairs;

public:
	// Constructor
	User(std::string name);
	User(std::string name, int choice);

	//User Functions
	void printSavingAccounts();
	std::string GetName();
	int GetNumAccounts();
	SavingsAccount GetAccount(int index);
	int getAccNr(int index);
	int getBalance(int index);
	void AddAccount(SavingsAccount account);
	void createSavingAcc();
	void deposit();
	void transaction();

};
