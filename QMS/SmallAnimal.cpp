#include"SmallAnimal.h"
#include "Share.h"

#pragma once

SmallAnimal::SmallAnimal() :Animal() {
	share = nullptr;
}

SmallAnimal::SmallAnimal( int tokenNo, float weight, float price, bool onDisplay,AnimalStatus* status) : Animal(tokenNo, weight, price, onDisplay,status) {
	share = nullptr;
}
SmallAnimal::SmallAnimal(float weight, float price) : Animal( weight, price) {
	share = nullptr;
	cout << "Small Animal added Successfully" << endl;
}

float SmallAnimal::getSharePrice() {
	float price = Animal::getPrice();
	return price;
}
void SmallAnimal::print(ostream& out) {
	Animal::print(out);
	out << "\nType:Small" ;

}
string SmallAnimal::getType() {
	return "Small";
}

void SmallAnimal::addShare(Share* obj) {
	if (!share) {
		share = obj;
		this->setAnimalStatus(FullyBooked::getIns());
		setDisplay(false);
	}
}

int SmallAnimal::getNextShareNo() {
	return 1;
}

int SmallAnimal::getNoOfAvailableShares() {
	if (!share) {
		return 1;
	}
	return 0;
}

void SmallAnimal::printShares(ostream& out) {
	if (share) {
		share->print(out);
	}
}

void SmallAnimal::printInListView() {
	Animal::printInListView();
	cout << endl;
}

void SmallAnimal::printDetailedView() {
	Animal::printDetailedView();
	printSlaughterDetails();
}

void SmallAnimal::changeShareStatus(int animalShareNo, ShareStatus* pStatus) {
	if(animalShareNo != 1){
		cout << "Invalid Share Number!" << endl;
		return;
	}
	share->changeStatus(pStatus);
}

SmallAnimal::~SmallAnimal() {
	if (share) {
		delete share;
		share = nullptr;
	}
}
