









CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -o2
DEBUG=-g
Objects= Node.o finale.o
Tree:$(Objects)
	$(CXX) $(DEBUG) $(Objects) -o a.out
	doxygen



Node.o: Node.cpp Node.h
finale.o: finale.cpp Node.h


