#include "StaffMemberType.h"
#pragma once

class Admin : public StaffMemberType{
private:
	static Admin* obj;
	Admin();
public:
	static Admin* getIns();
	virtual void printType();
	virtual string getType();
};
