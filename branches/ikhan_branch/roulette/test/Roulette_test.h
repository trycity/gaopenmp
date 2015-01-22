#ifndef ROULETTE_TEST_H
#define ROULETTE_TEST_H
#include "GA_Typedefs.h"

class Roulette_test
{
public:
	Roulette_test();
	
	~Roulette_test();

	void runTests();

private:

	 void testRoulette();
    void printFarm(POPULATION& anObject);

};
#endif // FITNESS_TEST_H

