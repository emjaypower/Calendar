#include "cal.h"
using namespace std;


int main()
{
    cal myCal;
    myCal.init();
    myCal.display(myCal.numDays, myCal.offset, myCal.month, myCal.year);

    return 0;
}