
#ifndef POPULATION_TEST_H
#define POPULATION_TEST_H

#include "GA_Typedefs.h"

class Population_test
{
public:
	Population_test();
	
	~Population_test();

	void runTests();

private:

	void testInitialization();

	void printFarm(POPULATION& popRef);

};

#endif // POPULATION_TEST_H
