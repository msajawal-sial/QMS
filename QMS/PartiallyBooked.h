#include "AnimalStatus.h"
#pragma once

class PartiallyBooked : public AnimalStatus {
private:
	static PartiallyBooked* obj;
	PartiallyBooked();
public:
	static PartiallyBooked* getIns();
	 void printStatus();
	 string getStatus();
};

