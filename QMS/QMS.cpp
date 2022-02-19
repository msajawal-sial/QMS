#include "QMS.h"
#include <iomanip>
#include "Share.h"
#include <stdlib.h>

QMS* QMS::getIns() {//Application of the Singleton pattern
	if (!obj) {
		obj = new QMS();
	}
	return obj;
}

QMS::QMS() {
	clients.clear();
	staff.clear();
	animals.clear();
}

void QMS::addClient(ClientI* client) {
	clients.push_back(client);
}

void QMS::addStaff(User* pStaff) {
	staff.push_back(pStaff);
}

void QMS::printStaff(ostream& out) {
	list<User*>::iterator looper = staff.begin();
	while (looper != staff.end()) {
		(*looper)->print(out);
		looper++;
	}
}

void QMS::printClients(ostream& out) {
	list<ClientI*>::iterator looper = clients.begin();
	while (looper != clients.end()) {
		(*looper)->print(out);
		looper++;
	}
}

void QMS::saveStaffToFile(ofstream& fout) {
	list<User*>::iterator looper = staff.begin();
	while (looper != staff.end()) {
		(*looper)->saveToFile(fout);
		looper++;
	}
}

void QMS::saveClientsToFile(ofstream& fout) {
	list<ClientI*>::iterator looper = clients.begin();
	while (looper != clients.end()) {
		(*looper)->saveToFile(fout);
		looper++;
	}
}

void QMS::addAnimal(Animal* animal) {
	animals.push_back(animal);
}
void QMS::printAnimals(ostream& out) {

	list<Animal*>::iterator looper = animals.begin();
	while (looper != animals.end()) {
		cout << "\n\n";

		(*looper)->print(out);
		if ((*looper)->getSlaughterDetails() != nullptr) {
			(*looper)->getSlaughterDetails()->print(out);
		}
		looper++;
	}
}

void QMS::printSmallAnimals(ostream& out) {
	list<Animal*>::iterator looper = animals.begin();
	while (looper != animals.end()) {
		if ((*looper)->getType().compare("Small") == 0) {
			(*looper)->print(out);
		}
		looper++;
	}
}

void QMS::printBigAnimals(ostream& out) {
	list<Animal*>::iterator looper = animals.begin();
	while (looper != animals.end()) {
		if ((*looper)->getType().compare("Big") == 0) {
			(*looper)->print(out);
		}
		looper++;
	}
}

void QMS::addAnimalSlaughterDetail(int t, SlaughterDetails* sd) {
	list<Animal*>::iterator looper = animals.begin();
	while (looper != animals.end()) {
		if ((*looper)->getTokenNumber() == t) {
			(*looper)->setSlaughterDetails(sd);
		}
		looper++;
	}
}

void QMS::printAnimalSlaughterDetails(ostream& out) {
	list<Animal*>::iterator looper = animals.begin();
	while (looper != animals.end()) {
		if ((*looper)->getSlaughterDetails() != nullptr) {
			out << "\nTokenNumber:" << (*looper)->getTokenNumber();
			(*looper)->getSlaughterDetails()->print(out);
		}
		looper++;
	}
}

void QMS::printShares(ostream& out) {
	list<Animal*>::iterator looper = animals.begin();
	while (looper != animals.end()) {
		(*looper)->printShares(out);
		looper++;
	}
}


void QMS::bookShare() {
	int animalTokenNo = 0, clientID = 0, noOfShares = 0;

	Animal* animal = nullptr;
	ClientI* client = nullptr;

	cout << "Enter Token Number: ";
	cin >> animalTokenNo;
	list<Animal*>::iterator looper;
	for (looper = animals.begin(); looper != animals.end(); looper++) {
		if ((*looper)->getTokenNumber() == animalTokenNo) {
			animal = *looper;
			break;
		}
	}
	if (!animal) {
		cout << "Invalid Token Number" << endl;
		return;
	}

	cout << "Enter Client ID: ";
	cin >> clientID;
	list<ClientI*>::iterator looperC;
	for (looperC = clients.begin(); looperC != clients.end(); looperC++) {
		if ((*looperC)->getUserID() == clientID) {
			client = *looperC;
			break;
		}
	}
	if (!client) {
		cout << "Invalid Client ID" << endl;
		return;
	}

	if (animal->getType() == "Big") {
		cout << "Enter No of Shares: ";
		cin >> noOfShares;
	}
	else {
		noOfShares = 1;
	}
	
	if (noOfShares > animal->getNoOfAvailableShares()) {
		cout << "Shares not Available" << endl;
		return;
	}
	if (!animal->getSlaughterDetails()) {
		int day = 0, hour = 0, minute = 0, second = 0;
		cout << "Please Enter the Following Slaughter Details: " << endl;
		cout << "1. Day Number: ";
		cin >> day;
		cout << "2. Hour: ";
		cin >> hour;
		cout << "3. Minutes ";
		cin >> minute;
		cout << "4. Seconds: ";
		cin >> second;
		animal->setSlaughterDetails(day, hour, minute, second);
	}

	for (int i = 0; i < noOfShares; i++) {
		Share* temp = new Share(animal->getNextShareNo(), animal, client);
		animal->addShare(temp);
		client->addShare(temp);
	}
	cout << "Booking Completed Successfully" << endl;
}

void QMS::bookShare(int shareNo, int tokenNo, int clientID, ShareStatus* status) {
	Animal* animal = nullptr;
	ClientI* client = nullptr;

	list<Animal*>::iterator looper;
	for (looper = animals.begin(); looper != animals.end(); looper++) {
		if ((*looper)->getTokenNumber() == tokenNo) {
			animal = *looper;
			break;
		}
	}

	list<ClientI*>::iterator looperC;
	for (looperC = clients.begin(); looperC != clients.end(); looperC++) {
		if ((*looperC)->getUserID() == clientID) {
			client = *looperC;
			break;
		}
	}

	Share* temp = new Share(shareNo, animal, client,status);
	animal->addShare(temp);
	client->addShare(temp);

}

void QMS::displayLoginScreen(string& uEmail, string& uPass) {
	for (int i = 0; i < 10; i++) {
		cout << endl;
	}
	cout << setw(80);
	cout << "****************************************" << endl;
	cout << setw(76);
	cout<< "Qurbani Management System LOGIN" << endl;
	cout << setw(80);
	cout << "****************************************" << endl;	
	cout << setw(50) << "Email: ";
	getline(cin, uEmail);
	cout << setw(50) << "Pass : ";
	getline(cin, uPass);
}

int QMS::login() {
	string uEmail,uPass;
	displayLoginScreen(uEmail,uPass);
	list<User*>::iterator looper;
	Staff* temp = nullptr;
	for (looper = staff.begin(); looper != staff.end(); looper++) {
		temp = (Staff*)(*looper);
		if (temp->getEmail() == uEmail && temp->getPass() == uPass) {
			cout << "User Type ="<< temp->getUserType() << endl;
			if (temp->getUserType() == "Admin") {
				return 2;
			}
			else {//Salesman
				return 1;
			}
		}

	}
	cout<<setw(67) << "User Not Found!\n";
	return 0;//User Not Found

}

void QMS:: displaySalesmanInterface() {
	cout << "0. Logout" << endl;
	cout << "1. View All Animals" << endl;
	cout << "2. View Available Animals" << endl;
	cout << "3. View an Animal's Details" << endl;
	cout << "4. View Schedule " << endl;
	cout << "5. View all reservations of a customer" << endl;
	cout << "6. Reserve Share for a customer" << endl;
	cout << "7. Change Share Status" << endl;
	cout << "8. Add Client" << endl;
}

void QMS::displayAdminInterface() {
	displaySalesmanInterface();
	cout << "9. Add Animal" << endl;
	cout << "10. Add Salesman" << endl;
	cout << "11. Make a Schedule" << endl;
}

void QMS::session() {
	int loginStatus = login();
	if (loginStatus == 0) {//if User not found, terminate program
		return;
	}
	system("CLS");
	int choice = 1;
	cout << endl;
	if (loginStatus == 1) {
		while (choice != 0) {
			cout << "WELCOME Salesman, what would you like to do Today?" << endl << endl;
			displaySalesmanInterface();
			cout << endl << "Choice: ";
			cin >> choice;
			salesmanUseCases(choice);
			system("pause");

			if (choice != 0) {
				system("CLS");
			}

		}
	}
	if (loginStatus == 2) {
		while (choice != 0) {
			cout << "WELCOME ADMIN, what would you like to do Today?" << endl << endl;
			displayAdminInterface();
			cout <<endl << "Choice: ";
			cin >> choice;

			if ((choice >= 0) && (choice < 9)) {
				salesmanUseCases(choice);
			}
			else {
				adminUseCases(choice);
			}
			system("pause");
			if (choice != 0) {		
				system("CLS");
			}
		}
	}
}

void QMS::salesmanUseCases(int choice) {
	if (choice == 0) {
		cout << "Goodbye!" << endl;
		return;
	}
	if (choice == 1) {//print all Animals
		printAnimalsInListView();
	}
	else if (choice == 2) {//Print Available Animals
		printAvailableAnimalsInListView();
	}
	else if (choice == 3) {//print Animal Details
		int animalTokenNo = 0;
		printLine();
		cout<<"Animal Token No: ";
		cin >> animalTokenNo;
		printAnimal(animalTokenNo);
		printLine();
	}
	else if (choice == 4) {//View Schedule
		viewSchedule();
	}
	else if (choice == 5) {//View Reservations of a Customer
		int clientID = 0;
		printLine();
		cout << "Client ID: ";
		cin >> clientID;
		viewReservationsByCustomer(clientID);
		printLine();
	}
	else if (choice == 6) {//Reserve Share
		printLine();
		bookShare();
		printLine();
	}
	
	else if (choice == 7) {
		int animalTokenNo = 0;
		int animalShareNo = 0;
		int statusC = 0;
		ShareStatus* status = nullptr;
		printLine();
		cout << "Animal Token Number: ";
		cin >> animalTokenNo;
		cout << "Animal Share No: ";
		cin >> animalShareNo;
		cout << "\t1. To Change Status to Delivered" << endl;
		cout << "\t2. To Change Status to DistributedToPoor" << endl;
		cin >> statusC;
		if (statusC < 1 || statusC > 2) {
			cout << "Invalid Input" << endl;
			return;
		}
		if(statusC == 1){
			status = Delievered::getIns();
		}
		if (statusC == 2) {
			status = DistributedToPoor::getIns();
		}
		changeShareStatus(animalTokenNo, animalShareNo,status);

		printLine();
	}
	else if (choice == 8) {
		string name, phoneNumber;
		int amountPaid;
		cin.ignore();
		printLine();
		cout << "Name: ";
		getline(cin, name);
		cout << "Phone Number: ";
		getline(cin, phoneNumber);
		cout << "Amount Paid: ";
		cin >> amountPaid;
		ClientI* client = new Client(name, phoneNumber, amountPaid);
		addClient(client);
		printLine();
	}
} 

void QMS::adminUseCases(int choice) {
	if (choice == 9) {
		float weight = 0, price = 0, animalChoice = 0;
		Animal* animal = nullptr;

		printLine();
		cout << "\t1. Add Small Animal" << endl;
		cout << "\t2. Add Big Animal" << endl;
		cin >> animalChoice;
		cout << "Weight: ";
		cin >> weight;
		cout << "Price: ";
		cin >> price;	
		if (animalChoice < 1 || animalChoice > 2) {
			cout << "Invalid Input!" << endl;
			return;
		}
		if (animalChoice == 1) {
			animal = new SmallAnimal(weight, price);
		}
		if (animalChoice == 2) {
			animal = new BigAnimal(weight, price);
		}
		addAnimal(animal);
		printLine();
	}
	else if (choice == 10) {
		string name, phoneNumber, email, pass;
		printLine();
		cout << "Name: ";
		cin.ignore();
		getline(cin, name);
		cout << "Phone Number: ";
		getline(cin, phoneNumber);
		cout << "Email: ";
		getline(cin, email);
		cout << "Pass: ";
		getline(cin, pass);
		User* salesman = new Staff(name, phoneNumber, email, pass,Salesman::getIns());
		addStaff(salesman);
		printLine();
		cout << "Salesman Created Successfully" << endl;
	}
	else if (choice == 11) {
		printLine();
		int day = 0, hour = 0, minute = 0, second = 0;
		list<Animal*>::iterator looper = animals.begin();
		cout << "Adding Schedule of all Animals without Slaughter Details" << endl;
		while (looper != animals.end()) {
			if (!(*looper)->getSlaughterDetails()) {
				cout << "Slaughter Details for Animal " << (*looper)->getTokenNumber() << endl;
				cout << "\tDay: ";
				cin >> day;
				cout << "\tHours: ";
				cin >> hour;
				cout << "\tMinute: ";
				cin >> minute;
				cout << "\tSeconds: ";
				cin >> second;
				(*looper)->setSlaughterDetails(day, hour, minute, second);
			}
			looper++;
		}
		printLine();
	}
	else {
		cout << "Invalid Input" << endl;
	}
}

void QMS::changeShareStatus(int animalTokenNo, int animalShareNo,ShareStatus* status) {
	list<Animal*>::iterator looper;
	for (looper = animals.begin(); looper != animals.end(); looper++) {
		if ((*looper)->getTokenNumber() == animalTokenNo) {
			(*looper)->changeShareStatus(animalShareNo,status);
		}
	}
}

void QMS::printAnimal(int animalTokenNo) {
	list<Animal*>::iterator looper;
	for (looper = animals.begin(); looper != animals.end(); looper++) {
		if ((*looper)->getTokenNumber() == animalTokenNo) {
			(*looper)->printDetailedView();
		}
	}
}
void QMS::printAvailableAnimalsInListView() {
	cout << "Printing Available Animals in the format [TokenNo Price Status (No of Available Shares for Big Animals Only)]" << endl;
	printLine();
	list<Animal*>::iterator looper;
	for (looper = animals.begin(); looper != animals.end(); looper++) {
		if ((*looper)->getAnimalStatus() == "Unbooked" || (*looper)->getAnimalStatus() == "PartiallyBooked") {
			(*looper)->printInListView();
		}	
	}
	printLine();
}

void QMS::printLine() {
	for (int i = 0; i < 120; i++) {
		cout << ".";
	}
	cout << endl;
}

void QMS::printAnimalsInListView() {
	printLine();
	cout << "Printing Animals in the format [TokenNo Price Status (No of Available Shares for Big Animals Only)]" << endl;
	list<Animal*>::iterator looper;
	for (looper = animals.begin(); looper != animals.end(); looper++) {
		(*looper)->printInListView();
	}
	printLine();
}

void QMS::viewSchedule() {
	printLine();
	cout << "Printing Schedule for Qurbani" << endl;
	list<Animal*>::iterator looper;
	for (looper = animals.begin(); looper != animals.end(); looper++) {
		if ((*looper)->getSlaughterDetails()) {
			cout << "Animal Token Number: " << (*looper)->getTokenNumber() << endl;
			(*looper)->printSlaughterDetails();
			cout << endl;
		}
	}
	printLine();
}

void QMS::viewReservationsByCustomer(int clientID) {
	list<ClientI*>::iterator looper;
	for (looper = clients.begin(); looper != clients.end(); looper++) {
		if ((*looper)->getUserID() == clientID) {
			cout << "Printing all Reservations By "<< (*looper)->getName()<<" in the format [AnimalTokenNo AnimalShareNo ShareStatus Price]"<< endl;
			(*looper)->printBookedShares();
			cout << endl;
			cout << "TOTAL: " << (*looper)->generateBill() << endl;
		}
	}
}

QMS::~QMS() {
	list<User*>::iterator looper = staff.begin();
	User* temp = nullptr;
	while (looper != staff.end()) {
		temp = *looper;
		looper++;
		delete temp;
	}
	staff.clear();

	list<ClientI*>::iterator looperC = clients.begin();
	ClientI* tempC = nullptr;
	while (looperC != clients.end ()) {
		tempC = *looperC;
		looperC++;
		delete tempC;
	}
	clients.clear();

	list<Animal*> ::iterator looperA = animals.begin();
	Animal* tempA = nullptr;
	while (looperA != animals.end()) {
		tempA = *looperA;
		looperA++;
		delete tempA;
	}
	animals.clear();
}

QMS* QMS:: obj = nullptr;