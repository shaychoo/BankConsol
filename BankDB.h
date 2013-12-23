#pragma once
#include "Accounts.h"
#include "Clients.h"
#include "ATMAction.h"
#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

class BankDB
{
private:
    static bool instanceFlag;
    static BankDB *single;
    BankDB();
	map<int, Account*> Accounts;
	map<string, Client*> Clients;

	map<Account*, vector<Client*>> AccountToClients;
	map<Client*, vector<Account*>> ClientToAccounts;

	map<int,ATMAction*> ATMLog;
	void Initialize();

public:
    static BankDB* getDB();
    ~BankDB();

	void insertAccount(int id,Account* account);
	void insertClient(string id,Client* client);
	void insertATMLog(string id,Client* client);

	Account* getAccount(int id);
	Client*  getClient(string id);

	vector<Client*> getClients(Account* account);
	vector<Account*> getAccounts(Client* client);
		
};
enum AccountTypes
{
	Student,
	Private,
	Business
};
	