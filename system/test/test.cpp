#include <iostream>
#include "GA_OpenMP_test.h"




int main()
{
   std::cout<<"Begin GA tests"<<std::endl<<std::endl;
   
   GA_OpenMP_test aTestObject;
	aTestObject.runTests();

   
   
   std::cout<<"End of GA tests"<<std::endl<<std::endl;	

return 0;
}

