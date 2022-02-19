#pragma once
#include "QMS.h"

class DataPersistence {
protected:
	QMS* qms;
public:
	DataPersistence(QMS*);
	virtual void saveData() = 0;
	virtual void loadData() = 0;
};