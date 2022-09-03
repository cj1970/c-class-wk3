//HEADER FOR SAVINGS BANKACCOUNT
#pragma once

#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H


#include "bankAccount.h"



class savingsAccount :
    public bankAccount
{

public:




	//DEFAULT CONSTRUCTOR****************************************************************
	savingsAccount();


	//PARAMETERIZED CONSTRUCTOR**********************************************************

	savingsAccount(string, int, double, double);


	//CONSTANT MEMBER FUNCTIONS**********************************************************

	double getInterestRate(int) const;

	void print() const;



	//MODIFICATION MEMBER FUNCTIONS******************************************************

	void setInterestRate(double);

	void withdraw(double);

	void postInterest(int);

	void createMonthlyStatement();


protected:

	double interestRate = 0;


};

#endif
