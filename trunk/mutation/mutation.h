#ifndef MUTATION_H
#define MUTATION_H

#include "GA_Typedefs.h"


class mutation
{
 public:
  
   mutation(POPULATION & aPop):fpop(aPop){}


   ~mutation(){}

    void flipbit();
    

 private:
  
 POPULATION & fpop;
#ifdef UNIT_TEST
   friend class mutation_test;
   
#endif //UNIT_TEST
   

};
#endif // CROSSING_HEADER

