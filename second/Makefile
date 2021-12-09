CXX = g++
CXXFLAGS = -Wall -g


all: main.o Block.o Blockchain.o
	$(CXX) $(CXXFLAGS) -o main main.o Block.o Blockchain.o

main.o: main.cpp TransactionData.h Block.h Blockchain.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Block.o: Block.cpp Block.h TransactionData.h

Blockchain: Blockchain.cpp Blockchain.h

clean: rm  *.o all