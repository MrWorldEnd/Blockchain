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
        os << "[\n    { \n" ;
        os << "\"id\": \"" << to_string(dt.index) << "\",\n";
        os <<  "\"Hash\": \"" << dt.currentHash << "\",\n";
        os << "\"PrevHash\": \"" << dt.previousHash << "\",\n";
        os <<  "\"Data\": \"" << dt.getData() << "\",\n";
        os << "\n    }\n]";
        os << x;
        return os;
    };
};

#endif //BLOCKCHAINDEV_BLOCK_H
