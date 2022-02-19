#include"Animal.h"
#pragma once
class Share;

class SmallAnimal : public Animal {
private:
	Share* share;
public:
	SmallAnimal();
	SmallAnimal(int, float,float, bool,AnimalStatus*);
	SmallAnimal(float, float);
	string getType();
	virtual float getSharePrice();
	void addShare(Share*);
	virtual int getNextShareNo();
	virtual int getNoOfAvailableShares();
	void print(ostream&);
	void printShares(ostream&);
	void printInListView();
	virtual void printDetailedView();
	virtual void changeShareStatus(int, ShareStatus*);
	virtual ~SmallAnimal();
};