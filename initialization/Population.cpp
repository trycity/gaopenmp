#include "Population.h"

#include <vector>
#include<iostream>
#include <random>

Population::Population(unsigned int  aSizeOfPopulation, Chromosome aChromosome):mSizeOfPopulation(aSizeOfPopulation)
{
   mPopulation.reserve(mSizeOfPopulation);
   mPopulation.assign(mSizeOfPopulation, aChromosome);
}

Population::~Population()
{
   mPopulation.clear();
}

 void Population::Initialization()
{
   std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0,1);
	unsigned int Chrom_size = mPopulation[0].size();
 
	for(unsigned int i =0; i< mSizeOfPopulation; i++)
	{
      
	
		for(unsigned int j=0; j<Chrom_size; j++ )
		{
			mPopulation[i][j]=static_cast<bool>(distribution(generator));
         
		}
		std::cout<<std::endl;
	}	
}
	

POPULATION& Population::getPopulation()
{
   
	return mPopulation;
}
