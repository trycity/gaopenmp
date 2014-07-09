

#include <iostream>
#include "crossing.h"
#include "GA_Typedefs.h"
#include "Population.h"
#include <random>
#include <vector>
#include <omp.h>

void crossing::crossover()
{

 std::vector<unsigned int> chosen;

 std::default_random_engine generator;
 std::uniform_real_distribution<double> distribution(0.0,1.0);
 std::vector<double> randomvector(fpop.size(), 0.0);
	
	for(unsigned int i=0; i < fpop.size(); i++ )   
	{        
		randomvector[i] = distribution(generator);

		if(randomvector[i] < 0.25)
      {
      	chosen.push_back(i);
			//std::cout<<"i = "<<i<<std::endl;
      }
	}
	

  if((chosen.size()%2 != 0) || (chosen.size() == 1))
  {
		chosen.pop_back();
	}
	
   Chromosome temp1(fpop[0].size(), 0.0);
   Chromosome temp2(fpop[0].size(), 0.0);

  unsigned int position = static_cast<unsigned int>(distribution(generator)*fpop[0].size());

	//std::cout<<"fpop size = "<<fpop.size()<<std::endl;
	//std::cout<<" position = "<<position<<std::endl;
  //#pragma omp parallel for 
  for(unsigned int i = 0; i < chosen.size(); i = i+2)
   {
    std::copy(fpop[chosen[i]].begin(), fpop[chosen[i]].end(),
              temp1.begin() );
    std::copy(fpop[chosen[i+1]].begin(), fpop[chosen[i+1]].end(),
              temp2.begin() );
     //#pragma omp parallel for
     for(unsigned int k = position; k<fpop[0].size(); k++)
      {
       temp1[k] = fpop[chosen[i+1]][k];
       temp2[k] = fpop[chosen[i]][k];
      //std::cout<<" end number chosen = "<<chosen.size()<<std::endl;
    	std::copy(temp1.begin(), temp1.end(),
              fpop[chosen[i]].begin() );
    	std::copy(temp2.begin(), temp2.end(),
              fpop[chosen[i+1]].begin() );

       }
        
    }
  
}






