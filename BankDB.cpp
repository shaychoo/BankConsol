#include "BankDB.h"

bool BankDB::instanceFlag = false;
BankDB* BankDB::single = NULL;

// Bank databse constructor
BankDB::BankDB(void) 
{

}

//Deconstructor 
BankDB::~BankDB(void)
{
	instanceFlag = false;
}

void BankDB::insertAccount(int id,Account* account)
{
	Accounts.insert(std::pair<int,Account*>(id,account));
}

void BankDB::insertClient(string id,Client* client)
{
	Clients.insert(std::pair<string,Client*>(id,client));
}

Account* BankDB::getAccount(int id)
{
	return Accounts.find(id)->second;
}

Client* BankDB::getClient(string id)
{
	return Clients.find(id)->second;
}


BankDB* BankDB::getDB()
{
    if(! instanceFlag)
    {
        single = new BankDB();
        instanceFlag = true;
        return single;
    }
    else
    {
        return single;
    }
}


