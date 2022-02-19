#pragma once
#include "DataPersistence.h"

class DataPersistenceByFile: public DataPersistence {
private:
	void saveUserData();
	void loadUserData();
	void loadAnimalData();
	void saveAnimalData();
	void saveShareData();
	void loadShareData();
	static void initializeVariablesForReadingUser(int&, string&, string&);
	static void initializeVariablesForReadingClient(int&, string&, string&, int&);
	static void initializeVariablesForReadingStaff(int&, string&, string&, string&, string&, string&);
	static void readUser(ifstream&, int&, string&, string&);
	static void readClient(ifstream&, int&, string&, string&, int&);
	static void readStaff(ifstream&, int&, string&, string&, string&, string&, string&);
public:
	DataPersistenceByFile(QMS*);
	virtual void saveData();
	virtual void loadData();	
	~DataPersistenceByFile();
};