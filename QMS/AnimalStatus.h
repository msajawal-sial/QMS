#pragma once
class Staff;
#include <iostream>
using namespace std;

class AnimalStatus {
public:
	virtual void printStatus() = 0;
	virtual string getStatus() = 0;
};
