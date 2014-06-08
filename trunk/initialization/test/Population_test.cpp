
#ifndef UNIT_TEST
#define UNIT_TEST
#endif // UNIT_TEST

#include <iostream>
#include <vector>
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
	
	std::cout<<"Running testgetPopulation"<<std::endl;
	testgetPopulation();
	
}

void Population_test::testInitialization()
{
   unsigned int sizeofpopulation = 20;
	const unsigned int totalLength =10;
   Chromosome ChromosomeLength(totalLength, true);
   
   Population chrom_initial(sizeofpopulation, ChromosomeLength);
	chrom_initial.Initialization();
}

void Population_test::testgetPopulation()
{
  
		
		/*if(Chrom_population.size() != 20)
		{
			throw POPULATION(Chrom_population);
		}
		else
		{
			std::cout<<"SUCCESS: Population_test::testgetPopulation()"<<std::endl<<std::endl;
		}
	}*/
	
}
   
