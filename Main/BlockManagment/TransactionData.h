//
// Created by mrworldend on 09/12/2021.
//

#ifndef BLOCKCHAINDEV_TRANSACTIONDATA_H
#define BLOCKCHAINDEV_TRANSACTIONDATA_H

#include <iostream>
#include <vector>
#include <stdio.h>
#include "Packet.h"
#include <time.h> 

using namespace std;

struct TxDataset
{
    vector<Packet> packets;
    string receiverKey;
    string senderKey;
    time_t timestamp;

    string strTxDataset(){
        string x;
        x = receiverKey + " , " + senderKey + "\n";
        x = x + to_string(timestamp) + "\n";
        return "\n{" + x + "}";
    }

    TxDataset(string x,string y){
        receiverKey = x;
        senderKey = y;
        time(&timestamp);
    }

    TxDataset(){
        receiverKey = "receiver Key";
        senderKey = "Test Sender Key";
        time(&timestamp);
    }

    void addTX(Packet tx){
        if (packets.size() < 5)
            packets.push_back(tx);
        else
            cout << "Data set full";
    }

    bool isfull(){
        if (packets.size() < 4)
            return false;
        else
            return true;
    }

    int getsize(){return packets.size();}

    vector<Packet> getpackets(){return packets;}

};

#endif //BLOCKCHAINDEV_TRANSACTIONDATA_H
