#include<iostream>
#include "Time.h"
using namespace std;
#pragma once

class SlaughterDetails {
	int dayOfEid;
	int hour;
	int minute;
	int second;

public:
	SlaughterDetails();
	SlaughterDetails(int day1,int h,int m,int s);
	void setDayOfEid(int day1);
	void setHour(int h);
	void setMinute(int m);
	void setSecond(int s);
	int getHour();
	int getMinute();
	int getSecond();
	int getDayOfEid();
	virtual void print(ostream&);
	void printDetailedView();
	~SlaughterDetails();

};