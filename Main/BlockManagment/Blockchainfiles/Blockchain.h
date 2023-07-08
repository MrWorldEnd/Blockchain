//
// Created by mrworldend on 09/12/2021.
//

#ifndef BLOCKCHAINDEV_BLOCKCHAIN_H
#define BLOCKCHAINDEV_BLOCKCHAIN_H

#include <vector>
<<<<<<< Updated upstream
=======
#include "Block.cpp"
#include "blockchainsql.cpp"
#include "jsonsystem.h"

using namespace rapidjson;
using namespace std;
>>>>>>> Stashed changes

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

<<<<<<< Updated upstream
=======
    std::string outChain();
    
    Document currentblockchainstate;
>>>>>>> Stashed changes
};

#endif //BLOCKCHAINDEV_BLOCKCHAIN_H
