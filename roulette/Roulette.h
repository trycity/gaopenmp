#include "Fittness_value.h"


template <class T>

class Roulette

{
  public:
  Roulette(const Population& aPop, const std::vector<unsigned int>& alength, 
                  unsigned int aNDIM, 
                  const std::vector<double>& adomain, 
                  T& afunction): mlength(alength),
                  mNDIM(aNDIM), mdomain(adomain), mfunction(afunction) {}
