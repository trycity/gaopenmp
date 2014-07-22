#include "GA_OpenMP_test.h"
#include "GA_OpenMP.h" 
#include <iostream>
#include <vector>
#include "Function.h"
#include "GA_Typedefs.h"

GA_OpenMP_test::GA_OpenMP_test()
{
}

GA_OpenMP_test::~GA_OpenMP_test()
{
}
void GA_OpenMP_test::runTests()
{
	std::cout<<"Running  Algorithm Black Box test"<<std::endl;
	testgaopenmp();
	std::cout<<"Success"<<std::endl<<std::endl;	
}
void GA_OpenMP_test::testgaopenmp()

{ 
   std::vector<double> domain;
    domain.push_back(0.0);
    domain.push_back(3.1415927);
  
    unsigned int value = 0;

    Function mfunction;
    GA_OpenMP<Function> first(domain, value, mfunction);
     first.run();
     POPULATION& dpop =first.getPopulation();
     //printFarm(dpop);

		
		std::vector<std::vector<double>> setCoordinateValues;

		for(unsigned int i=0; i<dpop.size(); ++i)
		{
			setCoordinateValues.push_back(computeValue(dpop[i], domain));
		}

		for(unsigned int i=0; i<setCoordinateValues.size(); ++i)
		{
			std::cout<<"Values = "<<setCoordinateValues[i][0]<<std::endl;
		}
   
}

void GA_OpenMP_test::printFarm(POPULATION& anObject)
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

std::vector<double> GA_OpenMP_test::computeValue(Chromosome& achromosome, std::vector<double> mdomain)
{


     Chromosome::const_iterator beginIt = achromosome.begin(); 
		unsigned int mNDIM = mdomain.size()/2; 
 
      std::vector<double> values(mNDIM, 0.0);
  
		
      for(unsigned int i=0; i<mNDIM; i++)
      {
         std::vector<bool>::const_iterator secondIt = achromosome.end();//std::next(beginIt, mlength[i]);  
      
         double lowerLimit = mdomain[2*i];
         double upperLimit = mdomain[2*i+1];

			
         values[i] = computeCoordinateValue(beginIt, secondIt, lowerLimit, upperLimit);
      	
         beginIt = secondIt++;
      }

		
      return values;
}
   

double GA_OpenMP_test::computeCoordinateValue(Chromosome::const_iterator beginIt, Chromosome::const_iterator secondIt,
                                 double lowerLimit, double UpperLimit)
{
      double m =0;    
      int length =  distance(beginIt,secondIt);
   
      unsigned int i=0;  
 
      for ( ; beginIt != secondIt; ++beginIt)
      {
         m += (*beginIt)*std::pow(2.0,i);
         i++;
      }  
   
      double n = lowerLimit+m*(UpperLimit-lowerLimit)/(std::pow(2.0, length)-1.0);

      return n;
}








  
