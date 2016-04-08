/**
 * @file Chromosome_Length.cpp
 * @author zshahid
 */

#include <cmath>
#include <omp.h>
#include <iostream>

#include "Chromosome_Length.h"

Chromosome_Length::Chromosome_Length(unsigned int aPrecision,
      unsigned int aNDIM, const std::vector<double>& adomain) :
      thePrecision(aPrecision), theNDIM(aNDIM), thedomain(adomain)
{
   if(theNDIM != thedomain.size() / 2)
   {
      throw;
   }
}

Chromosome_Length::~Chromosome_Length()
{
}

Chromosome Chromosome_Length::getChromosome()
{
   return theChromosome;
}

std::vector<unsigned int> Chromosome_Length::getLength()
{
   return theLengths;
}

void Chromosome_Length::buildChromosome()
{
   unsigned int chromosomeLength {0};
   theLengths.resize(theNDIM, 0);

   #pragma omp for ordered schedule(dynamic)
   for(unsigned int i = 0; i < theNDIM; ++i)
   {
      unsigned int length = computeLength(thedomain[2 * i], thedomain[2 * i + 1]);

      #pragma omp ordered
      theLengths[i] = length;

      chromosomeLength += length;
   }

   theChromosome.resize(chromosomeLength);
}

unsigned int Chromosome_Length::computeLength(double aLowerLimit,
      double anUpperLimit)
{
   unsigned int length {0};

   double total = (anUpperLimit - aLowerLimit) * std::pow(10, thePrecision);

   while(total > std::pow(2, length))
      length++;

   return length;
}

