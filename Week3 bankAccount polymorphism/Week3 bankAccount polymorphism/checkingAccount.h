

//CHECKING ACCOUNT HEADER FILE
#pragma once

#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "bankAccount.h"






//DERIVED CLASS checkingAccout

class checkingAccount : public bankAccount
{

public:




	//DEFAULT CONSTRUCTOR****************************************************************
	checkingAccount();


	//PARAMETERIZED CONSTRUCTOR**********************************************************

	checkingAccount(string, int, double, double, double, double);


	//CONSTANT MEMBER FUNCTIONS**********************************************************

	double getMinimumBalance(int) const;

	double getInterestRate(int) const;

	double getServiceCharge(int) const;

	void print() const;




	//MODIFICATION MEMBER FUNCTIONS******************************************************

	void setMinimumBalance(double);

	void setInterestRate(double);

	void setServiceCharge(double);

	void withdraw(double);

	void writeCheck(double);

	void postInterest(int);

	void createMonthlyStatement();



	double interestRate = 0;

	double minimumBalance = 0;

	double serviceCharge = 0;

	double fee = 0;
};


#endif
