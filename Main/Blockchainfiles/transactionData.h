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
class TxDataset
{
    private:
    
    vector <Packet> packets;
    string receiverKey;
    string senderKey;
    time_t timestamp;

    public:

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

    std::string getstr(){
        string x;
        x.append("\n\"    { \n");
        x = x + "Transaction Data: {" ;
        for(auto y: packets){
	        x.append(y.packetStr() + " , ");
        }
        x.append("}\n");
        x.append("\"SenderKey:\": \"" + receiverKey  + "\",\n");
        x.append("\"ReceiveKey\": \"" + senderKey + "}\",\n");
        x.append("\"timestamps\": \"" + to_string(timestamp) + "}\"\n");
        return x;
    }
};

#endif //BLOCKCHAINDEV_TRANSACTIONDATA_H
