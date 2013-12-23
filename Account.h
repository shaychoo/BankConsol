#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include "CreditCard.h"


using namespace std;

class Account
{
public:
	Account(float LineCommission,int MaxCredit);
	~Account();
	bool isAccountActive();
	int getAccountId(void);
	void Deposit(int Amuont);
	void Withdrow(int Amuont);
	double getBalance();
	void Transfer(Account* TransferToAccountId,int Amount);
	bool IsAccountActive(void);
	void CloseAccount(void);



protected:
    const int Credit;  // Minimum Balace avilable 
	const string OpeningDate;
	const float LineCommission;
    CreditCard* creditCard; 

private:
    int Id;
    double Balance;
    bool IsActive;
	void setNewCreditCard(int Password);
	void setBalance(double);


};

#endif // ACCOUNT_H
