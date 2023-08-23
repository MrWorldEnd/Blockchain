//
// Created by mrworldend on 09/12/2021.
//

#include <iostream>
#include "transactionData.h"
#include "sha256.cpp"

#ifndef BLOCKCHAINDEV_BLOCK_H
#define BLOCKCHAINDEV_BLOCK_H

class Block
{
private:
    int index;
    std::string currentHash;
    std::string previousHash;
    TxDataset pdata;
public:
    Block ();
    Block (int idx,TxDataset d, std::string prevHash);

    int getIndex();
    std::string getHash();
    std::string getPrevHash();
    TxDataset getData() const { return pdata;}
    
    void setIndex(const int &x) { index = x;}
    void setData(const TxDataset &x) { pdata = x;}
    void setHash(const std::string &x) { currentHash = x;}
    void setPrevHash(const std::string &x) { previousHash = x;}
    
    bool isValid();
    
    friend ostream& operator<<(ostream& os, const Block& dt){
        os << "Block: [ \n { " << "\n" ;
        os << "Index: " << dt.index << ",\n";
        os << "Hash: " << dt.currentHash << ",\n";
        os << "PrevHash: " << dt.previousHash << ",\n";
        os << "Transaction Data: " << dt.getData().getstr() << "    \n}\n]";
        return os;
    };

    std::string to_string()
{
    std::string out;
    out = out + "\"[\n\"Block\": \n" + "    { \n" ;
    out = out + "\"Index\": \"" + std::to_string(index) + "\",\n";
    out = out + "\"Hash\": \"" + currentHash + "\",\n";
    out = out + "\"PrevHash\": \"" + previousHash + "\",\n";
    out = out + "\"Transaction Data\": \"" + pdata.getstr() + "\",\n";
    out = out + "\n    }\n]";
    return out;
}
};

#endif //BLOCKCHAINDEV_BLOCK_H
