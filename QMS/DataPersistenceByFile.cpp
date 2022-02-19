#include "DataPersistenceByFile.h"
#include "Admin.h"
#include "Salesman.h"
#include "BigAnimal.h"
#include "SmallAnimal.h"
#include "Share.h"
#include "Delievered.h"
#include "DistributedToPoor.h"

DataPersistenceByFile::DataPersistenceByFile(QMS* obj): DataPersistence(obj) {

}

void DataPersistenceByFile::saveData() {
	saveUserData();
	saveAnimalData();
	saveShareData();
}

void DataPersistenceByFile::loadData() {
	loadUserData();
	loadAnimalData();
	loadShareData();
}
void DataPersistenceByFile::saveUserData() {
	const char* staffFile = "staff";
	const char* clientFile = "clients";
	ofstream fout;
	fout.open(staffFile,ios::binary);
	if (fout.is_open()) {
		qms->saveStaffToFile(fout);
		fout.close();
	}
	fout.open(clientFile, ios::binary);
	if (fout.is_open()) {
		qms->saveClientsToFile(fout);
	}

}

void DataPersistenceByFile::loadUserData() {
	//list<User*> users;
	const char* staffFileName = "staff";
	const char* clientFileName = "clients";

	ifstream fin;
	fin.open(staffFileName, ios::binary);
	if (fin.is_open()) {
		int id;
		string name, email, pass, type;
		string phoneNumber;
		Staff* temp = nullptr;
		ClientI* client = nullptr;
		StaffMemberType* uType = nullptr;

		while (!fin.eof()) {
			initializeVariablesForReadingStaff(id, name, phoneNumber, email, pass, type);
			readStaff(fin, id, name, phoneNumber, email, pass, type);

			if (!type.compare("Admin")) {
				uType = Admin::getIns();
			}
			else if (!type.compare("Salesman")) {
				uType = Salesman::getIns();
			}
			if ((email != "") && (pass != "")) {
				temp = new Staff(name, phoneNumber, email, pass, id, uType);
				qms->addStaff(temp);
			}
		}
		fin.close();
	}
	fin.open(clientFileName, ios::binary);
	if (fin.is_open()) {
		int id, amountPaid;
		string name;
		string phoneNumber;
		ClientI* temp = nullptr;

		while (!fin.eof()) {
			initializeVariablesForReadingClient(id, name, phoneNumber, amountPaid);
			readClient(fin, id, name, phoneNumber, amountPaid);

			if (id != 0) {
				temp = new Client(name, phoneNumber, id, amountPaid);
				qms->addClient(temp);
			}
		}
		fin.close();
	}
}

void DataPersistenceByFile::initializeVariablesForReadingUser(int& id, string& name, string& phoneNumber) {
	id = 0;
	name = "";
	phoneNumber = "";
}

void DataPersistenceByFile::initializeVariablesForReadingClient(int& id, string& name, string& phoneNumber, int& amountPaid) {
	DataPersistenceByFile::initializeVariablesForReadingUser(id, name, phoneNumber);
	amountPaid = 0;
}

void DataPersistenceByFile::initializeVariablesForReadingStaff(int& id, string& name, string& phoneNumber, string& email, string& pass,string& type) {
	DataPersistenceByFile::initializeVariablesForReadingUser(id, name, phoneNumber);
	email = "";
	pass = "";
	type = "";
}

void DataPersistenceByFile::readUser(ifstream& fin, int& id, string& name, string& phoneNumber) {
	fin.read((char*)&id, sizeof(id));
	getline(fin, name, '\0');
	getline(fin, phoneNumber, '\0');
}

void DataPersistenceByFile::readClient(ifstream& fin, int& id, string& name, string& phoneNumber, int& amountPaid) {
	DataPersistenceByFile::readUser(fin,id,name,phoneNumber);
	fin.read((char*)&amountPaid,sizeof(amountPaid));
}

void DataPersistenceByFile::readStaff(ifstream& fin, int& id, string& name, string& phoneNumber, string& email, string& pass, string& type) {
	DataPersistenceByFile::readUser(fin, id, name, phoneNumber);
	getline(fin, email, '\0');
	getline(fin, pass, '\0');
	getline(fin, type, '\0');
}

void DataPersistenceByFile::saveAnimalData() {
	const char* fileName = "biganimal.txt";
	ofstream fout;
	fout.open(fileName);
	if (fout.is_open()) {
		qms->printBigAnimals(fout);
		fout.close();
	}

	const char* fileName1 = "smallanimal.txt";
	ofstream fout1;
	fout1.open(fileName1);
	if (fout1.is_open()) {
		qms->printSmallAnimals(fout1);
		fout1.close();
	}

	const char* fileName2 = "slaughterdetails.txt";
	ofstream fout2;
	fout2.open(fileName2);
	if (fout2.is_open()) {
		qms->printAnimalSlaughterDetails(fout2);
		fout2.close();
	}

}

void DataPersistenceByFile::loadAnimalData() {
	const char* FileName = "biganimal.txt";
	const char* FileName1 = "smallanimal.txt";
	const char* FileName2 = "slaughterdetails.txt";

	ifstream fin;
	fin.open(FileName);
	if (fin.is_open()) {
		int token;
		float price, weight;
		bool ondisplay;
		string type;
		int sharesav;
		string status;
		BigAnimal* temp = nullptr;
		AnimalStatus* sat = nullptr;

		while (!fin.eof()) {
			token = 0;
			price = 0;
			weight = 0;
			ondisplay = false;
			sharesav = 0;
			status = "";
			type = "";

			fin.ignore(100, ':');
			fin >> token;

			fin.ignore(100, ':');
			fin >> price;

			fin.ignore(100, ':');
			fin >> weight;

			fin.ignore(100, ':');
			fin >> ondisplay;

			fin.ignore(100, ':');
			fin >> status;

			fin.ignore(100, ':');
			fin >> type;

			fin.ignore(100, ':');
			fin >> sharesav;

			if (status.compare("Unbooked") == 0) {
				sat = UnBooked::getIns();
			}

			else if (status.compare("PartiallyBooked") == 0) {
				sat = PartiallyBooked::getIns();
			}

			else if (status.compare("FullyBooked") == 0) {
				sat = FullyBooked::getIns();
			}

			else if (status.compare("Slaughtered") == 0) {
				sat = Slaughtered::getIns();
			}

			//cout << "\n" << token << " " << weight << " " << price << " " << ondisplay << " " <<status;
			if (token != 0) {
				temp = new BigAnimal(token, weight, price, ondisplay, sat);
				//temp->print(cout);
				qms->addAnimal(temp);
			}
		}
		fin.close();
	}


	fin.open(FileName1);
	if (fin.is_open()) {
		int token;
		float price, weight;
		bool ondisplay;
		string type;
		string status;
		SmallAnimal* temps = nullptr;
		AnimalStatus* sat = nullptr;

		while (!fin.eof()) {
			token = 0;
			price = 0;
			weight = 0;
			ondisplay = false;
			status = "";
			type = "";

			fin.ignore(100, ':');
			fin >> token;

			fin.ignore(100, ':');
			fin >> price;

			fin.ignore(100, ':');
			fin >> weight;

			fin.ignore(100, ':');
			fin >> ondisplay;

			fin.ignore(100, ':');
			fin >> status;

			fin.ignore(100, ':');
			fin >> type;



			if (status.compare("Unbooked") == 0) {
				sat = UnBooked::getIns();
			}

			else if (status.compare("PartiallyBooked") == 0) {
				sat = PartiallyBooked::getIns();
			}

			else if (status.compare("FullyBooked") == 0) {
				sat = FullyBooked::getIns();
			}

			else if (status.compare("Slaughtered") == 0) {
				sat = Slaughtered::getIns();
			}
			//cout << "\n" << token << " " << weight << " " << price << " " << ondisplay << " " <<status;
			if (token != 0) {
				temps = new SmallAnimal(token, weight, price, ondisplay, sat);
				//temp->print(cout);
				qms->addAnimal(temps);
			}
		}
		fin.close();
	}


	fin.open(FileName2);
	if (fin.is_open()) {
		int token;
		int day;
		int hour;
		int minute;
		int second;
		SlaughterDetails* tempsd = nullptr;

		while (!fin.eof()) {
			token = 0;
			day = 0;
			hour = 0;
			minute = 0;
			second = 0;

			fin.ignore(100, ':');
			fin >> token;

			fin.ignore(100, ':');
			fin >> day;

			fin.ignore(100, ':');
			fin >> hour;

			fin.ignore(100, ':');
			fin >> minute;

			fin.ignore(100, ':');
			fin >> second;

			//cout << "\n" << token << " " << weight << " " << price << " " << ondisplay << " " <<status;
			if (token != 0) {
				tempsd = new SlaughterDetails(day, hour, minute, second);
				//temp->print(cout);
				qms->addAnimalSlaughterDetail(token, tempsd);
			}
		}
		fin.close();
	}
}

void DataPersistenceByFile::saveShareData() {
	const char* sharesFile = "shares.txt";
	ofstream fout;
	fout.open(sharesFile);
	if (fout.is_open()) {
		qms->printShares(fout);
		fout.close();
	}
}

void DataPersistenceByFile::loadShareData() {

	const char* FileName = "shares.txt";
	ifstream fin;
	fin.open(FileName);
	if (fin.is_open()) {
		int token;
		int clientID;
		int shareNo;
		string status;
		ShareStatus* sat = nullptr;
		Share* temp = nullptr;

		while (!fin.eof()) {
			token = 0;
			clientID = 0;
			status = "";
			shareNo = 0;

			fin >> shareNo;
			fin >> token;
			fin >> clientID;
			fin >> status;

			if (status.compare("Booked") == 0) {
				sat = Booked::getIns();
			}

			else if (status.compare("Delievered") == 0) {
				sat = Delievered::getIns();
			}

			else if (status.compare("DistributedToPoor") == 0) {
				sat = DistributedToPoor::getIns();
			}
			
			if (token != 0) {
				qms->bookShare(shareNo, token, clientID, sat);
			}
		}
		fin.close();
	}
}

DataPersistenceByFile::~DataPersistenceByFile() {
}