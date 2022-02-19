#pragma once
#include"Animal.h"

class BigAnimal : public Animal {
private:
	static const int NO_OF_SHARES = 7;
	int noOfAvailableShares;
	Share* shares[NO_OF_SHARES];
public:
	BigAnimal();
	BigAnimal( int, float, float, bool, AnimalStatus*);
	BigAnimal( float, float);
	string getType();
	virtual float getSharePrice();
	void setNoOfAvailableShares(int s);
	virtual int getNoOfAvailableShares();
	virtual void addShare(Share*);
	virtual int getNextShareNo();
	virtual void printShares(ostream&);
	virtual void print(ostream&);
	virtual void printInListView();
	virtual void printDetailedView();
	virtual void changeShareStatus(int,ShareStatus*);
	virtual ~BigAnimal();
};