//
// Created by mrworldend on 09/12/2021.
//

#ifndef BLOCKCHAINDEV_BLOCKCHAIN_H
#define BLOCKCHAINDEV_BLOCKCHAIN_H

#include <vector>
#include "Block.h"

class Blockchain
{
private:
    std::vector<Block> chain;
public:
    Blockchain();
    Block creategenesisBlock();

    std::vector<Block> getChain();
    void addBlock(Packet dt);
    int getsize();
    bool isvalid();
    void printChain();

    Block *getlatestBlock();

    std::string outChain();
};

#endif //BLOCKCHAINDEV_BLOCKCHAIN_H
