#include"Delievered.h"

Delievered::Delievered() {

}

Delievered* Delievered::getIns() {
	if (!obj) {
		obj = new Delievered();
	}
	return obj;
}

void Delievered::printStatus() {
	cout << "Delievered" << endl;
}

string Delievered::getStatus() {
	return "Delievered";
}

Delievered* Delievered::obj = nullptr;