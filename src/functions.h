/*
 * functions.h
 *
 *  Created on: 29 Mar 2023
 *      Author: corne
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_





#endif /* FUNCTIONS_H_ */


#include "classes.h"

//declaration of general functions
void printStartMenu();
std::string hashFunc(std::string password);
void createUser(std::string name);
bool login(std::string name);
void printUserInterface(User user1);
int menuTwoFunc(User user1);
void inactiveFunction(int& choice);
void printUserInterfaceDeposit(User user1);
void printSuccesDeposit(User user1);
