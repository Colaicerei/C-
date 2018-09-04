
CXX = g++
CXXFLAG = -wall -g


main: main.o readMatrix.o determinant.o
	$(CXX) $(CXXFLAGS) -o main main.o readMatrix.o determinant.o

main.o: readMatrix.hpp determinant.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp
 
readMatrix.o: readMatrix.hpp

determinant.o: determinant.hpp
 

clean:
	rm *.o main 








