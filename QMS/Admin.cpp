#include "Admin.h"

Admin::Admin() {

}

Admin* Admin::getIns() {
	if (!obj) {
		obj = new Admin();
	}
	return obj;
}

void Admin::printType() {
	cout << "Admin" << endl;
}

string Admin::getType() {
	return "Admin";
}

Admin* Admin::obj = nullptr;

