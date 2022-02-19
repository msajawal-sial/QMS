#include "AnimalStatus.h"
#pragma once

class FullyBooked : public AnimalStatus {
private:
	static FullyBooked* obj;
	FullyBooked();
public:
	static FullyBooked* getIns();
	 void printStatus();
	 string getStatus();
};


