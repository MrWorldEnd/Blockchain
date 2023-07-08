//
// Created by mrworldend on 09/12/2021.
//

#include <iostream>
#include "TransactionData.h"

#ifndef BLOCKCHAINDEV_BLOCK_H
#define BLOCKCHAINDEV_BLOCK_H

class Block
{
private:
    int index;
    size_t currentHash;
    size_t previousHash;
    size_t generateHash;
    TxDataset pdata;
public:
    Block ();
    Block (Packet d);
    Block (int idx,TxDataset d, size_t prevHash);

    int getIndex();
    size_t getHash();
    size_t getPrevHash();
    Packet getData() const { return pdata; }
    
    size_t generateHash();

    void setData(const TxDataset &x) { pdata = x; }

    bool isValid();
    


    friend ostream& operator<<(ostream& os, const Block& dt){
        os << "[\n    { \n" ;
        os << "\"Index\": \"" << dt.index << "\",\n";
        os <<  "\"Hash\": \"" << dt.currentHash << "\",\n";
        os << "\"PrevHash\": \"" << dt.previousHash << "\",\n";
        os << "\"Transaction Data\": \"" << dt.getData().packetStr() << "\",\n";
        os << "\"SenderKey:\": \"" << dt.getData().getheader().getsenderKey() << "\",\n";
        os <<  "\"ReceiveKey\": \"" << dt.getData().getheader().getreceiverKey() << "\",\n";
        os << "\"Timestamp\": \"" << dt.getData().getheader().gettimestamp() << "\",\n";
        os << "\n    }\n]";
        return os;
    };
};

#endif //BLOCKCHAINDEV_BLOCK_H
