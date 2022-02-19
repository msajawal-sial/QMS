#pragma once
#include<iostream>
#include<fstream>
#include"AnimalStatus.h"
#include"Unbooked.h"
#include"PartiallyBooked.h"
#include"FullyBooked.h"
#include"Slaughtered.h"
#include"SlaughterDetails.h"
#include "Delievered.h"
#include "DistributedToPoor.h"

using namespace std;
class Share;

class Animal {
    int tokenNumber;
	float weight;
	float price;
	AnimalStatus* status;
	bool onDisplay;
	SlaughterDetails* slaughterDetails;
	static int uniqueTokenNumber;
public:
	Animal();
	Animal(int token1, float weight1, float price1, bool ondisplay1,AnimalStatus *status1 );
	Animal(float, float);
	void setWeight(float wieght1);
	void setPrice(float price);
	void setDisplay(bool x);
	void setTokenNumber(int t1);
	void setAnimalStatus(AnimalStatus* status1);
	void setSlaughterDetails(int,int,int,int);
	void setSlaughterDetails(SlaughterDetails* s1);
    float getWeight();
	float getPrice();
	bool getDisplay();
	int getTokenNumber();
	virtual void printDetailedView();
	void printSlaughterDetails();
	string getAnimalStatus();
	SlaughterDetails* getSlaughterDetails();
	virtual string getType() = 0;
	virtual float getSharePrice() = 0;
	virtual void  addShare(Share*) = 0;
	virtual int getNextShareNo() = 0;
	virtual int getNoOfAvailableShares() = 0;
	virtual void printShares(ostream&) = 0;
	virtual void print(ostream&);
	virtual void printInListView();
	virtual void changeShareStatus(int,ShareStatus*) = 0;
	virtual ~Animal();
};
