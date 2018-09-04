
CXX = g++

CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -g
 
main: main.o Character.o Barbarian.o Medusa.o HarryPotter.o BlueMen.o Vampire.o Game.o Menu.o inputValidation.o
	$(CXX) $(CXXFLAGS) -o main main.o  Medusa.o HarryPotter.o BlueMen.o Character.o Barbarian.o Vampire.o Game.o Menu.o inputValidation.o

main.o: Character.hpp Barbarian.hpp Medusa.hpp HarryPotter.hpp BlueMen.hpp Vampire.hpp Game.hpp Menu.hpp inputValidation.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp
 
Character.o: Character.hpp

Barbarian.o: Barbarian.hpp

Medusa.o: Medusa.hpp

HarryPotter.o: HarryPotter.hpp

BlueMen.o: BlueMen.hpp

Vampire.o: Vampire.hpp

Game.o: Game.hpp

Menu.o: Menu.hpp

inputValidation.o: inputValidation.hpp
 
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

clean:
	rm *.o main 








