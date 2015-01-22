#include "mutation.h"
#include "mutation_test.h"
#include <iostream>
#include <vector>



mutation_test::mutation_test()
{
}

mutation_test::~mutation_test()
{
}
void mutation_test::runTests()
{
	std::cout<<"Running testcrossingtwo"<<std::endl;
	testmutation();
	std::cout<<"Success"<<std::endl<<std::endl;	
}
 
void mutation_test::testmutation()

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
    
     mutation flip(fpop);
     
      flip.flipbit();
   
   printFarm(fpop);
}

void mutation_test::printFarm(POPULATION& anObject)
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
