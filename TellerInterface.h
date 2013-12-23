#pragma once
#include <vector>
#include "BankInterface.h"
#include "ATMInterface.h"
#include "Accounts.h"
#include "Clients.h"
#include "BankDB.h"


class TellerInterface :
	public BankInterface
{
public:
	TellerInterface(void);
	~TellerInterface(void);
	void CreateNewClient(string*); //
	void UpdateClientDeatils(void);
	void RefillATM(ATMInterface* ATM); // OK
	void ATMLogView(void);
	void AprooveATMActions(void);
	void AddNewAccount(enum AccountTypes AccountType, Client* client);
	void ReturnAccountDeatils(void);
	void AddClientToAccount(void);
	void CloseAccount(Account* account);// OK
private:
	BankDB* bankDB;

};

