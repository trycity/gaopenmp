#include "crossing_wrap.h"
#include "crossing_wraptest.h"

#include <iostream>


crossing_wraptest::crossing_wraptest()
{
}

crossing_wraptest::~crossing_wraptest()
{
}
void crossing_wraptest::runTests()
{
	std::cout<<"Running test"<<std::endl;
	testcrossingwraptest();
	std::cout<<"Success"<<std::endl<<std::endl;	
}
 
void crossing_wraptest::testcrossingwraptest()
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






std:: cout << "the initial crossing population"<< std:: endl;
  printFarm(fpop);
 
choice achoice = choice::crossingone;
   crossing_wrap final(fpop, achoice);
   final.optioncross();
std:: cout<<"the final crossing population"<< std::endl;
  printFarm(fpop);

 std:: cout << "the initial crossingtwo population"<< std:: endl;
  printFarm(fpop);
 
choice dchoice = choice::crossingtwo;
   crossing_wrap end(fpop, dchoice);
   end.optioncross();
std:: cout<<"the final crossingtwo population"<< std::endl;
  printFarm(fpop);
}

void crossing_wraptest::printFarm(POPULATION& anObject)
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

