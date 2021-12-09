//
// Created by mrworldend on 09/12/2021.
//

#ifndef BLOCKCHAINDEV_BLOCK_H
#define BLOCKCHAINDEV_BLOCK_H

#include "TransactionData.h"
//transaction data

class Block
{
private:
    int index;
    size_t currentHash;
    size_t previousHash;
    size_t generateHash();
public:
    //constructor
    Block (int idx,TransactionData data, size_t prevHash);
    int getIndex();
    size_t getHash();
    size_t getPrevHash();
    TransactionData data;// usualy private with getter
    bool isValid();
};

#endif //BLOCKCHAINDEV_BLOCK_H
