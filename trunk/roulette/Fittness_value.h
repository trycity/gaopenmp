#ifndef FITTNESS_VALUE_H
#define FITTNESS_VALUE_H

#include <vector>
#include <cmath>
#include "GA_Typedefs.h"


template <class T>
class Fittness_value
{
   public:
   Fittness_value(const std::vector<unsigned int>& alength, 
                  unsigned int aNDIM, 
                  const std::vector<double>& adomain, 
                  T& afunction): mlength(alength),
                  mNDIM(aNDIM), mdomain(adomain), mfunction(afunction) {}
                                                                                                                                                    
               
   ~Fittness_value(){}

	double computeValue(  Chromosome& achromosome)
   {
    // create iterators
   // set iterators to initial dimension in chromosome
   Chromosome::const_iterator beginIt = achromosome.begin();  
 
   std::vector<double> values(mNDIM, 0.0);
   
   for(int i=0; i<mNDIM; i++)
   {
    std::vector<bool>::const_iterator secondIt = std::next(beginIt, mlength[i]);  
      
      double lowerLimit = mdomain[2*i];
      double upperLimit = mdomain[2*i+1];

      values[i] = computeCoordinateValue(beginIt, secondIt, lowerLimit, upperLimit);
      
      beginIt = secondIt++;
   }
   
	double result = mfunction(values);
   return result;
   }
   

   
    

   private:
   
   double computeCoordinateValue(Chromosome::const_iterator beginIt, Chromosome::const_iterator secondIt, double lowerLimit, double UpperLimit)
   {
     double m =0;    
   int length =  distance(beginIt,secondIt);
   
   unsigned int i=0;  
 
   for ( ; beginIt != secondIt; ++beginIt)
   {
      m += (*beginIt)*std::pow(2.0,i);
      i++;
   }  
   
   double n = lowerLimit+m*(UpperLimit-lowerLimit)/(std::pow(2.0, length)-1.0);

   return n;
   }
   
	const std::vector<unsigned int> & mlength;
	unsigned int mNDIM;
	const std::vector<double> & mdomain;
	T& mfunction;
};

#endif 
