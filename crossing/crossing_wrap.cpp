/**
 * @file Chromosome_Length.h
 * @author ikhan
 */

#include "crossing_wrap.h"

#include "crossing.h"
#include "TwoPointCrossing.h"


crossing_wrap::crossing_wrap(POPULATION& apop, choice achoice) noexcept :
                            mpop(apop), mchoice(achoice)
{

}

crossing_wrap::~crossing_wrap()
{
}

void crossing_wrap::crossingone()
{
  
  crossing anobject(mpop);
  anobject.crossover();

}


void crossing_wrap::crossingtwo()
{
 
 TwoPointCrossing twopoint(mpop);
 twopoint.crossovertwo(); 
 
}


void crossing_wrap::optioncross()
{

        if( mchoice == choice::crossingone ) { crossingone(); }
        else if(  mchoice == choice::crossingtwo  ) { crossingtwo() ; }
        
}

