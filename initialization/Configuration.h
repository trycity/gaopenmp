/**
 * @file Configuration.h
 * @author trycity
 */

#ifndef CONFIGURATION_HEADER
#define CONFIGURATION_HEADER

#include "GA_Typedefs.h"

class Configuration
{
public:

   /**
    * ctor to create an configuration for the population
    *
    * @param aSizeOfPopulation the size of the population
    * @param aChromosome A chromosome of some particular size
    */
   Configuration(unsigned int aSizeOfPopulation, Chromosome& aChromosome) noexcept;

   /**
    * Destructor
    */
   ~Configuration();

   /** Non-const accessor
    *
    * @return The population
    */
   POPULATION& getPopulation();

   /**
    * Create initial values for chromosomes
    */
   void Initialization();

private:
   /// Population size
   unsigned int mSizeOfPopulation;

   /// array of chromosomes
   POPULATION mPopulation;

#ifdef UNIT_TEST
   friend class Configuration_test;
#endif //UNIT_TEST

};

#endif // CONFIGURATION_HEADER

