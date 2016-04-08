#ifndef CROSSING_H
#define CROSSING_H

#include "GA_Typedefs.h"



class crossing
{
 public:
  
   crossing(POPULATION & aPop):fpop(aPop){}


   ~crossing(){}

    void crossover();
    

 private:
  
 POPULATION & fpop;
#ifdef UNIT_TEST
   friend class crossing_test;
   
#endif //UNIT_TEST
   

};
#endif // CROSSING_HEADER


