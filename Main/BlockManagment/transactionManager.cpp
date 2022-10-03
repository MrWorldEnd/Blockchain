#include "request.h"
#include "node.h"
#include <fstream>

std::stack<Packet> currentblockbuffer;
Blockchain blockchain;


Packet artpack(Request x){
    //if request sent from client
    ARTpacket thispc;
    PacketPayload payload(x.getclient(), x.getserver());
    thispc.setpayload(payload);
    //broadcast_tx(x);
    return thispc;
};

Packet dttpack(Request x)
{
    //if request sent from network peer
    DTTpacket thispk;
    PacketPayload payload(x.getclient(), x.getserver());
    thispk.setpayload(payload);
    return thispk;
};

void addTxstack(stack <Packet> txs){
    Packet x;
    while(!txs.empty())
    {
        x = txs.top();
        blockchain.addBlock(x);
        txs.pop();
    }
}

void blockhandler(){
    if (currentblockbuffer.size() > 3)
    {
        addTxstack(currentblockbuffer);
    }
};

void Concensus(){};