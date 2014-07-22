#ifndef GA_OPENMP_TEST_H
#define GA_OPENMP_TEST_H
//#include "GA_Typedefs.h"
#include "GA_Typedefs.h"


class GA_OpenMP_test
{
public:
	GA_OpenMP_test();
	
	~GA_OpenMP_test();

	void runTests();

private:

	 void testgaopenmp();
    void printFarm(POPULATION& anObject);
    std::vector<double> computeValue(Chromosome& achromosome, std::vector<double> mdomain);
		double computeCoordinateValue(Chromosome::const_iterator beginIt, Chromosome::const_iterator secondIt,
                                 double lowerLimit, double UpperLimit);
};
#endif // FITNESS_TEST_H

