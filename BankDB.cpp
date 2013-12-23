#include "BankDB.h"

bool BankDB::instanceFlag = false;
BankDB* BankDB::single = NULL;

// Bank databse constructor
BankDB::BankDB(void) 
{
	Initialize();
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

vector<Client*> BankDB::getClients(Account* account)
{
	vector<Client*> result = AccountToClients.find(account)->second;
	return result;
}

vector<Account*> BankDB::getAccounts(Client* client)
{
	vector<Account*> result = ClientToAccounts.find(client)->second;
	return result;
}


void BankDB::Initialize()
{
	Client* c1 = new GoldClient("200779072","Shay Trjmn","04/10/88","0548015226","La La Land 56");
	Client* c2 = new GoldClient("435645645","Bibi Netanyaho","04/03/68","0548015226","La La Land 56");
	Client* c3 = new RegularClient("432546455","Micle Jecson","04/10/88","0548015226","La La Land 56");
	Client* c4 = new RegularClient("564547743","Dr.Dolitel","04/10/88","0548015226","La La Land 56");
	Client* c5 = new PlatinumClient("987453242","Moshe Ofnic","04/10/88","0548015226","La La Land 56");
	Client* c6 = new PlatinumClient("533745633","Didi hararri","04/10/88","0548015226","La La Land 56");
	Clients.insert(std::pair<string,Client*>(c1->getId(),c1));
	Clients.insert(std::pair<string,Client*>(c2->getId(),c2));
	Clients.insert(std::pair<string,Client*>(c3->getId(),c3));
	Clients.insert(std::pair<string,Client*>(c4->getId(),c4));
	Clients.insert(std::pair<string,Client*>(c5->getId(),c5));
	Clients.insert(std::pair<string,Client*>(c6->getId(),c6));
	
	Account* a1 = new PrivateAccount();
	Account* a2 = new PrivateAccount();
	Account* a3 = new StudentAccount();
	Account* a4 = new StudentAccount();
	Account* a5 = new BusinessAccount();
	Account* a6 = new BusinessAccount();
	Accounts.insert(std::pair<int,Account*>(a1->getAccountId(),a1));
	Accounts.insert(std::pair<int,Account*>(a2->getAccountId(),a2));
	Accounts.insert(std::pair<int,Account*>(a3->getAccountId(),a3));
	Accounts.insert(std::pair<int,Account*>(a4->getAccountId(),a4));
	Accounts.insert(std::pair<int,Account*>(a5->getAccountId(),a5));
	Accounts.insert(std::pair<int,Account*>(a6->getAccountId(),a6));

	vector<Account*> av1;
	av1.push_back(a1);
	av1.push_back(a2);
	av1.push_back(a3);
	ClientToAccounts.insert(std::pair<Client*, vector<Account*>>(c1,av1));

	vector<Account*> av2;
	av2.push_back(a1);
	av2.push_back(a3);
	av2.push_back(a5);
	ClientToAccounts.insert(std::pair<Client*, vector<Account*>>(c2,av2));

	vector<Account*> av3;
	av3.push_back(a4);
	av3.push_back(a5);
	av3.push_back(a6);
	ClientToAccounts.insert(std::pair<Client*, vector<Account*>>(c3,av3));

	vector<Account*> av4;
	av4.push_back(a2);
	av4.push_back(a4);
	av4.push_back(a6);
	ClientToAccounts.insert(std::pair<Client*, vector<Account*>>(c4,av4));
		
	vector<Account*> av5;
	av5.push_back(a1);
	av5.push_back(a6);
	ClientToAccounts.insert(std::pair<Client*, vector<Account*>>(c5,av5));

	vector<Account*> av6;
	av6.push_back(a6);
	ClientToAccounts.insert(std::pair<Client*, vector<Account*>>(c6,av6));

	vector<Client*> cv1;
	cv1.push_back(c1);
	cv1.push_back(c2);
	AccountToClients.insert(std::pair<Account*, vector<Client*>>(a1,cv1));

	vector<Client*> cv2;
	cv2.push_back(c3);
	cv2.push_back(c4);
	AccountToClients.insert(std::pair<Account*, vector<Client*>>(a2,cv2));
		
	vector<Client*> cv3;
	cv3.push_back(c5);
	cv3.push_back(c6);
	AccountToClients.insert(std::pair<Account*, vector<Client*>>(a3,cv3));

	vector<Client*> cv4;
	cv4.push_back(c1);
	cv4.push_back(c3);
	AccountToClients.insert(std::pair<Account*, vector<Client*>>(a4,cv4));

	vector<Client*> cv5;
	cv5.push_back(c5);
	AccountToClients.insert(std::pair<Account*, vector<Client*>>(a5,cv5));

	vector<Client*> cv6;
	cv6.push_back(c6);
	AccountToClients.insert(std::pair<Account*, vector<Client*>>(a6,cv6));
}
