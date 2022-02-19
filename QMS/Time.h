#include<iostream>
#include<iomanip>
#pragma once
using namespace std;

class Time
{
private:
	int hour;
	int minute;
	int second;
public:
	//constructor with default value 0
	Time(int h = 0, int m = 0, int s = 0);
	//setter function 
	void setTime(int h, int m, int s);
	//print description of object in hh:mm:ss
	void print();
	//compare two time object
	bool equals(Time);
};


