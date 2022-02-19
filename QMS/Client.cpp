#include "Client.h"
#include "Share.h"

Client::Client():ClientI() {
	amountPaid = 0;
}

Client::Client(string name, string phoneNumber, int uAmountPaid):ClientI(name,phoneNumber) {
	amountPaid = uAmountPaid;
}

Client::Client(string name, string phoneNumber, int uID, int uAmountPaid) : ClientI(name, phoneNumber,uID) {
	amountPaid = uAmountPaid;
}

void Client::printBookedShares() {
	list<Share*>::iterator looper;
	for (looper = shares.begin(); looper != shares.end(); looper++) {
		(*looper)->printDetailed();
	}
}

void Client::print(ostream & out) {
	User::print(out);
	out << amountPaid << endl;
}

void Client::saveToFile(ofstream& fout) {
	User::saveToFile(fout);
	if (fout.good()) {
		fout.write((char*)&amountPaid, sizeof(amountPaid));
	}
}

string Client::getUserType() {
	return "Client";
}

void Client::makePayment(int payment) {
	amountPaid = amountPaid + payment;
}

void Client::addShare(Share* obj) {
	shares.push_back(obj);
}

float Client::generateBill() {
	float sum = 0;
	list<Share*>::iterator looper;
	for (looper = shares.begin(); looper != shares.end(); looper++) {
		sum += (*looper)->getSharePrice();
	}
	return sum;
}

Client::~Client() {
	amountPaid = 0;
	//cout << "~Client();" << endl;
}