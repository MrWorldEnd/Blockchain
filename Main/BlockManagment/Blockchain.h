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
    Block creategenesisBlock();
    std::vector<Block> chain;
public:
    Blockchain();

    std::vector<Block> getChain();
    void addBlock(TxDataset dt);
    int getsize();
    bool isvalid();
    void printChain();

    Block *getlatestBlock();

};

#endif //BLOCKCHAINDEV_BLOCKCHAIN_H
