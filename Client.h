#ifndef CLIENTS_H
#define CLIENTS_H
#include <iostream>

using namespace std;
class Client
{
public:
	Client(string id, string name, string birthDate, string phoneNumber,string address);
    string getId();
    string getName();
    string getBirthDate();
    string getPhoneNumber();
    string getAddress();
	double getTotalBalance();
	

private:
    const string Id;
    string FullName;
    string BirthDate;
    string PhoneNumber;
    string Address;
    double TotalBalance;


};




#endif // CLIENTS_H
