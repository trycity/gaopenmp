#ifndef ROULETTE_H
#define ROULETTE_H

#include "Population.h"
#include "Fittness_value.h"
#include "GA_Typedefs.h"

#include <vector>
#include <random>

template <class T>

class Roulette
  
  {
  public:
  Roulette(Population& aPop, 
           const std::vector<unsigned int>& alength, 
           unsigned int aNDIM, 
           const std::vector<double>& adomain, 
           T& afunction):mPop(aPop), mlength(alength),
                           mNDIM(aNDIM), mdomain(adomain), mfunction(afunction){}
     
   void spinWheel()
   {
      POPULATION& fpop = mPop.getPopulation();
      std::vector<double> FitnessVector;
      std::vector<double> probalityVector;
      double totalFitness =0.0;
      double cummulativeProb = 0.0;
      std:: vector<double> cum_prob_vector;
      Fittness_value<T> fitness(mlength, mNDIM, mdomain, mfunction);

      
     for(int i=0; i < fpop.size(); i++)   
      {
         FitnessVector[i]= fitness.computeValue(fpop[i]);
         totalFitness += FitnessVector[i];
       }  
    for(int i=0; i < fpop.size(); i++)   
      {   
         probalityVector[i]= FitnessVector[i]/totalFitness;
         cummulativeProb +=probalityVector[i];
         cum_prob_vector[i] = cummulativeProb;
      }
      unsigned int totallength = 0;
      for( unsigned int i =0; i <mNDIM; i++)
       {
          totallength += mlength[i];
       }
   
         std::default_random_engine generator;
         std::uniform_real_distribution<double> distribution(0.0,1.0);
         std::vector<double> randomvector(fpop.size(), 0.0);
        
        

        for(int i=0; i <fpop.size(); i++ )   
        {   
         
         randomvector[i] = distribution(generator);
         int count=0;
      
         while(randomvector[i] > cum_prob_vector[count]) {count++;};
          if(count!=i)
          {
          for(unsigned int j=0; j< totallength; j++) 
           {   
             fpop[i][j]= fpop[count][j];
           }
          }
        
        }
  }


   private:
      Population& mPop;
      const std::vector<unsigned int> & mlength;
      unsigned int mNDIM;
      const std::vector<double> & mdomain;
      T& mfunction;

#ifdef UNIT_TEST
   friend class Roulette_test;
#endif //UNIT_TEST

};
#endif // ROULETTE_H

