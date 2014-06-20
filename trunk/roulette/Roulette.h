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
      double totalFitness;
      double cummulativeProb;
      std:: vector<double> cum_prob_vector;
      Fittness_value<T> fitness(mlength, mNDIM, mdomain, mfunction);

      
     for(int i=0; i < fpop.size(); i++)   
      {
         FitnessVector[i]= fitness.computeValue();
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
   for(int i=0; i <fpop.size(); i++ )   
    {   
         std::default_random_engine generator;
         std::uniform_real_distribution<double> distribution(0.0,1.0);
         std::vector<double> randomvector;
         
         randomvector[i] = distribution(generator);
         int count=0;
         while(randomvector[i] > cum_prob_vector[count]) {count++;};
          for(unsigned int j=0; j< totallength; j++) 
           {   
             fpop[i][j]= fpop[count][j];
           }
    }


   }


   private:
      Population& mPop;
      const std::vector<unsigned int> & mlength;
      unsigned int mNDIM;
      const std::vector<double> & mdomain;
      T& mfunction;

};
#endif // ROULETTE_H

