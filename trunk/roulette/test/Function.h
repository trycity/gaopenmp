
#ifndef FUNCTION_H
#define FUNCTION_H

#include <vector>
#include <cmath>

class Function
{
   public:
      Function(){}
      ~Function(){}

      double operator()(std::vector<double>& aVector)
      {
         return sin(aVector[0])*sin(aVector[1])*sin(aVector[1]);
      }

};

#endif // FUNCTION_H

