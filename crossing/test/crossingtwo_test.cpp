#include "GA_Typedefs.h"
#include <iostream>
#include <vector>
#include "crossingtwo.h"
#include "Population.h"
#include "crossingtwo_test.h"


crossingtwo_test::crossingtwo_test()
{
}

crossingtwo_test::~crossingtwo_test()
{
}
void crossingtwo_test::runTests()
{
	std::cout<<"Running testcrossingtwo"<<std::endl;
	testcrossingtwo();
	std::cout<<"Success"<<std::endl<<std::endl;	
}
 
void crossingtwo_test::testcrossingtwo()

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

	for(int i=0; i<5; ++i)
	{
		fpop.push_back(trueChromosome);
		fpop.push_back(trueChromosome);
		fpop.push_back(achromosome);
	}

	printFarm(fpop); 

   crossingtwo onepoint(fpop);
   onepoint.crossovertwo();
   std::cout<<"Final population"<<std::endl;
	printFarm(fpop); 
}

void crossingtwo_test::printFarm(POPULATION& anObject)
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
