#include "GA_Typedefs.h"
#include <iostream>
#include <vector>
#include "TwoPointCrossing.h"

#include "TwoPointCrossing_test.h"
#include <ctime> 
#include <stdio.h>
#include <ratio>
#include <chrono>
using namespace std::chrono;


TwoPointCrossing_test::TwoPointCrossing_test()
{
}

TwoPointCrossing_test::~TwoPointCrossing_test()
{
}
void TwoPointCrossing_test::runTests()
{
	std::cout<<"Running testcrossingtwo"<<std::endl;
	testcrossingtwo();
	std::cout<<"Success"<<std::endl<<std::endl;	
}
 
void TwoPointCrossing_test::testcrossingtwo()

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

   POPULATION fpop;//(5, trueChromosome);
	/*fpop.push_back(achromosome);
	fpop.push_back(achromosome);
	fpop.push_back(achromosome);
	fpop.push_back(achromosome);
	fpop.push_back(achromosome);*/

	for(int i=0; i<100; ++i)
	{
		fpop.push_back(trueChromosome);
		fpop.push_back(trueChromosome);
		fpop.push_back(achromosome);
	}

	printFarm(fpop); 
   high_resolution_clock::time_point t1 = high_resolution_clock::now();
   
    TwoPointCrossing  onepoint(fpop);
   
  for(int i=0; i<1000; ++i)
   {

    onepoint.crossovertwo();
   }

   high_resolution_clock::time_point t2 = high_resolution_clock::now();
   std::cout<<"Final population"<<std::endl;
	printFarm(fpop);
   duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

  std::cout << "It took me " << time_span.count() << " seconds."<<std::endl;
     
}

void TwoPointCrossing_test::printFarm(POPULATION& anObject)
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
