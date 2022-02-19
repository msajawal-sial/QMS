#include "DataPersistenceByFile.h"
#include "BigAnimal.h"
#include "SmallAnimal.h"
using namespace std;


int main() {
	QMS* qms = QMS::getIns();
	DataPersistenceByFile DP(qms);	
	DP.loadData();
	qms->session();
	DP.saveData();
	delete qms;

	return 0;
}

