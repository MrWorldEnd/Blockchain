#include <iostream>
#include <cstring>
#include "BlockchainDataPackets.cpp"

using namespace std;
//transaction packet
class ARTpacket {
    private:
        Header header;
        ARTPayload payload;        
};
class DTTpacket {
    private:
        Header header;
        DTTPayload payload;    
};
