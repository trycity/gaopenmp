
#ifndef
#define

// include files
#include "Chromosome_Length.h"
#include "Population.h"
#include "roulette.h"
#include ...

template <class T>
class GA_OpenMP
{
public:
   GA_OpenMP(/*parameters*/, bool aExtrema(true = max, false = min),
                              crossingValue=0,1,2,3 - enum
                              T aFunction);
   ~GA_OpenMP();


   void run()
   {
      Chromosome_Length aLength(..);
      aLength.buildChromosome();

      Population popObject(aLength.getChromosome, );
      popObject.Initialize();

      roulette wheel(popObject...);
      Crossing crossingObject(...crossingEnum);
      Mutation mutationObject(...);

      for(int i=0; ...)
      {    
         wheel.spinWheel();
         crossingObject.doSomething();
         wheel.spinWheel();
         mutationObject.doSomething();
      }

      mPOP = popObject.getPopulation();

   }

   POPULATION& getPopulation()
   {
      return mPOP;
   }

   double getExtrema()
   {
      return mExtrema;
   }

   std::vector<double> getCoordinates()
   {
      return mCoordinates;
   }

private:
   // members
   mPOP;
   mExtrema;
   mCoordinates

};



#endif
