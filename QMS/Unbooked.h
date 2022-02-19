#include "AnimalStatus.h"
#pragma once

class UnBooked : public AnimalStatus {
private:
	static UnBooked* obj;
	UnBooked();
public:
	static UnBooked* getIns();
	 void printStatus();
	 string getStatus();
};
