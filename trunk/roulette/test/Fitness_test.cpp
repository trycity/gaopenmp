

#include <vector>
#include <iostream>

#include "GA_Typedefs.h"
#include "Fitness_test.h"
#include "Fittness_value.h"
#include "Function.h"
#include "Chromosome_Length.h"


Fitness_test::Fitness_test()
{
}

Fitness_test::~Fitness_test()
{
}
void Fitness_test::runTests()
{
	std::cout<<"Running testFitness"<<std::endl;
	testFitness();
	std::cout<<"Success"<<std::endl<<std::endl;	
}
 
void Fitness_test::testFitness()
{
   unsigned int aPrecision = 4;

   std::vector<double> adomain;
   adomain.push_back(1.0);
   adomain.push_back(2.0);   
   adomain.push_back(3.0);
   adomain.push_back(6.0);
   adomain.push_back(8.0);
   adomain.push_back(16.0); 

   std::vector<unsigned int> length;
   unsigned int aNDIM = 3;

   Chromosome_Length chrom(aPrecision, aNDIM, adomain);
   chrom.buildChromosome();
   length = chrom.getLength();
   Chromosome achromosome = chrom.getChromosome();
   
    for(unsigned int i=0; i<achromosome.size(); i++)

		{
         if(i%2==0)
           {
              achromosome.push_back(true);
            }
         else
             achromosome.push_back(false); 
       }
   
   Function afunction;
    Fittness_value<Function> fitness(length, aNDIM, adomain, afunction);
    double result;
    result = fitness.computeValue(achromosome);
   std:: cout << "the final vale is" << result << std::endl; 
 }  

