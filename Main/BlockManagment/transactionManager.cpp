#include "request.h"
#include "node.h"
#include <fstream>

std::stack<Request> blockbuffer;

Packet txhandler(Request x){
    //if request sent from client
    ARTpacket thispc;
    PacketPayload payload(x.getclient(), x.getserver());
    thispc.setpayload(payload);
    broadtx(x);
    return thispc;
};

Packet broadtx(Request x)
{
    //if request sent from network peer
    DTTpacket thispk;
    PacketPayload payload(x.getclient(), x.getserver());
    thispk.setpayload(payload);
    return thispk;
};

void blockhandler(){
    if (blockbuffer.size() == 4)
    {

    }
};

void Concensus(){};