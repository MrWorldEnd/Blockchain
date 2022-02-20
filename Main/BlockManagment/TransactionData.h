//
// Created by mrworldend on 09/12/2021.
//

#ifndef BLOCKCHAINDEV_TRANSACTIONDATA_H
#define BLOCKCHAINDEV_TRANSACTIONDATA_H

#include <iostream>
#include <vector>
#include <stdio.h>
#include "userdatastructures.h"

struct TXpacket {
    private:
        Header header;
        Payload payload;
};
struct TxDataset
{
    std::vector<TXpacket> packets;
    void addTX(TXpacket tx){
        if (packets.size() < 5)
            packets.push_back(tx);
        else
            std::cout << "Data set full";
    }

};

#endif //BLOCKCHAINDEV_TRANSACTIONDATA_H
