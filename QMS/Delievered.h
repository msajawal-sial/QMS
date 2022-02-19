#include "ShareStatus.h"
#pragma once

class Delievered : public ShareStatus {
private:
	static Delievered* obj;
	Delievered();
public:
	static Delievered* getIns();
	virtual void printStatus();
	virtual string getStatus();
};
