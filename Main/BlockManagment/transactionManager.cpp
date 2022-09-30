#include "request.h"
#include "node.h"
#include <fstream>

std::stack<Request> blockbuffer;

Packet txhandler(Request x){
    Packet thispc();
    thispc.validateTx(x.getclient(),  device);
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