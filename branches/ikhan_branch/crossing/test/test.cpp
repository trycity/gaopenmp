#include <iostream>
#include "crossing_test.h"
#include "TwoPointCrossing_test.h"
#include "crossing_wraptest.h"





int main()
{
   std::cout<<"Begin crossing tests"<<std::endl<<std::endl;
   
   crossing_test aTestObject;
	aTestObject.runTests();
   
    TwoPointCrossing_test anobject;
     anobject.runTests();
  
   // crossing_wraptest aninstance;
   // aninstance.runTests();
    

  
   
   std::cout<<"End of crossing tests"<<std::endl<<std::endl;	

return 0;
}
