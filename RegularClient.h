#pragma once
#include "Client.h"
class RegularClient :
	public Client
{
public:
	RegularClient(string id, string Name, string birthDate, string PhoneNumber,string Address);
	~RegularClient(void);
};

