
//**********************************************************************
//IMPLEMENTATION FILE SAVINGS BANKACCOUNT******************************
//**********************************************************************


#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H


#include "savingsAccount.h"



//DEFAULT CONTRUCTOR>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

savingsAccount::savingsAccount()
{
	interestRate = 0;

}


//PARAMETERIZED CONSTRUCTOR>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

savingsAccount::savingsAccount(string userName, int userAccountNumber, double userBalance, double userInterestRate)
	:bankAccount(userAccountNumber, userName, userBalance)
{

	name = userName;

	accountNumber = userAccountNumber;

	balance = userBalance;

	interestRate = userInterestRate;
		
};


//CONSTANT MEMBER FUNCTIONS**********************************************************

double savingsAccount::getInterestRate(int userAccountNumber) const
{

	return interestRate;


};


void savingsAccount::print() const
{
	cout << fixed << showpoint;
	cout << setprecision(2)
		<< " Name: " << name << endl
		<< " Account number: " << accountNumber << endl
		<< " Account type: Savings" << endl
		<< " Balance: $" << balance << endl
		<< " Interest rate: " << interestRate * 100 << "%" << endl;
			

};

//MODIFICATION MEMBER FUNCTIONS******************************************************


void savingsAccount::setInterestRate(double userInterestRate)
{

	interestRate = userInterestRate;

};


void savingsAccount::withdraw(double withdrawAmount)
{

	//withdraw checks to make sure there is enough money in the account first and reports a warning if not.  

	if ((balance - withdrawAmount) < 0)
	{
		cout << " There is not enough money in the checking account. " << endl;
	}
	else
	{
		balance -= withdrawAmount;
	
	}

};



void savingsAccount::postInterest(int userAccountNumber)
//postInterest takes the interest amount based off of the total balance and adds it to the balance (balance + balance * interestRate)
{

	balance += (balance * interestRate);


};




void savingsAccount::createMonthlyStatement()
{
	postInterest(accountNumber);
	
};


#endif