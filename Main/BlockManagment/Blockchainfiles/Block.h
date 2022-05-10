//
// Created by mrworldend on 09/12/2021.
//

#include <iostream>

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
    size_t generateHash;
    TxDataset data;
public:
    Block ();
    Block (int idx,TxDataset d, size_t prevHash);

    int getIndex();
    size_t getHash();
    size_t getPrevHash();
    TxDataset getData() const { return data; }
    
    size_t generateHash();

    void setData(const TxDataset &x) { data = x; }

    bool isValid();


    friend ostream& operator<<(ostream& os, const Block& dt){
        std::string x;
        x = "[\n    { \n" ;
        x = x + "\"id\": \"" + to_string(dt.getIndex()) + "\",\n";
        x = x +  "\"Hash\": \"" + dt.getHash() + "\",\n";
        x = x + "\"PrevHash\": \"" + dt.getPrevHash() + "\",\n";
        x = x +  "\"Data\": \"" dt.getData() + "\",\n";
        x = x + "\n    }\n]";
        return x;
    };
};

#endif //BLOCKCHAINDEV_BLOCK_H
