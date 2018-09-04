
CXX = g++
CXXFLAGS = -std=c++11


main: main.o count_letters.o output_letters.o
	$(CXX) $(CXXFLAGS) -o main main.o count_letters.o output_letters.o

main.o: count_letters.hpp 
	$(CXX) $(CXXFLAGS) -c main.cpp
 
count_letters.o: count_letters.hpp

output_letters.o: output_letters.hpp 

clean:
	rm *.o main 








