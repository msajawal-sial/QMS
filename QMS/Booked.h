#include "ShareStatus.h"
#pragma once

class Booked : public ShareStatus {
private:
	static Booked* obj;
	Booked();
public:
	static Booked* getIns();
	virtual void printStatus();
	virtual string getStatus();
};

