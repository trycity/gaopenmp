#ifndef TWOPOINTCROSSING_TEST_H
#define TWOPOINTCROSSING_TEST_H

#include "GA_Typedefs.h"

class TwoPointCrossing_test
{
public:
	TwoPointCrossing_test();
	
	~TwoPointCrossing_test();

	void runTests();

private:

	 void testcrossingtwo();
    void printFarm(POPULATION& anObject);

};
#endif // CROSSING_TEST_H

