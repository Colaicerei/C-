
CXX = g++

CXXFLAGS = -std=c++11
#CXXFLAGS += -Wall
CXXFLAGS += -g
 
main: main.o Game.o Die.o LoadedDie.o inputValidation.o 
	$(CXX) $(CXXFLAGS) -o main main.o Game.o Die.o LoadedDie.o inputValidation.o

main.o: Game.hpp Die.hpp LoadedDie.hpp inputValidation.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp
 
Game.o: Game.hpp

Die.o: Die.hpp

LoadedDie.o: LoadedDie.hpp

inputValidation.o: inputValidation.hpp
 

clean:
	rm *.o main 








