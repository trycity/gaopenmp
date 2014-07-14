
#ifndef TWOPOINTCROSSING_H
#define TWOPOINTCROSSING_H

#include "GA_Typedefs.h"


class TwoPointCrossing
{
public:
	TwoPointCrossing(POPULATION & aPop);


   ~TwoPointCrossing();

	void crossovertwo();


 private:
  
 POPULATION & fpop;

#ifdef UNIT_TEST
   friend class TwoPointCrossing_test;
#endif //UNIT_TEST

};
#endif

