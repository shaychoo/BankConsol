#ifndef GOLDCLIENT_H
#define GOLDCLIENT_H
#include "client.h"

class GoldClient : public Client
{
public:
    GoldClient(string id, string Name, string birthDate, string PhoneNumber,string Address);
	~GoldClient();
};

#endif // GOLDCLIENT_H
