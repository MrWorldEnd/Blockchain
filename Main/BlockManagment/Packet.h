#include <stdio.h>
#include <ctime>
#include <string>
#include "TxHeader.h"
#include "PacketPayload.h"

using namespace std;
//transaction packet

class Packet {
    private:
        TxHeader pheader;
        string pinfo;
        PacketPayload payload;
    public:
        void setpHeader(TxHeader ph){
            pheader= ph;
        }
        void setpPinfo(string x){
            pinfo= x;
        }
        void setpayload(PacketPayload x){
            payload = x;
        }

        string getPinfo(){
            return pinfo;
        }

        PacketPayload getPayload(){return payload;}
        TxHeader getheader(){return pheader;}

        string packetStr(){
            string x;
            x = pinfo + "/n" + payload.getPayloadstr();
            return x;
        }
};

class ARTpacket: public Packet {
    private:
        string accrequestattribute;
    public:
        ARTpacket():Packet(){
            setpPinfo("Access Request Attribute\n");  
            accrequestattribute = "undefined";
        };
        string getArt() const { return accrequestattribute; }
        void setArt(const string &x) { accrequestattribute = x; }


};

class DTTpacket: public Packet {
    private:
        string dttmessage;

    public:
        DTTpacket():Packet(){
            setpPinfo("Data Transmission packet\n");
            dttmessage = "undefined";
        };
        string getDtt() const { return dttmessage; }
        void setDtt(const string &dttmessage_) { dttmessage = dttmessage_; }
};
