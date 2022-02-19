#pragma once
class Staff;
#include <iostream>
using namespace std;

class StaffMemberType {
public:
	virtual void printType() = 0;
	virtual string getType() = 0;
};