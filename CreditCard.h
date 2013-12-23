#pragma once
class CreditCard
{
public:
	CreditCard(int);
	CreditCard();
	~CreditCard(void);
	bool ComperPassword(int);
	const int getCreditCardId(void);
	const int getPassword(void); 
	

private:
	const int CreditCardId;
	const int Password;
	
};

