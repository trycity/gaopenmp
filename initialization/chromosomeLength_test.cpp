
#include <iostream>
#include "Chromosome_Length.h"

using namespace std;

int main()
{
   std::vector<double> adomain;
   adomain.push_back(1.0);
   adomain.push_back(2.0);   
   adomain.push_back(3.0);
   adomain.push_back(6.0);
   adomain.push_back(8.0);
   adomain.push_back(16.0);   

   unsigned int aNDIM = 2;
   unsigned int aPrecision = 2;
   
   Chromosome_Length aChromosomeLength(aPrecision, aNDIM, adomain);
	
	aChromosomeLength.buildChromosome();
   
 vector<unsigned int> length = aChromosomeLength.getLength();

   cout<<"length[0] = "<<length[0]<<endl;
   cout<<"length[1] = "<<length[1]<<endl;
   cout<<"length[2] = "<<length[2]<<endl;
   return 0; 
}
