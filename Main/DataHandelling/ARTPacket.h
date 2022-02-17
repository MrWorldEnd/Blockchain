#include <iostream>
#include <cstring>
#include "BlockchainDataPackets.cpp"

using namespace std;

class ARTpacket {
    private:
        Header header;
        ARTPayload payload;
    public:
        Artpacket(Header h; ARTPayload p){
            
        }
        void setHeader(Header x){header = x;}
        void setPayload(ARTPayload x){payload = x;}
};