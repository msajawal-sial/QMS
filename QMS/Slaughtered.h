#include "AnimalStatus.h"
#pragma once

class Slaughtered : public AnimalStatus {
private:
	static Slaughtered* obj;
	Slaughtered();
public:
	static Slaughtered* getIns();
	 void printStatus();
	 string getStatus();
};

