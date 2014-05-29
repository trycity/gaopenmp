// class for Chromosome_Length
/**
 @file Chromosome_Length.h
*/

#ifndef CHROMOSOME_LENGTH_H
#define CHROMOSOME_LENGTH_H

#include <vector>
#include <iterator> 

#include "GA_Typedefs.h"

class Chromosome_Length
{
public:

   /// ctor
   Chromosome_Length(unsigned int aPrecision, 
                     unsigned int aNDIM, 
                     std::vector<double>& adomain);

   /// dtor
   ~Chromosome_Length();

   /// chromosome accessor
   Chromosome getChromosome() const;

   /// accessor
   std::vector<unsigned int> getLength() const
   {
      return theLengths;
   }
  
   /// build chromosome
   void buildChromosome();
   
private:

   unsigned int computeLength(double aLowerLimit, 
                              double anUpperLimit);

   unsigned int thePrecision;

   unsigned int theNDIM;

   std::vector<double>& domain;

   Chromosome theChromosome; 

   std::vector<unsigned int> theLengths;

#ifdef UNIT_TEST
   friend class Chromosome_Length_Test;
#endif
   
};

#endif // CHROMOSOME_LENGTH_H
