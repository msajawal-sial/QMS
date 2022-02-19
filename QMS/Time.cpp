#include "Time.h"

Time::Time(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
}

void Time::setTime(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
}

void Time::print()
{
	cout << setw(2) << setfill('0') << hour << ":"
		<< setw(2) << setfill('0') << minute << ":"
		<< setw(2) << setfill('0') << second << "\n";
}

bool Time::equals(Time otherTime)
{
	if (hour == otherTime.hour &&
		minute == otherTime.minute &&
		second == otherTime.second)
		return true;
	else
		return false;
}