
CXX = g++

CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -g
 
main: main.o SearchSort.o inputValidation.o Menu.o 
	$(CXX) $(CXXFLAGS) -o main main.o  SearchSort.o inputValidation.o Menu.o 

main.o: SearchSort.hpp inputValidation.hpp Menu.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp
 
SearchSort.o: SearchSort.hpp

Menu.o: Menu.hpp

inputValidation.o: inputValidation.hpp
 
#--track-origins=yes

clean:
	rm *.o main 








