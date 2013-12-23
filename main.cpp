#include <iostream>
#include "Accounts.h"
#include "Clients.h"
#include "ATMInterface.h"
#include "ATMAction.h"
#include "BankDB.h"

void main(void)
{
	BankDB* db;
		db = BankDB::getDB();

	Client* c1 = new Client("200779072","Shay Trjmn","04/10/88","0548015226","La La Land 56");
	Client* c2 = new Client("435645645","Bibi Netanyaho","04/03/68","0548015226","La La Land 56");
	Client* c3 = new Client("432546455","Micle Jecson","04/10/88","0548015226","La La Land 56");
	Client* c4 = new Client("564547743","Dr.Dolitel","04/10/88","0548015226","La La Land 56");
	Client* c5 = new Client("987453242","Moshe Ofnic","04/10/88","0548015226","La La Land 56");
	Client* c6 = new Client("533745633","Didi hararri","04/10/88","0548015226","La La Land 56");

	Account* a1 = new BusinessAccount();
	Account* a2 = new BusinessAccount();
	Account* a3 = new StudentAccount();
	Account* a4 = new StudentAccount();
	ATMInterface* at1 = new ATMInterface();
	
	
		a1->Deposit(20000);
		at1->Deposit(120,a1);
		at1->Deposit(120,a1);
		at1->Deposit(120,a1);
		at1->Withdraw(20,a1);
		at1->Withdraw(100,a1);
		at1->Withdraw(100,a1);
		at1->Withdraw(100,a1);
		at1->Withdraw(100,a1);
		at1->Withdraw(100,a1);
	
		ATMAction* log1 = new ATMAction("1/1/10",100,false,NULL,a1);
		ATMAction* log2 = new ATMAction("1/1/10",100,false,NULL,a1);
		ATMAction* log3 = new ATMAction("1/1/10",200000,false,NULL,a2);

		
		db->insertAccount(1,a1);
		db->insertAccount(1,a1);
		db->insertAccount(1,a1);

}
