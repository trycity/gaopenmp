/**
 *
 */


#ifndef POPULATION_HEADER
#define POPULATION_HEADER

//#include <bitset>

#include "GA_Typedefs.h"


/// the chromosome length
// const unsigned int ChromosomeLength = 16;
//typedef std::bitset<ChromosomeLength> Chromosome;

//typedef std::vector<Chromosome> POPULATION;

class Population
{
public:
   
   /**
    * ctor to create a population object
    *
    * @param aSizeOfPopulation the size of the population
    */
   Population(unsigned int aSizeOfPopulation, 
                       Chromosome aChromosome);

   /**
    * Destructor
    */
   ~Population();

   /**
    * const ref accessor method
    *
    * @return The population
    */
   /*const POPULATION& getPopulation() const;

   
    * Non-const accessor
    *
    * @return The population
    */
   POPULATION& getPopulation();
	 void  Initialization();

private:
   /// Population size
   unsigned int mSizeOfPopulation;

   /// array of chromosomes
   POPULATION mPopulation;

#ifdef UNIT_TEST
   friend class Population_test;
#endif //UNIT_TEST

};


#endif // POPULATION_HEADER

