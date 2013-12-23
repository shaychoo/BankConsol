#pragma once
#include <map>
#include <iostream>

#include "Accounts.h"			// Load all account types
#include "Clients.h"			// Load all client types
#include "BankInterface.h"		// Abstract type interface
#include "ATMInterface.h"		// ATM interface
#include "BankDB.h"				// Load bank database class

using namespace std;

class BankController
{
public:
	BankController(void);
	~BankController(void);

	Account* GetAcountById(int id);
	Client* GetClientById(string id);
	
	Account* getCurrentWorkingAccount();
	Client* getCurrentWorkingClient();
	void ClearCurrentWorkingAccount();
	void ClearCurrentWorkingClient();
	void VerifyCreditCard(int CreditCardId,int Password);// uptdate Working Pointer
	void VerifyClient(string ClientId); // uptdate Working Pointer


///////// GUI Functions

	string GetAccountName(int id);
	string GetAccountBalance(int id);
	string GetBallance(int accountId = 0);
	void TransferMoney(int amount,int transferToAccount,int transferFromAccountId = 0);
	void Deposit(int amount,string cashOrCheck,int accountId = 0 );
	void Withdrow(int amount,int accountId = 0);
	string* GetClientDetails(string ClientId = "");
	int* GetAccounts(string ClientId = "");
	void UpdateClientDetails(string* Details);
	void CloseAccount(int accountId = 0 );




private:
	Account* CurrentWorkingAccount;
	Client*  CurrentWorkingClient;
	BankDB* BankDB;
	


};

