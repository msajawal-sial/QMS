#pragma once
#include "ClientI.h"
#include <list>

class Client : public ClientI {
private:
	list<Share*> shares;
	int amountPaid;
public:
	Client();
	Client(string, string, int);
	Client(string, string, int, int);
	virtual void print(ostream&);
	virtual void saveToFile(ofstream&);
	virtual string getUserType();
	virtual void makePayment(int);
	virtual void addShare(Share*);
	virtual void printBookedShares();
	virtual float generateBill();
	virtual ~Client();
};