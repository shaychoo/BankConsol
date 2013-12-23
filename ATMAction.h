#pragma once
#include <iostream>
#include <map>
#include "Accounts.h"
using namespace std;

class ATMAction
{
public:
	ATMAction(string date,int amaount,bool Aprooved,Account* WithrowFrom = 0, Account* DepositTo = 0);
	~ATMAction(void);
	void AddToLog(int Actionid,ATMAction* Action);
	void AprooveAction(int Actionid);
	int getActionId(void);

private:
	int Actionid;
	string Date;
	Account* AccountToWithrowFrom;
	Account* AccountToDeposit;
	int Amount;
	bool Aprooved;

};

