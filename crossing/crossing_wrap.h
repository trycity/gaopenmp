
#ifndef CROSSING_WRAP_H
#define CROSSING_WRAP_H

#include "GA_Typedefs.h"
#include "GA_enum.h"

class crossing_wrap
{
 public:
  
	crossing_wrap(POPULATION& apop, choice achoice);
	~crossing_wrap();
 void optioncross();
   
 private:
  void crossingone();
  void crossingtwo();

  POPULATION& mpop;
  choice mchoice;
	//void (crossing_wrap::*fPointer)(void);
#ifdef UNIT_TEST
   friend class crossing_wraptest;
   
#endif //UNIT_TEST


};

#endif // CROSSING_WRAP_H

