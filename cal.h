#ifndef cal_h
#define cal_h
using namespace std;

class cal{
public:
	int month;
	int year;
	int offset;
	int numDays;
	int getMonth();
	int getYear();
	bool isLeap(int year);
	int setNumberDays(int month, int year);
	int computeOffset(int year, int month);
	void monthName(int month);
	void display(int numDays, int offset, int month, int year);
	void init();
};

#endif