//
// Created by mrworldend on 09/12/2021.
//

#ifndef BLOCKCHAINDEV_BLOCKCHAIN_H
#define BLOCKCHAINDEV_BLOCKCHAIN_H

#include <vector>
#include "block.cpp"

using namespace std;

class Blockchain
{
private:
    std::vector<Block> chain;
public:
    Blockchain(){
        Block genesis;
        genesis = creategenesisBlock();
        chain.push_back(genesis);
    };
    Block creategenesisBlock();
    
    std::vector<Block> getChain(){return chain;};
    void addBlock(Block bk){
        chain.push_back(bk);
    };
    int getsize();
    bool isvalid();
    void printChain();
    void addBlock(TxDataset d);

    Block *getlatestBlock(){return &chain.back();}

    std::string outChain();
};

#endif //BLOCKCHAINDEV_BLOCKCHAIN_H
