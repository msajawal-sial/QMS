#pragma once

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class User {
private:
	string name;
	int userID;
	char phoneNumber[12];
	static int uniqueUserID;
	static const int PHONE_NUMBER_LENGTH;
	static bool validatePhoneNumber(string);
	static void formatPhoneNumber(char*,string);
protected:
	User(string, string, int);
public:
	User();
	User(string, string);
	virtual void print(ostream&);
	virtual string getUserType() = 0;
	int getUserID();
	string getName();
	virtual void saveToFile(ofstream&);
	virtual ~User();
};