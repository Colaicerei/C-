
CXX = g++

CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -g
 
main: main.o DList.o inputValidation.o Menu.o
	$(CXX) $(CXXFLAGS) -o main main.o  DList.o inputValidation.o Menu.o 

main.o: DList.hpp inputValidation.hpp Menu.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp
 
DList.o: DList.hpp

Menu.o: Menu.hpp

inputValidation.o: inputValidation.hpp
 
#--track-origins=yes

clean:
	rm *.o main 








