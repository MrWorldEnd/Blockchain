#include "request.h"
#include "TransactionData.h"

std::stack<Request> blockbuffer;

Request txhandler(Device client,Device server, IotDevice device){
    Request rq(client, server, device);
    blockbuffer.push(rq);
    return rq;
};

Packet broadcasttx(Request x)
{
    
}

void blockhandler(){
    if (blockbuffer.size() == 4)
    {

    }
};

void Concensus(){};