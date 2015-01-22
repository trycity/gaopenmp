#include <iostream>
#include "mutation.h"
#include "mutation_test.h"





int main()
{
   std::cout<<"Begin crossing tests"<<std::endl<<std::endl;
   
   mutation_test aTestObject;
	aTestObject.runTests();
   
    //TwoPointCrossing_test anobject;
     //anobject.runTests();
  
   // crossing_wraptest aninstance;
   // aninstance.runTests();
    

  
   
   std::cout<<"End of crossing tests"<<std::endl<<std::endl;	

return 0;
}
