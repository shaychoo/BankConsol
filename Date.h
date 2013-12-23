#pragma once
#include <iostream>

using namespace std;
class Date
{
public:
	Date(string);
	Date (void);
	~Date(void);
	void setDate(string date);
	string getDate(void);
	string getTodaysDate(void);
private:
	string date;
};

