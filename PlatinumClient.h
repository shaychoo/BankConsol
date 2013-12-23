#pragma once
#include "client.h"
class PlatinumClient :
	public Client
{
public:
	PlatinumClient(string id, string Name, string birthDate, string PhoneNumber,string Address);
	~PlatinumClient(void);
};

