
#ifndef UNIT_TEST
#define UNIT_TEST
#endif // UNIT_TEST

#include <iostream>
#include <exception>

#include "Population_test.h"
#include "Population.h"


Population_test::Population_test()
{
}

Population_test::~Population_test()
{
}

void Population_test::runTests()
{
	std::cout<<"Running testInitialization"<<std::endl;
	testInitialization();
	std::cout<<"Success"<<std::endl<<std::endl;	
}

void Population_test::testInitialization()
{
   unsigned int sizeofpopulation = 20;
	const unsigned int totalLength =10;
   Chromosome ChromosomeLength(totalLength, true);

   try
   {
      Population chrom_initial(sizeofpopulation, ChromosomeLength);
	   chrom_initial.Initialization();

		
      
		POPULATION& popRef = chrom_initial.getPopulation();
		unsigned int chromSize = popRef[0].size();
		printFarm(popRef);
      if(chromSize != sizeofpopulation)
      {
         throw int(chromSize);
      }
		
   }
   catch(int x)
   {
      std::cout<<"FAILURE: Population_test::testInitialization()"<<std::endl<<std::endl;
   }

}

void Population_test::printFarm(POPULATION& popRef)
{

	unsigned int sizeofpopulation = popRef.size();
	unsigned int chromSize = popRef[0].size();

	for(unsigned int i=0; i<sizeofpopulation; i++)
	{
      std::cout<<"Chromosome number = "<<i<<":  ";
      
		for(unsigned int j =0; j<chromSize; j++)
		{
      	std::cout<<popRef[i][j];
		}
		std::cout<<std::endl;
	}	
}



   
