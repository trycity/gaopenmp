// TestWriter.h

#ifndef TESTWRITER_H
#define TESTWRITER_H

#include <string>
#include <map>

template <class T>
class TestWriter
{
public:
	TestWriter(T& aTestClass);
	~TestWriter();
	
	void registerTest(T& aTestClass);
	
	void runTests();
	
	void logTests();
	
private:

	T& mTestClass;
	std::map<std::string, bool> mTestNames;
	
};

//////////////////IMPLEMENTATION/////////////////////

template <class T>
TestWriter<T>TestWriter(T& aTestClass):mTestClass(aTestClass)
{
}

template <class T>
TestWriter<T>::~TestWriter()
{
}

template <class T>
void TestWriter<T>::registerTest(T& aTestClass)
{
	mTestNames[aTestClass] = false;
}

template <class T>
void TestWriter<T>::logTests()
{
}

template <class T>
void TestWriter<T>::runTests()
{
	mTestClass.runTests();
}




#endif // TESTWRITER_H
