#include "User.h"
//void formatPhoneNumber(char* fPhoneNumber, string phoneNumber);

User::User() :userID{uniqueUserID} {
	name = name.empty();
	phoneNumber[0] = '\0';
	uniqueUserID++;
}

User::User(string uName, string uPhoneNumber): userID{ uniqueUserID },name { uName }{
	formatPhoneNumber(phoneNumber, uPhoneNumber);
	uniqueUserID++;
}

bool User::validatePhoneNumber(string phoneNumber) {
	if (phoneNumber.length() != PHONE_NUMBER_LENGTH) {
		return false;
	}
	return true;
}

void User::formatPhoneNumber(char* phoneNumber, string uPhoneNumber) {
	if (validatePhoneNumber(uPhoneNumber)) {
		strcpy_s(phoneNumber, PHONE_NUMBER_LENGTH + 1, uPhoneNumber.c_str());
	}
	else {
		strcpy_s(phoneNumber, PHONE_NUMBER_LENGTH + 1, "00000000000");
	}
}

void User::saveToFile(ofstream& fout) {
	if (fout.good()) {
		fout.write((char*)&userID, sizeof(userID));
		fout.write(name.c_str(), name.length() + 1);
		fout.write(phoneNumber,sizeof(phoneNumber));
	}
}

User::User(string uName, string uPhoneNumber, int id): userID { id }, name{ uName } {
	formatPhoneNumber(phoneNumber, uPhoneNumber);
	if (id >= uniqueUserID) {
		uniqueUserID = id + 1;
	}
}

void User::print(ostream& out) {
	out << userID << ' ' << name << ' ' << phoneNumber << ' ';
}

int User::getUserID() {
	return userID;
}

string User::getName() {
	return name;
}

User::~User() {
	userID = 0;
	name = "";
	strcpy_s(phoneNumber, strlen("") + 1, "");
}

int User::uniqueUserID = 1;
const int User::PHONE_NUMBER_LENGTH = 11;