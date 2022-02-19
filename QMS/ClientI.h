#pragma once
#include "User.h"

class Share;

class ClientI : public User {
public:
	ClientI();
	ClientI(string, string);
	ClientI(string, string, int);
	virtual void print(ostream&) = 0;
	virtual void saveToFile(ofstream&) = 0;
	virtual float generateBill() = 0;
	virtual void makePayment(int) = 0;
	virtual void addShare(Share*) = 0;
	virtual void printBookedShares() = 0;
	virtual ~ClientI();
};