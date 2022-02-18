//
// Created by mrworldend on 09/12/2021.
//

#ifndef BLOCKCHAINDEV_BLOCK_H
#define BLOCKCHAINDEV_BLOCK_H

#include <ctime>
#include "TxPacket.h"
//transaction data

class Block
{
private:
    int index;
    size_t currentHash;
    size_t previousHash;
    size_t generateHash();
    TxPacket data;
public:

    Block (int idx,TxPacket data, size_t prevHash);

    int getIndex();
    size_t getHash();
    size_t getPrevHash();
    TxPacket getData() const { return data; }
    
    void setData(const TxPacket &x) { data = x; }

    bool isValid();
};

#endif //BLOCKCHAINDEV_BLOCK_H
