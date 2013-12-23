#include "ATMAction.h"


ATMAction::ATMAction(string date,int amount,bool aprooved,Account* withrowFrom , Account* depositTo )
{
	static int _id = 1;
	Actionid = _id++;
	Date = date;
	Amount = amount;
	Aprooved = aprooved;
	AccountToWithrowFrom = withrowFrom;
	AccountToDeposit = depositTo;
}

ATMAction::~ATMAction(void)
{
}

int ATMAction::getActionId(void)
{
	return Actionid;
}
