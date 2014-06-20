// class for Chromosome_Length
/**
 @file Chromosome_Length.cpp
*/

#include <cmath>
#include <omp.h>

#include "Chromosome_Length.h"


Chromosome_Length::Chromosome_Length(unsigned int aPrecision, 
                                     unsigned int aNDIM, 
                                     std::vector<double>& adomain):thePrecision(aPrecision), theNDIM(aNDIM), domain(adomain)
{
   if(theNDIM != domain.size()/2)
   {
      //Throw exception
   }
}

Chromosome_Length::~Chromosome_Length()
{
}

Chromosome Chromosome_Length::getChromosome() const
{
   return theChromosome;
}

void Chromosome_Length::buildChromosome()
{
   unsigned int chromosomeLength = 0;
   #pragma omp parallel 
   {
      #pragma omp for
      for(unsigned int i=0; i<theNDIM; ++i)
      {
         
         unsigned int length = computeLength(domain[2*i], domain[2*i+1]);
         theLengths.push_back(length);
         chromosomeLength += length;
      }
   }

   theChromosome.resize(chromosomeLength);
}

unsigned int Chromosome_Length::computeLength(double aLowerLimit, 
                                              double anUpperLimit)
{
   unsigned int length = 0;
   
   double total = (anUpperLimit - aLowerLimit)*std::pow(10, thePrecision);
   
   while(total > std::pow(2, length)) length++;
   
   return length;
}


 



