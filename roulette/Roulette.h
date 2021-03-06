/**
 * @file The Roulette  class
 * @author zshahid
 */

#ifndef ROULETTE_H
#define ROULETTE_H

#include "Population.h"
#include "Fittness_value.h"
#include "GA_Typedefs.h"

#include <vector>
#include <random>
#include <algorithm>

template<class T>
class Roulette
{
public:
   /**
    * Roulette  ctor
    *
    * @param aPop The population(farm) object of the of all the chromosomes in (binary)space
    * @param alength A length of each dimension in chromosome (binary) space
    * @param aNDIM The number of dimensions of the problem
    * @param adomain The domain covering the dimensions of the function
    * @param afunction The template function in question
    */
   Roulette(Population& aPop, const std::vector<unsigned int>& alength,
         unsigned int aNDIM, const std::vector<double>& adomain, T& afunction) :
         mPop(aPop), mlength(alength), mNDIM(aNDIM), mdomain(adomain), mfunction(
               afunction)
   {
   }

   /// dtor
   ~Roulette()
   {
   }

   /**
    * New Farm is set up using a roulette wheel parent selection
    *
    */
   void spinWheel()
   {
      /*
       *fpop is refrerence of vector to a vector of bools
       *FitnessVector contain fitness of each individual chromosomes of the farm
       *fitness object of Fitness_value class to call compute value method for calculation individual values
       */
      POPULATION& fpop = mPop.getPopulation();
      std::vector<double> FitnessVector(fpop.size(), 0.0);
      std::vector<double> probalityVector;
      double totalFitness = 0.0;
      double cummulativeProb = 0.0;
      std::vector<double> cum_prob_vector;
      Fittness_value<T> fitness(mlength, mNDIM, mdomain, mfunction);

      #pragma omp for ordered schedule(dynamic)
      for(unsigned int i = 0; i < fpop.size(); i++)
      {
         #pragma omp ordered
         FitnessVector[i] = fitness.computeValue(fpop[i]);
         totalFitness += FitnessVector[i];

      }

      /*
       *Calculate the probality vector
       *Calculate cummaltive probaly vector
       *
       */
      for(unsigned int i = 0; i < fpop.size(); i++)
      {
         probalityVector.push_back(FitnessVector[i] / totalFitness);
         cummulativeProb += probalityVector[i];
         cum_prob_vector.push_back(cummulativeProb);
      }

      /*
       * randomvector setting the vector of random real numbers
       * Create the new population
       */
      std::default_random_engine generator;
      std::uniform_real_distribution<double> distribution(0.0, 1.0);
      std::vector<double> randomvector(fpop.size(), 0.0);

      for(unsigned int i = 0; i < fpop.size(); i++)
      {

         randomvector[i] = distribution(generator);
         unsigned int count = 0;

         while(randomvector[i] > cum_prob_vector[count])
         {
            count++;
         };
         if(count != i)
         {
            std::copy(fpop[count].begin(), fpop[count].end(), fpop[i].begin());

         }

      }
   }

private:

   /// The population class object representation farm of chromosomes
   Population& mPop;

   /// The length of each dimension in the chromosome
   const std::vector<unsigned int> & mlength;

   /// The number of dimensions
   unsigned int mNDIM;

   /// The domain of the problem
   const std::vector<double> & mdomain;

   /// The function over which the Genetic Algorithm will perform its search
   T& mfunction;

#ifdef UNIT_TEST
   friend class Roulette_test;
#endif //UNIT_TEST
};
#endif // ROULETTE_H
