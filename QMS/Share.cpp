#include "Share.h"

Share::Share(int pShareNo, Animal* pAnimal, ClientI* pClient) {
	shareNo = pShareNo;
	animal = pAnimal;
	client = pClient;
	status = Booked::getIns();
}

Share::Share(int pShareNo, Animal* pAnimal, ClientI* pClient, ShareStatus* pStatus) {
	shareNo = pShareNo;
	animal = pAnimal;
	client = pClient;
	status = pStatus;
}
void Share::changeStatus(ShareStatus* pStatus) {
	status = pStatus;
	cout << "Status successfully set to " << status->getStatus() << endl;
}

void Share::print(ostream& out) {
	out << shareNo << " " << animal->getTokenNumber() << " " << client->getUserID() << " " << status->getStatus() << endl;
}

void Share::printDetailed() {
	cout << animal->getTokenNumber() << " " << shareNo << " " << status->getStatus() << " " << animal->getSharePrice() << endl;
}

float Share::getSharePrice() {
	return animal->getSharePrice();
}

Share::~Share() {
	animal = nullptr;
	client = nullptr;
	shareNo = 0;
}