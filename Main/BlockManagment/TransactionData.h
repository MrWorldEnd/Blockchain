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
    vector <Packet> packets;
    string receiverKey;
    string senderKey;
    time_t timestamp;

    TxDataset(string x,string y){
        receiverKey = x;
        senderKey = y;
        time(&timestamp);
    }

    TxDataset(){
        receiverKey = "GenesisBlock";
        senderKey = "GenesisBlock";
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

    friend ostream& operator<<(ostream& os, const TxDataset& tx){
        string x;
        extern vector <Packet> packets;
        x = tx.receiverKey + " , " + tx.senderKey + "\n";
        x = x + "[\n    { \n";
        x = x + "Data: " ;
        for(auto y: packets){
	        x = x + y.getPinfo() + " , ";
        }
        x = x + to_string(tx.timestamp) + "\n";
        os << x;
        return os;
    }
};

#endif //BLOCKCHAINDEV_TRANSACTIONDATA_H
