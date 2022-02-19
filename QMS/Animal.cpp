#include"Animal.h"
Animal::Animal()  {
	tokenNumber= uniqueTokenNumber;
	weight = 0;
	price = 0;
	onDisplay = true;
	status = UnBooked::getIns();
	uniqueTokenNumber++;
	slaughterDetails = nullptr;
}

Animal::Animal(int token1, float weight1, float price1, bool ondisplay1,AnimalStatus* status1) {
	tokenNumber = token1;
	weight = weight1;
    price = price1;
	onDisplay = ondisplay1;
	status = status1;
	slaughterDetails = nullptr;

	if (tokenNumber >= uniqueTokenNumber) {
		uniqueTokenNumber = tokenNumber + 1;
	}
}

Animal::Animal(float weight1, float price1) {
	tokenNumber = uniqueTokenNumber;
	weight = weight1;
	price = price1;
	onDisplay = true;
	status = UnBooked::getIns();
	uniqueTokenNumber++;
	slaughterDetails = nullptr;

}

void Animal::setWeight(float weight1) {
	weight = weight1;
}

void Animal::setTokenNumber(int t1) {
	tokenNumber = t1;
}

int Animal::getTokenNumber(){
	return tokenNumber;
}

void Animal::setPrice(float price1) {
	price = price1;
}

void Animal::setDisplay(bool x) {
	onDisplay = x;
}

float Animal::getWeight() {
	return weight;
}



float Animal::getPrice() {
	return price;
}

bool Animal::getDisplay() {
	return onDisplay;
}


string Animal:: getAnimalStatus() {
	return status->getStatus();
 }

void Animal::setAnimalStatus(AnimalStatus* status1) {
	status = status1;
}
void Animal::setSlaughterDetails(int day,int hour,int minute,int second) {
	slaughterDetails = new SlaughterDetails(day, hour, minute, second);
}

void Animal::setSlaughterDetails(SlaughterDetails* s1) {
	slaughterDetails = s1;
}

void Animal::printDetailedView() {
	cout << "Token No: " << tokenNumber << endl;
	cout << "Price: " << price << endl;
	cout << "Weight: " << weight << endl;
	cout << "Status: " << status->getStatus();
	cout << endl;

}

void Animal::printSlaughterDetails() {
	if (slaughterDetails) {
		cout << "Slaughter Details:" << endl;
		slaughterDetails->printDetailedView();
	}

}

SlaughterDetails* Animal::getSlaughterDetails() {
	return slaughterDetails;
}

void Animal::print(ostream& out) {
	out << "\nToken Number:" << tokenNumber << "\nPrice:" << price << "\nWeight:" << weight;
	out << "\nonDisplay:" << onDisplay;
	if (status != nullptr) {
		out << "\nStatus:" << status->getStatus();
	}
}

void Animal::printInListView() {
	cout << tokenNumber << " " << price << " " << " " << status->getStatus() << " ";
}

Animal::~Animal() {
	if(slaughterDetails){
		delete slaughterDetails;
		slaughterDetails = nullptr;
	}
	tokenNumber = 0;
	weight = price = 0;
	status = nullptr;
}

int Animal::uniqueTokenNumber = 1;