#pragma once
#include "Account.h"
#include "BankDB.h"
#include "ExpMsg.h"
class BankInterface
{
public:
	BankInterface(void);
	~BankInterface(void);

	//TODO return Bool? or Exeption?
	virtual void Withdraw(int Amount,Account* AccountId);
	virtual void Deposit (int Amount,Account*  AccountId);
	virtual int WatchBalance(Account*  AccountId);
	virtual void Transfer(Account*  TransferFromAccountId , Account*  TransferToAccountId , int Amount);
};

