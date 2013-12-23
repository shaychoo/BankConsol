#include "Client.h"

Client::Client(string id, string Name, string birthDate, string phoneNumber,string address)
:Id(id),FullName(Name),BirthDate(birthDate),PhoneNumber(phoneNumber),Address(address)
{
	
}

string Client::getId()				{ return Id;}
string Client::getName()			{ return FullName;}
string Client::getBirthDate()		{ return BirthDate;}
string Client::getPhoneNumber()		{ return PhoneNumber;}
string Client::getAddress()			{ return Address;}
double Client::getTotalBalance()    { return TotalBalance;}


