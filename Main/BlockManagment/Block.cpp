//
// Created by mrworldend on 09/12/2021.
//

//Block Constructor
#include <stdio.h>
#include <string>

#include "Block.h"
#include "TransactionData.h"

Block::Block()
{
    index = 0;
    setData(Packet());
    previousHash = '0';
    currentHash = generateHash();
}

Block::Block(int inx, TxDataset d, size_t prevHash)
{
    index = inx;
    data = d;
    previousHash = prevHash;
    currentHash = generateHash();
}



size_t Block::generateHash()
{
    std::string toHash = data.getPayload().getPayloadstr();

    std::hash<std::string> datahash;
    std::hash<std::string> lastHash;

    std::string x = std::to_string(previousHash);
    return datahash(toHash) ^ (lastHash(x) << 1 );
}

size_t Block::getHash(){return currentHash;}
size_t Block::getPrevHash(){return previousHash;}
bool Block::isValid(){return generateHash() == getHash();}
int Block::getIndex() {return index;}

