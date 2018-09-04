
CXX = g++

CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -g
 
main: main.o University.o inputValidation.o Menu.o Building.o Person.o Instructor.o Student.o
	$(CXX) $(CXXFLAGS) -o main main.o  University.o inputValidation.o Menu.o Building.o Person.o Student.o Instructor.o

main.o: University.hpp inputValidation.hpp Menu.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp
 
University.o: University.hpp Building.hpp Person.hpp Instructor.hpp Student.hpp

Building.o: Building.hpp

Person.o: Person.hpp

Student.o: Person.hpp Student.hpp

Instructor.o: Person.hpp Instructor.hpp

Menu.o: Menu.hpp

inputValidation.o: inputValidation.hpp
 
#--track-origins=yes

clean:
	rm *.o main 








