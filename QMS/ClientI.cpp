#include "ClientI.h"

ClientI::ClientI():User() {

}

ClientI::ClientI(string name, string phoneNumber) : User(name, phoneNumber) {

}

ClientI::ClientI(string name, string phoneNumber, int uID) : User(name, phoneNumber,uID) {

}

ClientI::~ClientI() {

}