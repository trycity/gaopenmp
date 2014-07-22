#ifndef MUTATION_TEST_H
#define MUTATION_TEST_H

#include "GA_Typedefs.h"

class mutation_test
{
public:
	mutation_test();
	
	~mutation_test();

	void runTests();

private:

	 void testmutation();
    void printFarm(POPULATION& anObject);

};
#endif // CROSSING_TEST_H

