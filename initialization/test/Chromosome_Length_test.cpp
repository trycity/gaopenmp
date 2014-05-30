
#ifndef UNIT_TEST
#define UNIT_TEST
#endif // UNIT_TEST

#include <iostream>
#include <vector>
#include <exception>

#include "Chromosome_Length_test.h"
#include "Chromosome_Length.h"

Chromosome_Length_test::Chromosome_Length_test()
{
}

Chromosome_Length_test::~Chromosome_Length_test()
{
}

void Chromosome_Length_test::runTests()
{
	std::cout<<"Running testBuildChromosome"<<std::endl;
	testBuildChromosome();
	std::cout<<"Success"<<std::endl<<std::endl;
	
	std::cout<<"Running testComputeLength"<<std::endl;
	testComputeLength();
	
}

void Chromosome_Length_test::testBuildChromosome()
{
	
}

void Chromosome_Length_test::testComputeLength()
{
	// build the parameter for the chromosome length ctor
	unsigned int nDim = 3;
	unsigned int aPrecision = 6;
	std::vector<double> domain;
	
	for(unsigned i=0; i<2*nDim; ++i)
	{
		domain.push_back(2*i+i);
	}

	Chromosome_Length chrom_length(aPrecision,
									 nDim,
									 domain);

	try
	{
		unsigned int dim_Length = chrom_length.computeLength(domain[0], domain[1]);
		
		if(dim_Length != 22)
		{
			throw int(dim_Length);
		}
		else
		{
			std::cout<<"SUCCESS: Chromosome_Length_test::testComputeLength()"<<std::endl<<std::endl;
		}
	}
	catch(int length)
	{
		std::cout<<"FAILURE: Chromosome_Length_test::testComputeLength()"<<std::endl<<std::endl;
	}
}


