
#include "GA_Typedefs.h"
#include <iostream>
#include <vector>
#include "crossing.h"
#include "Population.h"
#include "crossing_test.h"
#include <time.h> 
#include <stdio.h>


crossing_test::crossing_test()
{
}

crossing_test::~crossing_test()
{
}
void crossing_test::runTests()
{
	std::cout<<"Running testcrossing"<<std::endl;
	testcrossing();
	std::cout<<"Success"<<std::endl<<std::endl;	
}
 
void crossing_test::testcrossing()

{

    Chromosome achromosome;
   achromosome.push_back(true);
   achromosome.push_back(true);
   achromosome.push_back(true);
   achromosome.push_back(true);
   achromosome.push_back(true);
   achromosome.push_back(false);
   achromosome.push_back(false);
   achromosome.push_back(false);
   achromosome.push_back(false);
   achromosome.push_back(false);
  
	Chromosome trueChromosome(10, true);

   POPULATION fpop;

	for(int i=0; i<5; ++i)
	{
		fpop.push_back(trueChromosome);
		fpop.push_back(trueChromosome);
		fpop.push_back(achromosome);
	}
    
	  //printFarm(fpop);

	clock_t start = clock();    
   crossing onepoint(fpop);
   onepoint.crossover();
	clock_t end = clock();
   std::cout<<"Final population"<<std::endl;
	//printFarm(fpop);
	double time = difftime(end, start) * 1000.0;
	std::cout<<"Number of seconds = "<<time<<std::endl;
    
}

void crossing_test::printFarm(POPULATION& anObject)
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
