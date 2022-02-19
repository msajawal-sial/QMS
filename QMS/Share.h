#pragma once
#include "Animal.h"
#include "ClientI.h"
#include "Booked.h"
#include "Delievered.h"
#include "DistributedToPoor.h"


class Share {
private:
	int shareNo;
	Animal* animal;
	ClientI* client;	
	ShareStatus* status;
public:
	Share(int, Animal*, ClientI*);
	Share(int, Animal*, ClientI*, ShareStatus*);
	void changeStatus(ShareStatus*);
	void print(ostream&);
	void printDetailed();
	float getSharePrice();
	~Share();
};