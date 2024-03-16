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
    vector<Block> chain;
    stack<string> blockchainstate;
public:

    Blockchain(){
        Block genesis;
        creategenesisBlock();
    };

    Blockchain(string originHash){
        Block genesis(originHash);
        chain.push_back(genesis);
    }

    void creategenesisBlock(){
        Block x;
        chain.push_back(x);
    };
    
    vector<Block> getChain(){return chain;};

    void addBlock(Block bk){
        chain.push_back(bk);
    };

    int getsize();
    bool isvalid();
    void printChain();
    void addBlock(TxDataset d);
    
    stack<string>getstate(){return blockchainstate;};

    Block getlatestBlock(){return chain.back();}

    string outChain();
};

#endif //BLOCKCHAINDEV_BLOCKCHAIN_H
