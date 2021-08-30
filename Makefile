CXX=g++
CXXFLAGS=-g -Wall -std=c++11

all: floorplan

floorplan: floorplan.cpp bst.h avlbst.h print_bst.h
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f *.o floorplan 