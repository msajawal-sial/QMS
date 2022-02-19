#include "Salesman.h"

Salesman::Salesman() {

}

Salesman* Salesman::getIns() {
	if (!obj) {
		obj = new Salesman();
	}
	return obj;
}

void Salesman::printType() {
	cout << "Salesman" << endl;
}

string Salesman::getType() {
	return "Salesman";
}


Salesman* Salesman::obj = nullptr;
