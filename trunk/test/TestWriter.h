// TestWriter.h

#ifndef TESTWRITER_H
#define TESTWRITER_H

#include <string>
#include <map>

<template class T>
class TestWriter
{
public:
	TestWriter(T& aTestClass);
	~TestWriter();
	
	void registerTest(std::string aTestName);
	
	void runTests();
	
	void logTests();
	
private:

	T& mTestClass;
	std::map<std::string, bool> mTestNames;
	
};

//////////////////IMPLEMENTATION/////////////////////

<template class T>
TestWriter::TestWriter(T& aTestClass):mTestClass(aTestClass)
{
}

<template class T>
TestWriter::TestWriter()
{
}

void TestWriter::registerTest(std::string aTestName)
{
	mTestNames[aTestName] = false;
}




#endif // TESTWRITER_H
