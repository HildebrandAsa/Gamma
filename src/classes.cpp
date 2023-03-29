#include "classes.h"

/*
 * Functions for classes
 */


//	 User Constructor Implementation

//	User::User(std::string name) {
//	this->name = name;
//



//constructor for existing customer to check current balance


User::User(std::string filename){


	//open the file thats holding the data.
	std::ifstream file("C:\\Users\\corne\\eclipse-workspace\\Gamma_Bank\\src\\userdata");

	//check if the file is open. if not, an error message will be displayed. check else down below.
	if(file.is_open())
	{

		//check the current statel there is an eventual error with the file before reading in
		if (file.good())
		{

			//create a string to store the data
			std::string line;

			//start a whileloop to start read the data from the files

			while (getline(file,line))
			{
				//declare input stream object iss for line to use the operators >>
				std::istringstream iss(line);

				//create a an struct object account
				Account account;

				//now lets read in the the line. If read is succes, we store the data into account
				// and then push data into the account vector accPairs
				if (iss >> account.AccNr >> account.Balance)
				{
					accPairs.push_back(account);
					}
					else
					{
						std::cerr << "Error: Failed to read data from line: " << line << "\n";
					}

			}
			file.close();

			}
			else
			{
				std::cerr << "Error: State failure.\n";
			}

		}
		else
		{
		std::cerr << "Error: Failed to open file.\n";
		}

	}







void User:: print_accounts()
	{
		for (const auto & account : accPairs)
			std::cout <<"Account nr: " << account.AccNr << " has current balance of: " << account.Balance<< " SEK" <<std::endl;

	}







// User Functions
