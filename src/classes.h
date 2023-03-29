#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>



//Struct holding variables account and balance

struct Account{
	int AccNr;
	int Balance;
};


//Declaration of classes

//User
class User {
private:
	std::string name;
	std::vector<Account> accPairs;

public:

	//Constructor displaying an already existing client
	User(std::string filename);
	void print_accounts();


};
