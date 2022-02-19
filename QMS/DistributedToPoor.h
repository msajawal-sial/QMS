#include "ShareStatus.h"
#pragma once

class DistributedToPoor : public ShareStatus {
private:
	static DistributedToPoor* obj;
	DistributedToPoor();
public:
	static DistributedToPoor* getIns();
	virtual void printStatus();
	virtual string getStatus();
};
