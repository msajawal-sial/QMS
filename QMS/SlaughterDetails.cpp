#include"SlaughterDetails.h"

SlaughterDetails::SlaughterDetails() {
	dayOfEid = 0;
	hour = 0;
	minute = 0;
	second = 0;
}

SlaughterDetails::SlaughterDetails(int day1, int h,int m,int s) {
	dayOfEid = day1;
	hour = h;
	minute = m;
	second = s;
}

void SlaughterDetails::setDayOfEid(int day1) {
	dayOfEid = day1;
}

int SlaughterDetails::getDayOfEid() {
	return dayOfEid;
}


void SlaughterDetails::setHour(int h) {
	hour = h;
}
void SlaughterDetails::setMinute(int m) {
	minute = m;
}
void SlaughterDetails::setSecond(int s) {
	second = s;
}

int SlaughterDetails::getHour() {
	return hour;
}
int SlaughterDetails::getMinute() {
	return minute;
}

int SlaughterDetails::getSecond() {
	return second;
}

void SlaughterDetails::print(ostream& out) {
	out << "\nDay_of_Eid:" << dayOfEid;
	out << "\nTime:" << hour << ":" << minute << ":" << second;
}

void SlaughterDetails::printDetailedView() {
	cout << "\tEid Day: " << dayOfEid << endl;
	cout << "\tTime: " << hour << "-" << minute << "-" << second << endl;
}

SlaughterDetails::~SlaughterDetails() {
	dayOfEid = 0;
	hour = 0;
	minute = 0;
	second = 0;
}