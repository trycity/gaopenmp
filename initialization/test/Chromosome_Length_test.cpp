
#ifndef UNIT_TEST
#define UNIT_TEST
#endif // UNIT_TEST

#include <iostream>

#include "Chromosome_Length_test.h"
#include "Chromosome_Length.h"

Chromosome_Length_test::Chromosome_Length_test()
{
}

Chromosome_Length_test::~Chromosome_Length_test()
{
}

void Chromosome_Length_test::runTests()
{
	std::cout<<"Running testBuildChromosome"<<std::endl;
	testBuildChromosome();
	std::cout<<"Success"<<std::endl;

	std::cout<<"Running testComputeLength"<<std::endl;
	testComputeLength();
	std::cout<<"Success"<<std::endl;
}

void Chromosome_Length_test::testBuildChromosome()
{
}

void Chromosome_Length_test::testComputeLength()
{
}








/*#include <iostream>
#include "Chromosome_Length.h"

using namespace std;

int main()
{
   std::vector<double> adomain;
   adomain.push_back(1.0);
   adomain.push_back(2.0);   
   adomain.push_back(3.0);
   adomain.push_back(6.0);
   adomain.push_back(8.0);
   adomain.push_back(16.0);   

   unsigned int aNDIM = 2;
   unsigned int aPrecision = 2;
   
   Chromosome_Length aChromosomeLength(aPrecision, aNDIM, adomain);
	
	aChromosomeLength.buildChromosome();
   
 vector<unsigned int> length = aChromosomeLength.getLength();

   cout<<"length[0] = "<<length[0]<<endl;
   cout<<"length[1] = "<<length[1]<<endl;
   cout<<"length[2] = "<<length[2]<<endl;
   return 0; 
}*/
