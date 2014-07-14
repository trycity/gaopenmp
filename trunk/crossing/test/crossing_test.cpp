
#include "GA_Typedefs.h"
#include <iostream>
#include <vector>
#include "crossing.h"

#include "crossing_test.h"
#include <ctime> 
#include <stdio.h>
#include <ratio>
#include <chrono>

using namespace std::chrono;

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

	for(int i=0; i<1000; ++i)
	{
		fpop.push_back(trueChromosome);
		fpop.push_back(trueChromosome);
		fpop.push_back(achromosome);
	}
    std::cout<< "initial crossing population"<< std::endl;
	  printFarm(fpop);

	high_resolution_clock::time_point t1 = high_resolution_clock::now();
   crossing onepoint(fpop);
   for(int i=0; i<1000; ++i)
   {
      onepoint.crossover();
   }
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	std::cout<< "final crossing population"<< std::endl;

   printFarm(fpop);
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

  std::cout << "It took me " << time_span.count() << " seconds."<<std::endl;
    
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

















