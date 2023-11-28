//
// Created by mrworldend on 09/12/2021.
//

#ifndef BLOCKCHAINDEV_BLOCKCHAIN_H
#define BLOCKCHAINDEV_BLOCKCHAIN_H

#include <vector>
#include <stack>
#include "block.cpp"

using namespace std;

class Blockchain
{
private:
    std::vector<Block> chain;
    std::stack<string> blockchainstate;
public:
    Blockchain(){
        Block genesis;
        creategenesisBlock();
    };
    void creategenesisBlock(){
        Block x;
        chain.push_back(x);
    };
    
    std::vector<Block> getChain(){return chain;};
    void addBlock(Block bk){
        chain.push_back(bk);
    };
    int getsize();
    bool isvalid();
    void printChain();
    void addBlock(TxDataset d);
    void buildstate();
    std::stack<string>getstate(){return blockchainstate;};

    Block getlatestBlock(){return chain.back();}

    std::string outChain();
};

#endif //BLOCKCHAINDEV_BLOCKCHAIN_H
