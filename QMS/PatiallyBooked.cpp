#include"PartiallyBooked.h"

PartiallyBooked::PartiallyBooked() {

}

PartiallyBooked* PartiallyBooked::getIns() {
	if (!obj) {
		obj = new PartiallyBooked();
	}
	return obj;
}

void PartiallyBooked::printStatus() {
	cout << "PartiallyBooked" << endl;
}

string PartiallyBooked::getStatus() {
	return "PartiallyBooked";
}

PartiallyBooked* PartiallyBooked::obj = nullptr;