#include <iostream>
#include <cstring>
#include "BlockchainDataPackets.cpp"

using namespace std;
//transaction packet
class ARTpacket {
    private:
        Header header;
        ARTPayload payload;
    public:
        void setHeader(Header x){header = x;}
        void setPayload(ARTPayload x){payload = x;}
};
class DTTpacket {
    private:
        Header header;
        DTTPayload payload;
    public:
        void setHeader(Header x){header = x;}
        void setPayload(ARTPayload x){payload = x;}
};

//
class block {
    private
};