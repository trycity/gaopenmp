/**
 * @file The fitness value class
 * @author zshahid
 */

#ifndef FITTNESS_VALUE_H
#define FITTNESS_VALUE_H

#include <vector>
#include <cmath>
#include <iostream>

#include "GA_Typedefs.h"

template<class T>
class Fittness_value
{
public:
   /**
    * Fitness Value ctor
    *
    * @param alength A length of each dimension in chromosome (binary) space
    * @param aNDIM The number of dimensions of the problem
    * @param adomain The domain covering the dimensions of the function
    * @param afunction The template function in question
    */
   Fittness_value(const std::vector<unsigned int>& alength, unsigned int aNDIM,
         const std::vector<double>& adomain, T& afunction) :
         mlength(alength), mNDIM(aNDIM), mdomain(adomain), mfunction(afunction)
   {
   }

   /// dtor        
   ~Fittness_value()
   {
   }

   /**
    * Computes the value of a particular chromosome in the function
    *
    * @param achromosome The chromosome in question
    *
    * @return The value of the chromosome in the function
    */
   double computeValue(Chromosome& achromosome)
   {

      // create iterators
      // set iterators to initial dimension in chromosome
      Chromosome::const_iterator beginIt = achromosome.begin();

      std::vector<double> values(mNDIM, 0.0);

      for(unsigned int i = 0; i < mNDIM; i++)
      {
         std::vector<bool>::const_iterator secondIt = std::next(beginIt,
               mlength[i]);

         double lowerLimit = mdomain[2 * i];
         double upperLimit = mdomain[2 * i + 1];

         values[i] = computeCoordinateValue(beginIt, secondIt, lowerLimit,
               upperLimit);

         beginIt = secondIt++;
      }

      double result = mfunction(values);

      return result;
   }

private:

   /**
    * Computes the value of a particular coordinate in function space
    *
    * @param beginIt The begin iterator for a particular dimension
    * @param secondIt The end iterator for a particular dimension
    * @param lowerLimit The lower limit value of a dimension in the function
    * @param UpperLimit The upper limit value of a dimension in the function
    *
    * @return The value of the coordinate of a chromosome
    */
   double computeCoordinateValue(Chromosome::const_iterator beginIt,
         Chromosome::const_iterator secondIt, double lowerLimit,
         double UpperLimit)
   {
      double m = 0;
      int length = distance(beginIt, secondIt);

      unsigned int i = 0;

      for(; beginIt != secondIt; ++beginIt)
      {
         m += (*beginIt) * std::pow(2.0, i);
         i++;
      }

      double n = lowerLimit
            + m * (UpperLimit - lowerLimit) / (std::pow(2.0, length) - 1.0);

      return n;
   }

   /// The length of each dimension in the chromosome
   const std::vector<unsigned int> & mlength;

   /// The number of dimensions
   unsigned int mNDIM;

   /// The domain of the problem
   const std::vector<double> & mdomain;

   /// The function over which the Genetic Algorithm will perform its search
   T& mfunction;

#ifdef UNIT_TEST
   friend class Fitness_test;
#endif //UNIT_TEST
};

#endif // FITTNESS_VALUE_H
