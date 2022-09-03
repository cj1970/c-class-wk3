
//**********************************************************************
//IMPLEMENTATION FILE CHECKING BANKACCOUNT******************************
//**********************************************************************




#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include "checkingAccount.h"




//DEFAULT CONTRUCTOR>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

checkingAccount::checkingAccount()
{
	interestRate = 0;

	minimumBalance = 0;

	serviceCharge = 0;


}


//PARAMETERIZED CONSTRUCTOR>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

checkingAccount::checkingAccount(string userName, int userAccountNumber, double userBalance, double userMinimumBalance, double userInterestRate, double userServiceCharge)
	:bankAccount(userAccountNumber, userName, userBalance)
{

	name = userName;
	
	accountNumber = userAccountNumber;

	balance = userBalance;

	minimumBalance = userMinimumBalance;

	interestRate = userInterestRate;

	serviceCharge = userServiceCharge;

	fee = 10.00;

};



//)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))
//**************************CONSTANT MEMBER FUNCTIONS**********************************************
//)))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))))





double checkingAccount::getMinimumBalance(int userAccountNumber) const
{

	return minimumBalance;

};

double checkingAccount::getInterestRate(int userAccountNumber) const
{

	return interestRate;


};

double checkingAccount::getServiceCharge(int userAccountNumber) const
{

	return serviceCharge;

};



void checkingAccount::print() const
{
	cout << fixed << showpoint;
	cout << setprecision(2)
		<< " Name:" << name << endl
		<< " Account number: " << accountNumber << endl
		<< " Account type: Checking" << endl
		<< " Balance: $" << balance << endl
		<< " Interest rate: " << checkingAccount::interestRate * 100 << "%" << endl;
		

};





//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
////MODIFICATION MEMBER FUNCTIONS**********************************************************************
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

void checkingAccount::setMinimumBalance(double userMinimumBalance)
{

	checkingAccount::minimumBalance = userMinimumBalance;

};


void checkingAccount::setInterestRate(double userInterestRate)
{

	interestRate = userInterestRate;

};

void checkingAccount::setServiceCharge(double userSetServiceCharge)
{

	serviceCharge = userSetServiceCharge;

};

void checkingAccount::postInterest(int userAccountNumber)
//postInterest takes the interest amount based off of the total balance and adds it to the balance (balance + balance * interestRate)
{

	balance = balance + (balance * interestRate);


};

void checkingAccount::writeCheck(double checkAmount)
//writeCheck calls withdraw
{

	checkingAccount::withdraw(checkAmount);

};

void checkingAccount::withdraw(double withdrawAmount)
{

	//withdraw checks to make sure there is enough money in the account first and reports a warning if not.  

	if ((balance - withdrawAmount) < 0)
		//FIRST If branch: Not enough after withdraw, balance below zero
	{
		cout << "There is not enough money in the checking account." << endl;
		return;
	} //end FIRST if


	else
		//FIRST else branch: there IS enough after withdraw, balance not below zero

	{
				
		//If there is enough money to make the withdraw, it then checks to see if the balance will go below the minimum amount after the withdraw. 
		if ((balance - withdrawAmount) < checkingAccount::minimumBalance)
		
			//SECOND If branch: Balance will NOT go below zero, Balance below minimum
		{
			cout << "The withdrawal will go below the minimum balance allowed." << endl;

			
			
			//If so, it checks to see if the balance will go below zero after the withdraw and the service charge is applied.  
			//Should this occur an error is reported.  
			if ((balance - withdrawAmount) < 0)
				//THIRD If branch: Balance WILL go below zero, Balance below minimum, 
						
			{

				cout << "There is not enough money in the checking account." << endl;
				cout << "A service charge will be applied to the checking account." << endl;

				balance -= serviceCharge;

				return;

			}
			else

				//If not, the balance is adjusted to reflect the withdraw and the service charge applied.
				//THIRD else branch: Balance will NOT go below zero, Balance below minimum,
			{

				balance -= withdrawAmount;
				balance -= serviceCharge;
				return;
			} //end THIRD else



		}
		else
			// SECOND else branch: Balance will NOT go below zero, Balance ABOVE minimum
		{
			balance -= withdrawAmount;
			
			return;
		} //end SECOND else



	} //end FIRST else



};




void checkingAccount::createMonthlyStatement()
{
	
	checkingAccount::postInterest(accountNumber);

	balance = balance - fee;

};


#endif
