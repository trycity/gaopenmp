
#include "crossing_wrap.h"

#include "crossing.h"
#include "TwoPointCrossing.h"


crossing_wrap::crossing_wrap(POPULATION& apop, choice achoice):mpop(apop), mchoice(achoice)
{

}

crossing_wrap::~crossing_wrap()
{
}

void crossing_wrap::crossingone()
{
  std::cout <<"before crossing1"<< std::endl;
  crossing anobject(mpop);
  anobject.crossover();

}


void crossing_wrap::crossingtwo()
{
 std::cout <<"before crossing2"<< std::endl;
 TwoPointCrossing twopoint(mpop);
 twopoint.crossovertwo(); 
 std::cout <<"after crossing2"<< std::endl;
}


void crossing_wrap::optioncross()
{

        if( mchoice == choice::crossingone ) { crossingone(); }
        else if(  mchoice == choice::crossingtwo  ) { crossingtwo() ; }
        
}

