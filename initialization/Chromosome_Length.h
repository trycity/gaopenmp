/**
 * @file Chromosome_Length.h
 * @author zshahid
 */

#ifndef CHROMOSOME_LENGTH_H
#define CHROMOSOME_LENGTH_H

#include <vector>

#include "GA_Typedefs.h"

class Chromosome_Length
{
public:
   /// ctor
   Chromosome_Length(unsigned int aPrecision, 
                     unsigned int aNDIM, 
                     const std::vector<double>& adomain);

   /// dtor
   ~Chromosome_Length();

   /// chromosome accessor
   Chromosome getChromosome();

   /// accessor for length array
   std::vector<unsigned int> getLength();
  
   /// build chromosome
   void buildChromosome();
   
private:

   /**
    * Compute the length of the chromosome in a particular dimension
    *
    * @param aLowerLimit  The lower limit of a particular dimension
    * @param anUpperLimit The upper limit of a particular dimension
    *
    * @return the length of the chromosome in a particular dimension
    */   
   unsigned int computeLength(double aLowerLimit, 
                              double anUpperLimit);

   /// the required precision
   unsigned int thePrecision;

   /// The number of dimensions
   unsigned int theNDIM;

   /// The domain of the problem
   const std::vector<double>& thedomain;

   /// The chromosome
   Chromosome theChromosome; 

   /// An array of lengths - each element represents the size of the chromosome in each dimension
   std::vector<unsigned int> theLengths;

#ifdef UNIT_TEST
   friend class Chromosome_Length_test;
#endif
   
};

#endif // CHROMOSOME_LENGTH_H

