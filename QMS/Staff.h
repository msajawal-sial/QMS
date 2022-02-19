#pragma once
#include "User.h"
#include "Salesman.h"
#include "Admin.h"
class Staff :public User {
private:
	string email;
	string pass;
	StaffMemberType* type;
public:
	Staff(string, string, string, string,StaffMemberType*);
	Staff(string, string, string, string, int, StaffMemberType*);
	void setPass(string);
	void setEmail(string);
	void print(ostream&);
	virtual string getUserType();
	virtual void saveToFile(ofstream&);
	void setUserType(StaffMemberType*);
	string getEmail();
	string getPass();
	virtual ~Staff();
};