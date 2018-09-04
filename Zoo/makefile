
CXX = g++

CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -g
 
main: main.o Game.o Animal.o Tiger.o Penguin.o Turtle.o NewAnimal.o inputValidation.o Menu.o
	$(CXX) $(CXXFLAGS) -o main main.o  Game.o Animal.o Tiger.o Penguin.o Turtle.o NewAnimal.o inputValidation.o Menu.o

main.o: Game.hpp Animal.hpp Tiger.hpp Penguin.hpp Turtle.hpp NewAnimal.hpp inputValidation.hpp Menu.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp
 
Animal.o: Animal.hpp

Tiger.o: Animal.hpp Tiger.hpp

penguin.o: Animal.hpp Penguin.hpp

Turtle.o: Animal.hpp Turtle.hpp

NewAnimal.o: Animal.hpp NewAnimal.hpp

Menu.o: Menu.hpp

inputValidation.o: inputValidation.hpp
 

clean:
	rm *.o main 








