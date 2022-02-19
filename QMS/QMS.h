#pragma once
#include "Client.h"
#include "Staff.h"
#include <list>
#include "SmallAnimal.h"
#include "BigAnimal.h"
#include "Share.h"


class QMS {
private:
	list<ClientI*> clients;
	list<User*> staff;
	list<Animal*> animals;
	QMS();
	static QMS* obj;
	static void printLine();
public:
	static QMS* getIns();
	void addStaff(User*);
	void addClient(ClientI*);
	void printStaff(ostream&);
	void printClients(ostream&);
	void saveStaffToFile(ofstream&);
	void saveClientsToFile(ofstream&);

	void addAnimal(Animal*);
	void addAnimalSlaughterDetail(int, SlaughterDetails*);
	void printAnimals(ostream&);
	void printSmallAnimals(ostream&);
	void printBigAnimals(ostream&);
	void printAnimalSlaughterDetails(ostream&);
	void printShares(ostream&);
	void bookShare();
	void bookShare(int, int, int,ShareStatus*);
	void displayLoginScreen(string&, string&);
	int login();
	void session();
	void displaySalesmanInterface();
	void displayAdminInterface();
	void salesmanUseCases(int);
	void adminUseCases(int);
	void printAvailableAnimalsInListView();
	void printAnimalsInListView();
	void viewSchedule();
	void printAnimal(int);
	void viewReservationsByCustomer(int);
	void changeShareStatus(int,int,ShareStatus*);
	~QMS();
};