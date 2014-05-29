# initialization makefile

include ../makefile.common

CXXFLAGS += -I../utilities
DIRECTORY = initialization

all:
	$(CXX) $(CXXFLAGS) -c *.cpp

test: all
	$(CXX) $(CXXFLAGS) -c -I../$(DIRECTORY) test/*.cpp
	$(CXX) $(CXXFLAGS) *.o -o test/$(DIRECTORY)

clean:
	rm -rf *.o *.d
	rm -rf test/$(DIRECTORY)
	
   
