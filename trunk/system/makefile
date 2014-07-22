# system makefile

include ../makefile.common

CXXFLAGS += -I../utilities
CXXFLAGS += -I../initialization
CXXFLAGS += -I../roulette
CXXFLAGS += -I../crossing
CXXFLAGS += -I../mutation
DIRECTORY = system

all:
	$(CXX) $(CXXFLAGS) -c *.h

test: all
	$(CXX) $(CXXFLAGS) -c ../initialization/*.cpp
	
	$(CXX) $(CXXFLAGS) -c ../crossing/*.cpp
	$(CXX) $(CXXFLAGS) -c ../mutation/*.cpp
	$(CXX) $(CXXFLAGS) -c -I../$(DIRECTORY) test/*.cpp
	$(CXX) $(CXXFLAGS) *.o -o test/$(DIRECTORY)

clean:
	rm -rf *.o *.d *.gch
	rm -rf test/$(DIRECTORY)
	
   
