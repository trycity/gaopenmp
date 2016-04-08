/**
 * @file Configuration.cpp
 * @author trycity
 */

#include "Configuration.h"

#include <omp.h>
#include <vector>
#include <random>

Configuration::Configuration(unsigned int aSizeOfPopulation,
      Chromosome& aChromosome) noexcept :
      mSizeOfPopulation(aSizeOfPopulation)
{
   mPopulation.reserve(mSizeOfPopulation);
   mPopulation.assign(mSizeOfPopulation, aChromosome);
}

Configuration::~Configuration()
{
   mPopulation.clear();
}

void Configuration::Initialization()
{
   std::default_random_engine generator;
   std::uniform_int_distribution<int> distribution(0, 1);
   unsigned int Chrom_size = mPopulation[0].size();

#pragma omp parallel for collapse(2)
   for(unsigned int i = 0; i < mSizeOfPopulation; i++)
   {
      for(unsigned int j = 0; j < Chrom_size; j++)
      {
         mPopulation[i][j] = static_cast<bool>(distribution(generator));
      }
   }
}

POPULATION& Configuration::getPopulation()
{
   return mPopulation;
}
