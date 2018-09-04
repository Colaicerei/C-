CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

EXECUTABLE = doodlebugs

OBJS = Main.o Validations.o Menu.o Game.o Board.o Critter.o Doodlebug.o Ant.o Debugger.o

SRCS = Main.cpp Validations.cpp Menu.cpp Game.cpp Board.cpp Critter.cpp Doodlebug.cpp Ant.cpp Debugger.cpp

HEADERS = Validations.hpp Menu.hpp Game.hpp Board.hpp Critter.hpp Doodlebug.hpp Ant.hpp Debugger.hpp

${EXECUTABLE}: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o ${EXECUTABLE}

${OBJS}: ${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
	
clean:
	rm *.o ${EXECUTABLE}
