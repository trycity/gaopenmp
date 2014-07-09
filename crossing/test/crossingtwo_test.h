#ifndef CROSSINGTWO_TEST_H
#define CROSSINGTWO_TEST_H

#include "GA_Typedefs.h"

class crossingtwo_test
{
public:
	crossingtwo_test();
	
	~crossingtwo_test();

	void runTests();

private:

	 void testcrossingtwo();
    void printFarm(POPULATION& anObject);

};
#endif // CROSSING_TEST_H

