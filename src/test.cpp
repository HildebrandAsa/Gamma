#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
#include <string>
#include "classes.h"
#include "functions.h"

template <typename T>


bool assert_equal(const T& result, T expected){
	return result == expected;
}


void report_outcome(const std::string& testname, bool outcome){
	if (outcome){
		std::cout << "Passed: " << testname << std::endl;
	}
	else{
		std::cout << "Failed: " << testname << std::endl;
	}
}

void testUserConstructor(){
	//Arrange
	User user1 ("Lisa");
	int balance = user1.getBalance(0);

	//Act
	bool result1 = assert_equal(user1.GetName(), std::string("Lisa"));
	bool result2 = assert_equal(balance, 0);

	//Assert
	report_outcome("Test_assert_equal_true_is_true", assert_equal(result1, true));
	report_outcome("Test_assert_equal_true_is_true", assert_equal(result2, true));
}

void testUserDeposition(){
	//Arrange
	User user1 ("Lisa");
	user1.deposit();  //Test assumes a user input of 100
	int balance = user1.getBalance(0);

	//Act
	bool result1 = assert_equal(balance, 100);

	//Assert
	report_outcome("Test_assert_equal_true_is_true", assert_equal(result1, true));
}


int main() {
	testUserConstructor();
	testUserDeposition();

	return 0;
}
