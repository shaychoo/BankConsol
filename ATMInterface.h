#pragma once
#include "BankInterface.h"
#include "ATMAction.h"
#include <map>
class ATMInterface :
	public BankInterface
{
public:
	ATMInterface(void);
	~ATMInterface(void);
	
	void RefillATM(void);
	void DrowMoney(int Amount);
	
	void Withdraw(int Amount,Account* AccountId);
	void Deposit (int Amount,Account*  AccountId);
	int WatchBalance(Account*  AccountId);
	void Transfer(Account*  TransferFromAccountId , Account*  TransferToAccountId , int Amount);
	
private:
	int Amount100;
	int Amount50;
	int Amount20;
	int getATMTotalAmount();
	map<int,ATMAction*> ATMLog;
	void ATMLogAction(string date,int amount,bool aprooval,Account* TransferFromAccountId,Account* TransferToAccountId );

};

