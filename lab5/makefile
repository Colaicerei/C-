
CXX = g++

CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -g
 
main: main.o recursive.o inputValidation.o Menu.o
	$(CXX) $(CXXFLAGS) -o main main.o  recursive.o inputValidation.o Menu.o 

main.o: recursive.hpp inputValidation.hpp Menu.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp
 
recursive.o: recursive.hpp

Menu.o: Menu.hpp

inputValidation.o: inputValidation.hpp
 
#--track-origins=yes

clean:
	rm *.o main 








