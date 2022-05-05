CXX = g++
CXXFLAGS = -Wall -g


all: main.o Block Blockchain
	$(CXX) $(CXXFLAGS) -o main main.o Block Blockchain

main.o: main.cpp TransactionData.h PacketPayload.h Block.h Blockchain.h
	$(CXX) $(CXXFLAGS) -c main.cpp PacketPayload.h

Block: Block.cpp Block.h TransactionData.h

Blockchain: Blockchain.cpp Blockchain.h

clean: rm  *.o all