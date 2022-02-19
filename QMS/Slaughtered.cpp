#include"Slaughtered.h"

Slaughtered::Slaughtered() {

}

Slaughtered* Slaughtered::getIns() {
	if (!obj) {
		obj = new Slaughtered();
	}
	return obj;
}

void Slaughtered::printStatus() {
	cout << "Slaughtered" << endl;
}

string Slaughtered::getStatus() {
	return "Slaughtered";
}

Slaughtered* Slaughtered::obj = nullptr;