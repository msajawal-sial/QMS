#include"FullyBooked.h"

FullyBooked::FullyBooked() {

}

FullyBooked* FullyBooked::getIns() {
	if (!obj) {
		obj = new FullyBooked();
	}
	return obj;
}

void FullyBooked::printStatus() {
	cout << "FullyBooked" << endl;
}

string FullyBooked::getStatus() {
	return "FullyBooked";
}

FullyBooked* FullyBooked::obj = nullptr;