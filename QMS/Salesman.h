#pragma once
#include "StaffMemberType.h"

class Salesman :public StaffMemberType {
private:
	static Salesman* obj;
	Salesman();
public:	
	static Salesman* getIns();
	virtual void printType();
	virtual string getType();
};
