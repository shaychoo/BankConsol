#include "BankController.h"
#include <msclr\marshal_cppstd.h>


BankController::BankController(void)
{
	//get Database singel instence
	BankDB = BankDB::getDB();
	Atm = new ATMInterface();
	Teller = new TellerInterface();
	Manager = new ManagerInterface();
}

BankController::~BankController(void)
{
}

std::string BankController::convertToString(System::String^ managedString)
{
	msclr::interop::marshal_context context;
    std::string standardString = context.marshal_as<std::string>(managedString);
	return standardString;
}

vector<string> BankController::GetClientDetails(string ClientId)
{
	vector<string> result;
	//result = teller.get..
	return result;
}

void BankController::SetBankInterfaceType(enum BankInterfaceType nextBankInterfaceType)
{
	bankInterfaceType=nextBankInterfaceType;
}
enum BankInterfaceType BankController::GetBankInterfaceType()
{
	return bankInterfaceType;
}

vector<int> BankController::GetAccounts(std::string ClientId)
{
	return Teller->GetAccountsIdsByClient(ClientId);
}