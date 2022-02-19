#include"DistributedToPoor.h"

DistributedToPoor::DistributedToPoor() {

}

DistributedToPoor* DistributedToPoor::getIns() {
	if (!obj) {
		obj = new DistributedToPoor();
	}
	return obj;
}

void DistributedToPoor::printStatus() {
	cout << "DistributedToPoor" << endl;
}

string DistributedToPoor::getStatus() {
	return "DistributedToPoor";
}

DistributedToPoor* DistributedToPoor::obj = nullptr;