PRJ=projekt1
CXX=g++
CXXFLAGS=-Wall -pedantic -std=c++17

$(PRJ): main.o
	${CXX} -o $@ $<

run: ${PRJ}
	./${PRJ}

main.o: main.cpp quicksort.hpp mergesort.hpp #introsort.hpp
	${CXX} -c $< $(CXXFLAGS)

%.o: %.cpp %.hpp
	${CXX} -c $< $(CXXFLAGS)

.PHONY: clean
clean:
	rm -f ${PRJ} *.o *~
