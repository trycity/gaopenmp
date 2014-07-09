#ifndef CROSSING_TEST_H
#define CROSSING_TEST_H

#include "GA_Typedefs.h"

class crossing_test
{
public:
	crossing_test();
	
	~crossing_test();

	void runTests();

private:

	 void testcrossing();
    void printFarm(POPULATION& anObject);

};
#endif // CROSSING_TEST_H

