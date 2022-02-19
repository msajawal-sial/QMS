#include"Unbooked.h"

UnBooked::UnBooked() {

}

UnBooked* UnBooked::getIns() {
	if (!obj) {
		obj = new UnBooked();
	}
	return obj;
}

void UnBooked::printStatus() {
	cout << "Unbooked" << endl;
}

string UnBooked::getStatus() {
	return "Unbooked";
}

UnBooked* UnBooked::obj = nullptr;