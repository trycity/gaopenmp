#include<iostream>
#include "crossingtwo.h"
#include "GA_Typedefs.h"
#include "Population.h"
#include <random>
#include <vector>
#include <omp.h>


void crossingtwo::crossovertwo()

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
	
 std::cout<< "before chosen "<<std::endl;
  if((chosen.size()%2 != 0) || (chosen.size() == 1))
  {
		chosen.pop_back();
	}
	
   Chromosome temp1(fpop[0].size(), 0.0);
   Chromosome temp2(fpop[0].size(), 0.0);



 unsigned int position1 = static_cast<unsigned int>(distribution(generator)*fpop[0].size());
 unsigned int position2 = static_cast<unsigned int>(distribution(generator)*fpop[0].size());
   if (position2<position1)
      {
         std::swap(position2, position1);

      }

	std::cout<<" position1 = "<<position1<< std::endl;
   std::cout<<" position2 = "<<position2<< std::endl;
  #pragma omp parallel for collapse(1)
  for(unsigned int i = 0; i < chosen.size(); i = i+2)
   {
    std::copy(fpop[chosen[i]].begin(), fpop[chosen[i]].end(),
              temp1.begin() );
    std::copy(fpop[chosen[i+1]].begin(), fpop[chosen[i+1]].end(),
              temp2.begin() );
      
     for(unsigned int k = position1; k< position2; k++)
      {
       temp1[k] = fpop[chosen[i+1]][k];
       temp2[k] = fpop[chosen[i]][k];
      
    	std::copy(temp1.begin(), temp1.end(),
              fpop[chosen[i]].begin() );
    	std::copy(temp2.begin(), temp2.end(),
              fpop[chosen[i+1]].begin() );

       }
        
    }
  
}

