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

    std:: string getstr(){
        string x;
        extern vector <Packet> packets;
        x = x + "\n\"    { \n";
        x = x + "Transaction Data: {" ;
        for(auto y: packets){
	        x = x + y.getPinfo() + " , ";
        }
        x = x +  + "}\n";
        x = x + "\"SenderKey:\": \"" + receiverKey  + "\",\n";
        x = x +  "\"ReceiveKey\": \"" + senderKey + "}\",\n";
        x = x +  "\"timestamps\": \"" + to_string(timestamp) + "}\"\n";
        return x;
    }
};

#endif //BLOCKCHAINDEV_TRANSACTIONDATA_H
