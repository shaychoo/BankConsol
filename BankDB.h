#pragma once
#include "Accounts.h"
#include "Clients.h"
#include "ATMAction.h"
#include <map>
#include <iostream>
#include <string>
using namespace std;

class BankDB
{
private:
    static bool instanceFlag;
    static BankDB *single;
    BankDB();
	map<int, Account*> Accounts;
	map<string, Client*> Clients;

	map<int,Client**> AccountToClients;
	map<int,Account**> ClientToAccounts;
	map<int,ATMAction*> ATMLog;


public:
    static BankDB* getDB();
    ~BankDB();

	void insertAccount(int id,Account* account);
	void insertClient(string id,Client* client);
	void insertATMLog(string id,Client* client);

	Account* getAccount(int id);
	Client*  getClient(string id);
		
};
enum AccountTypes
{
	Student,
	Private,
	Business
};
	