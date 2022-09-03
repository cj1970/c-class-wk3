//BASE CLASS IMPLEMENTATION FILE


#include "bankAccount.h"
#include <string>
#include <iostream>
#include <iomanip>





//DEFAULT CONSTRUCTOR

bankAccount::bankAccount()
{
	accountNumber = 0;
	balance = 0.0;

};


//PARAMETERIZED CONSTRUCTOR**********************************************************
bankAccount::bankAccount(int userAccountNumber, string userAccountName, double userAccountBalance)
{
	accountNumber = userAccountNumber;
	
	name = userAccountName;

	balance = userAccountBalance;

};


//CONSTANT MEMBER FUNCTIONS**********************************************************




int bankAccount::getAccountNumber() const
{

	return accountNumber;

};

double bankAccount::getBalance() const
{

	return balance;

};


string bankAccount::getName() const
{

	return name;

};


void bankAccount::print() const
{
	cout << fixed << showpoint;
	cout << setprecision(2)
		<< " Account number: " << accountNumber
		<< " Account Balance: " << balance
		<< endl;

};


//MODIFICATION MEMBER FUNCTIONS******************************************************



void bankAccount::setName(string userName)
{

	name = userName;


};




void bankAccount::deposit(double moneyIn)
{
	balance += moneyIn;

};



void bankAccount::withdraw(double moneyOut)
{
	balance -= moneyOut;

};


