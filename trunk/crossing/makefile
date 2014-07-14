# crossing makefile

include ../makefile.common

CXXFLAGS += -I../utilities
#CXXFLAGS += -I../initialization

DIRECTORY = crossing

all:
	$(CXX) $(CXXFLAGS) -c  *.cpp

test: all
	
	$(CXX) $(CXXFLAGS) -c -I../$(DIRECTORY) test/*.cpp
	$(CXX) $(CXXFLAGS) *.o -o test/$(DIRECTORY)

clean:
	rm -rf *.o *.d *.gch
	rm -rf test/$(DIRECTORY)
