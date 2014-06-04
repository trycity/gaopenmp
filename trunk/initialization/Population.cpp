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

 
	for(unsigned int i =0; i< mSizeOfPopulation; i++)
	{
		std::cout<<"Chromosome number = "<<i<<" : ";
		for(int j=0; j<10; j++ )
		{
			mPopulation[i][j]=static_cast<bool>(distribution(generator));
          std::cout<< mPopulation[i][j];
		}
		std::cout<<std::endl;
	}	
}
	

POPULATION& Population::getPopulation()
{
   
	return mPopulation;
}
