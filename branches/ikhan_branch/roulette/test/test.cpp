// test.cpp

#include <iostream>
#include "Fitness_test.h"
#include "Roulette_test.h"




int main()
{
   std::cout<<"Begin roulette tests"<<std::endl<<std::endl;
   
   Fitness_test aTestObject;
	aTestObject.runTests();

   Roulette_test arouletteobject;   
   arouletteobject.runTests();
   
   std::cout<<"End of roulette tests"<<std::endl<<std::endl;	

return 0;
}

