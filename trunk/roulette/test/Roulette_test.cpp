#include <ctime> 
#include <stdio.h>
#include <ratio>
#include <chrono>
#include <vector>
#include <iostream>

#include "GA_Typedefs.h"
#include "Function.h"
#include "Chromosome_Length.h"
#include "Roulette_test.h"
#include "Roulette.h"
#include "Population.h"
#include "Fittness_value.h"

using namespace std::chrono;

Roulette_test::Roulette_test()
{
}

Roulette_test::~Roulette_test()
{
}
void Roulette_test::runTests()
{
	std::cout<<"Running test"<<std::endl;
	
   testRoulette();
   void printFarm(POPULATION& anObject);
	std::cout<<"Success"<<std::endl<<std::endl;	
}
    
void Roulette_test::printFarm(POPULATION& anObject)
{

	unsigned int chromSize = anObject[0].size();
   
for(unsigned int i =0; i<anObject.size(); i++)
	{
		std::cout<<"Chromosome number = "<<i<<" : ";
		for(unsigned int j=0; j<chromSize; j++ )
		{	
          std::cout<< anObject[i][j];
		}
		std::cout<<std::endl;
	}	

}



void Roulette_test::testRoulette()

{
   unsigned int aPrecision = 4;

   std::vector<double> adomain;
    for(int i=0; i<5; ++i)
	{
   adomain.push_back(1.0);
   adomain.push_back(2.0);   
   adomain.push_back(3.0);
   adomain.push_back(6.0);
   adomain.push_back(8.0);
   adomain.push_back(16.0); 
   }
   std::vector<unsigned int> length;
   unsigned int aNDIM = 3;
   unsigned int size = 10;
   
   Chromosome_Length chrom(aPrecision, aNDIM, adomain);
   chrom.buildChromosome();
   length = chrom.getLength();
   Chromosome achromosome = chrom.getChromosome();
   Population aPop(size, achromosome);

	aPop.Initialization();

	std::cout<<"Initial population"<<std::endl<<std::endl;
	printFarm(aPop.getPopulation());
    
    Function afunction;
    
   Roulette<Function> select( aPop, length, aNDIM, adomain, afunction);
   high_resolution_clock::time_point t1 = high_resolution_clock::now();
   
   for(int i=0; i<10000; ++i)
   {
   select.spinWheel();
   }
   high_resolution_clock::time_point t2 = high_resolution_clock::now();
   
	std::cout<<"Final population"<<std::endl;
	printFarm(aPop.getPopulation());
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

  std::cout << "It took me " << time_span.count() << " seconds."<<std::endl;
}










