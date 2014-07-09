#include <iostream>
#include "crossing_test.h"
#include "crossingtwo_test.h"





int main()
{
   std::cout<<"Begin crossing tests"<<std::endl<<std::endl;
   
   crossing_test aTestObject;
	aTestObject.runTests();
   
    crossingtwo_test anobject;
     anobject.runTests();
    

  
   
   std::cout<<"End of crossing tests"<<std::endl<<std::endl;	

return 0;
}
