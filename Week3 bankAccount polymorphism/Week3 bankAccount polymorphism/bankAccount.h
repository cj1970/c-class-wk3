//BASE CLASS DEFINITION
//bankAccount base class

#pragma once

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H


#include <string>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;






class bankAccount
{

public:

	//DEFAULT CONSTRUCTOR****************************************************************
	bankAccount();


	//PARAMETERIZED CONSTRUCTOR**********************************************************
	bankAccount(int, string, double);


	//CONSTANT MEMBER FUNCTIONS

	int getAccountNumber() const;

	double getBalance() const;

	string getName() const;
	
	
	virtual void print() const;						//VIRTUAL FUNCTION

	
	virtual void createMonthlyStatement() = 0;		//PURE VIRTUAL FUNCTION


	//MODIFICATION MEMBER FUNCTIONS

	void setName(string userName);

	void deposit(double moneyIn);

	virtual void withdraw(double moneyOut);			//VIRTUAL FUNCTION


protected:

	string name = "";

	double balance = 0;

	int accountNumber = 0;


};


#endif 