#include"Booked.h"

Booked::Booked() {

}

Booked* Booked::getIns() {
	if (!obj) {
		obj = new Booked();
	}
	return obj;
}

void Booked::printStatus() {
	cout << "Booked" << endl;
}

string Booked::getStatus() {
	return "Booked";
}

Booked* Booked::obj = nullptr;