# initialization makefile

include ../makefile.common

CXXFLAGS += -I../utilities

all:
	$(CXX) $(CXXFLAGS) -c *.cpp

test: all
	$(CXX) $(CXXFLAGS) -c -I../initialization test/*.cpp
	$(CXX) $(CXXFLAGS) *.o -o test/initialization

clean:
	rm -rf *.o *.d
	rm -rf test/*.o test/*.d
	
   
