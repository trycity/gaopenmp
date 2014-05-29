
#include <iostream>

#include "Chromosome_Length_test.h"


int main()
{
   std::cout<<"Creating Chromosome Length Test object..."<<std::endl;
   Chromosome_Length_test aTestObject;
   aTestObject.runTests();
   std::cout<<"End of test"<<std::endl;

   return 0;
}
