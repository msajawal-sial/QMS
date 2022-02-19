#include "Staff.h"

Staff::Staff(string name,string phoneNumber,string uEmail,string uPass,StaffMemberType* uType):User(name,phoneNumber) {
	email = uEmail;
	pass = uPass;
	type = uType;
}

Staff::Staff(string name, string phoneNumber, string uEmail, string uPass,int uID, StaffMemberType* uType) :User(name, phoneNumber,uID) {
	email = uEmail;
	pass = uPass;
	type = uType;
}

void Staff::setEmail(string newEmail) {
	email = newEmail;
}

void Staff::setPass(string newPass) {
	pass = newPass;
}

void Staff:: print(ostream& out) {
	User::print(out);
	out << email << ' ' << pass << ' ' << type->getType() << endl;
}

void Staff::saveToFile(ofstream& fout) {
	User::saveToFile(fout);
	if (fout.good()) {
		fout.write(email.c_str(), email.length() + 1);
		fout.write(pass.c_str(), pass.length() + 1);
		fout.write(type->getType().c_str(), type->getType().length() + 1);
	}
}

//ostream & operator << (ostream& out, const Staff& obj) {
//	out << (const User &)obj;
//	out << obj.email << " " << obj.pass << " " << obj.type->getType() << endl;
//	return out;
//}

string Staff::getUserType() {
	return type->getType();
}

void Staff::setUserType(StaffMemberType* newType) {
	type = newType;
}

string Staff:: getEmail() {
	return email;
}

string Staff::getPass() {
	return pass;
}

Staff::~Staff() {
	email = "";
	pass = "";
	type = nullptr;
	//cout << "~Staff()" << endl;
}