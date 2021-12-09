//
// Created by mrworldend on 09/12/2021.
//

//Block Constructor
#include <stdio.h>
#include <string>

#include "Block.h"
#include "TransactionData.h"

Block::Block(int inx, TransactionData d, size_t prevHash)
{
    index = inx;
    data = d;
    previousHash = prevHash;
    currentHash = generateHash();
}

size_t Block::generateHash()
{
    hash<string> datahash;
    hash<size_t> lastHash;
    string toHash = to_string(data.amount) + data.receiverKey + data.senderKey + to_string(data.timestamp);
    return datahash(toHash) ^ (prevHash(to_string(lastHash)) << 1 );
}

size_t Block::getHash(){return currentHash;}
size_t Block::getPrevHash(){return previousHash;}
bool Block::isValid(){return generateHash() == getHash();}
int Block::getIndex() {return index;}

#include "Block.h"
