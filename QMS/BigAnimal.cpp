#include"BigAnimal.h"
#include "Share.h"
#pragma once

BigAnimal::BigAnimal() :Animal() {
	noOfAvailableShares = NO_OF_SHARES;
	for (int i = 0; i < NO_OF_SHARES; i++) {
		shares[i] = nullptr;
	}
}

BigAnimal::BigAnimal(int tokenNo, float weight, float price, bool onDisplay,AnimalStatus *status) : Animal(tokenNo,weight,price,onDisplay,status) {
	noOfAvailableShares = NO_OF_SHARES;
	for (int i = 0; i < NO_OF_SHARES; i++) {
		shares[i] = nullptr;
	}
}

BigAnimal::BigAnimal( float weight, float price) : Animal( weight, price) {
	noOfAvailableShares = NO_OF_SHARES;
	for (int i = 0; i < NO_OF_SHARES; i++) {
		shares[i] = nullptr;
	}
	cout << "Big Animal added successfully!" << endl;
}

void BigAnimal::changeShareStatus(int animalShareNo,ShareStatus* pStatus) {
	if ((animalShareNo < 1) || (animalShareNo) > (NO_OF_SHARES - noOfAvailableShares)) {
		cout << "Invalid Share No!" << endl;
		return;
	}
	shares[animalShareNo-1]->changeStatus(pStatus);
}

float BigAnimal::getSharePrice() {
	float price = Animal::getPrice();
	return price/NO_OF_SHARES;
}

string BigAnimal::getType() {
	return "Big";
}

void BigAnimal:: addShare(Share* obj) {
	if (noOfAvailableShares > 0) {
		shares[NO_OF_SHARES - noOfAvailableShares] = obj;
		noOfAvailableShares--;
	}
	if (noOfAvailableShares == (NO_OF_SHARES - 1)) {
		this->setAnimalStatus(PartiallyBooked::getIns());
	}
	if (noOfAvailableShares == 0) {
		this->setAnimalStatus(FullyBooked::getIns());
		setDisplay(false);
	}
}

int BigAnimal::getNextShareNo() {
	return ((NO_OF_SHARES - noOfAvailableShares) + 1);
}


void BigAnimal:: print(ostream& out) {
	Animal::print(out);
	out << "\nType:Big \nNo_Of_Shares_Available:"<<noOfAvailableShares;
	
}

void BigAnimal::setNoOfAvailableShares(int s) {
	noOfAvailableShares = s;
}
int BigAnimal::getNoOfAvailableShares() {
	return noOfAvailableShares;
}

void BigAnimal::printShares(ostream& out) {
	for (int i = 0; i < (NO_OF_SHARES - noOfAvailableShares); i++) {
		shares[i]->print(out);
	}
}

void BigAnimal::printInListView() {
	Animal::printInListView();
	cout <<"("<< noOfAvailableShares<<")" << endl;
}

void BigAnimal::printDetailedView() {
	Animal::printDetailedView();
	cout << "No of Shares Available: " << noOfAvailableShares << endl;
	printSlaughterDetails();
}


BigAnimal::~BigAnimal() {
	for (int i = 0; i < (NO_OF_SHARES - noOfAvailableShares); i++) {
		delete shares[i];
			shares[i] = nullptr;
	}

}

