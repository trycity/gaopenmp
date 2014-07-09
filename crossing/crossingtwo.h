#ifndef CROSSINGTWO_H
#define CROSSINGTWO_H

#include "GA_Typedefs.h"
#include "Population.h"


class crossingtwo
{
 public:
  
   crossingtwo(POPULATION & aPop):fpop(aPop){}


   ~crossingtwo(){}

    void crossovertwo();
    









 private:
  
 POPULATION & fpop;
#ifdef UNIT_TEST
   friend class crossingtwo_test;
#endif //UNIT_TEST
   

};
#endif // CROSSING_HEADER
