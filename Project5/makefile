
CXX = g++

CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -g
 
SRCS = main.cpp Space.cpp Player.cpp Menu.cpp inputValidation.cpp Game.cpp Town.cpp Forest.cpp Mountain.cpp Desert.cpp Sea.cpp Island.cpp

PROG1 = main
PROGS = ${PROG1}

all:
	$(CXX) $(CXXFLAGS) ${SRCS} -o ${PROG1} 

#--VARGS = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes

#debug:
#   @valgrind $(VARGS) ./output

#PHONY: valgrind
#valgrind:
#	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes

clean:
	rm *.o main 








