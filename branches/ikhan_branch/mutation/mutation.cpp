#include <iostream>
#include "mutation.h"
#include <random>


void mutation::flipbit()
{

	unsigned int totalbits = fpop.size()*fpop[0].size();
	

	std::default_random_engine generator;  
	std::uniform_real_distribution<double> distribution(0.0,1.0);
	std::vector<double> randomvector(totalbits, 0.0);
	unsigned int a;
	unsigned int b;

	for(unsigned int i=0; i < totalbits; i++ )   
	{        
		randomvector[i] = distribution(generator);

		if(randomvector[i] < 0.01)
      {
      	if(i >= fpop[0].size())
        	{
         	a = i/fpop[0].size();  
				b = i%fpop[0].size();
				
				
        	}
			else
        	{
         	a=0; 
				b=i;
				
            
			}
			fpop[a][b].flip();
		}
	}
}
