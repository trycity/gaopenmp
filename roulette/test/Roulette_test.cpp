#include <vector>
#include <iostream>
#include "GA_Typedefs.h"
#include "Function.h"
#include "Chromosome_Length.h"
#include "Roulette_test.h"
#include "Roulette.h"
#include "Population.h"
#include "Fittness_value.h"

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
	std::cout<<"Success"<<std::endl<<std::endl;	
}

void Roulette_test::testRoulette()

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
   unsigned int size = 10;
   
   Chromosome_Length chrom(aPrecision, aNDIM, adomain);
   chrom.buildChromosome();
   length = chrom.getLength();
   Chromosome achromosome = chrom.getChromosome();
   Population aPop(size, achromosome);
    
    Function afunction;
    //Fittness_value<T> fitness(length, aNDIM, adomain, afunction);
   Roulette<Function> select( aPop, length, aNDIM, adomain, afunction);
   select.spinWheel();
}
