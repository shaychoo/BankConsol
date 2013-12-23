#include "CreditCard.h"
#include <random>


CreditCard::CreditCard(int creditCardId) : Password(rand()%10000),CreditCardId(creditCardId){}

CreditCard::~CreditCard(void)
{}

bool CreditCard::ComperPassword(int EnterdPassword)
{
	return (EnterdPassword == Password);
}

const int CreditCard::getCreditCardId()
{
	return CreditCardId;
}

const int CreditCard::getPassword()
{
	return Password ;
}
//TODO моощ вийн