#pragma once
#include <iostream>
#include <string>
#include <vector>


//Declaration of classes


struct SavingsAccount
{
	int AccNr;
	int balance;
};

//User
class User
{
private:
	std::string name_;
	std::vector<SavingsAccount> accounts_;

public:
	// Constructor
	User(std::string name);
	User(std::string name, int choice);

	//User Functions
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
