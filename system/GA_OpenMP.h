
#ifndef GA_OPENMP_H
#define GA_OPENMP_H

// include files
#include "Chromosome_Length.h"
#include "Population.h"
#include "Roulette.h"
#include "crossing_wrap.h"
#include "mutation.h"
#include "GA_Typedefs.h"
#include "GA_enum.h"

template <class T>
class GA_OpenMP
{
public:
   GA_OpenMP(const std::vector<double>& adomain, unsigned int crossingvalue,
                              T& aFunction):domain(adomain), value(crossingvalue), mfunction(aFunction), size(75), precision(6){}
   ~GA_OpenMP(){}


   void run()
   {
      unsigned int NDIM = domain.size()/2;
      unsigned int iter =10000;
      
      Chromosome_Length aLength(precision,NDIM,domain);
      aLength.buildChromosome();
       
       Chromosome achromosome = aLength.getChromosome();

      Population popObject(size, achromosome);
      popObject.Initialization();
      
        POPULATION & fpop= popObject.getPopulation();
         std::vector<unsigned int> length= aLength.getLength();
       
       Roulette<T> wheel(popObject, length, NDIM, domain, mfunction);
        
    choice achoice = static_cast<choice>(value);
        
      crossing_wrap cross(fpop, achoice);
      
           mutation mutate(fpop);
           
      for(unsigned int i=0; i<iter; i++ )
      {    
      
         wheel.spinWheel();
          cross.optioncross();
          wheel.spinWheel();
           mutate.flipbit();
         
      }

        mpop = popObject.getPopulation(); 

   }

   POPULATION& getPopulation()
   {
      
      return mpop;
   }

  /*double getExtrema()
   {
      return mExtrema;
   }

   std::vector<double> getCoordinates()
   {
      return mCoordinates;
   }*/

private:
   // members
   const std::vector<double>& domain;
 
  unsigned int value;
    T& mfunction;
    unsigned int size;
     unsigned int precision;
     POPULATION mpop;
};
#ifdef UNIT_TEST
   friend class GA_OpenMP_test;
#endif


#endif
