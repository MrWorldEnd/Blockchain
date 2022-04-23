//
// Created by mrworldend on 09/12/2021.
//

#ifndef BLOCKCHAINDEV_TRANSACTIONDATA_H
#define BLOCKCHAINDEV_TRANSACTIONDATA_H

#include <iostream>
#include <vector>
#include <stdio.h>
#include "Packet.h"

struct TxDataset
{
    std::vector<Packet> packets;

    void addTX(Packet tx){
        if (packets.size() < 5)
            packets.push_back(tx);
        else
            std::cout << "Data set full";
    }

    bool isfull(){
        if (packets.size() < 4)
            return false;
        else
            return true;
    }

    int getsize(){return packets.size();}

};

#endif //BLOCKCHAINDEV_TRANSACTIONDATA_H
