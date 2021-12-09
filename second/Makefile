CXX = g++
CXXFLAGS = -o

all: main.o Block.o Blockchain.o
	(cxx) main.o Block.o Blockchain.o (CXXFLAGS) all

main.o: main.cpp

Block.o: Block.cpp Block.h TransactionData.h
	(CXX)  Blockbuild

Blockchain: Blockchain.cpp Blockchain.h
	(CXX) Blockchain

clean: rm all main.o Block.o