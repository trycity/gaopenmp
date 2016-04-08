/**
 * @file Chromosome_Length.h
 * @author ikhan
 */

#ifndef CROSSING_WRAP_H
#define CROSSING_WRAP_H

#include "GA_Typedefs.h"
#include "GA_enum.h"

class crossing_wrap
{
 public:
  /**
   * ctor
   *
   * @param apop
   * @param achoice
   */
	crossing_wrap(POPULATION& apop, choice achoice) noexcept;

	/**
	 * dtor
	 */
	~crossing_wrap();

	/**
	 *
	 */
   void optioncross();
   
 private:
   void crossingone();
   void crossingtwo();

   POPULATION& mpop;
   choice mchoice;

#ifdef UNIT_TEST
   friend class crossing_wraptest;
   
#endif //UNIT_TEST


};

#endif // CROSSING_WRAP_H

