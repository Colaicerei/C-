
CXX = g++

CXXFLAGS = -std=c++11
#CXXFLAGS += -Wall
CXXFLAGS += -g
 
main: main.o Ant.o Board.o Menu.o inputValidation.o 
	$(CXX) $(CXXFLAGS) -o main main.o Ant.o Board.o Menu.o inputValidation.o

main.o: Ant.hpp Board.hpp Menu.hpp inputValidation.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp
 
Ant.o: Ant.hpp

Board.o: Board.hpp

Menu.o: Menu.hpp

inputValidation.o: inputValidation.hpp
 

clean:
	rm *.o main 








