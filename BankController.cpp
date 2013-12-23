
#include "BankController.h"


BankController::BankController(void)
{
	//get Database singel instence
	BankDB = BankDB::getDB();
}


BankController::~BankController(void)
{
}
