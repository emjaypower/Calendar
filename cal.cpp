#include "cal.h"
#include <iostream>
#include <iomanip>
using namespace std;

int cal::getMonth()
{
	int month;
	cout << "Enter a month number: ";
	cin >> month;

	while ((month < 1) || (month > 12))
	{
		cout << "Month must be between 1 and 12\n";
		cout << "Enter a month number: ";
		cin >> month;
	}
	return (month);
}

int cal::getYear()
{
	int year;
	cout << "Enter year: ";
	cin >> year;

	while (year < 1753)
	{
		cout << "Year must be later than 1753\n";
		cout << "Enter a year: ";
		cin >> year;
	}
	return (year);
}

bool cal::isLeap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		return true;
	else
		return false;
}

int cal::setNumberDays(int month, int year)
{
	if (month == 1)
		return (31);
	else if (month == 2)
	{
		if (cal::isLeap(year))
			return (29);
		else
			return (28);
	}
	else if (month == 3)
		return (31);
	else if (month == 4)
		return (30);
	else if (month == 5)
		return (31);
	else if (month == 6)
		return (30);
	else if (month == 7)
		return (31);
	else if (month == 8)
		return (31);
	else if (month == 9)
		return (30);
	else if (month == 10)
		return (31);
	else if (month == 11)
		return (30);
	else if (month == 12)
		return (31);
}

int cal::computeOffset(int year, int month)
{
	int offset = 0;
	int sum = 0;
	for (int i = 1753; i < year; i++)
	{
		int yearCount = i;
		sum += 365;
		if (isLeap(yearCount))
			sum += 1;
	}

	for (int k = 1; k < month; k++)
	{
		int monthCount = k;
		sum += (setNumberDays(monthCount, year));
	}

	offset = (sum % 7);
	return (offset);
}

void cal::monthName(int month)
{
	if (month == 1)
		cout << "January";
	else if (month == 2)
		cout << "February";
	else if (month == 3)
		cout << "March";
	else if (month == 4)
		cout << "April";
	else if (month == 5)
		cout << "May";
	else if (month == 6)
		cout << "June";
	else if (month == 7)
		cout << "July";
	else if (month == 8)
		cout << "August";
	else if (month == 9)
		cout << "September";
	else if (month == 10)
		cout << "October";
	else if (month == 11)
		cout << "November";
	else if (month == 12)
		cout << "December";

	return;
}

void cal::display(int numDays, int offset, int month, int year)
{
	cout << endl;
	cal::monthName(month);
	cout << ", " << year << endl;
	cout << "  Su  Mo  Tu  We  Th  Fr  Sa\n";

	if (offset != 6)
		for (int num = -1; num < offset; num++)
		{
			if (offset != 6)
				cout << "    ";
		}
	if (offset != 6)
	{
		for (int i = 1; i <= numDays; i++)
		{
			if (((i + offset) % 7 == 0))
				cout << "\n";
			cout << "  " << setw(2) << i;
		}
	}
	else if (offset == 6)
	{
		for (int i = 1; i <= numDays; i++)
		{
			if (((i + offset) % 7 == 0) && (i + offset != 7))
				cout << "\n";
			cout << "  " << setw(2) << i;
		}
	}
	cout << endl;
	return;
}

void cal::init()
{
	month = cal::getMonth();
	year = cal::getYear();
	numDays = cal::setNumberDays(month, year);
	offset = cal::computeOffset(year, month);
}