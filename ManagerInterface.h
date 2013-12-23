#pragma once
#include "Tellerinterface.h"
class ManagerInterface :
	public TellerInterface
{
public:
	ManagerInterface(void);
	~ManagerInterface(void);
	void getOverdaftLog(void);
	void RemoveClientFromAccount(void);
};

