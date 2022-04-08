#include <stdio.h>
#include <ctime>
#include <string>
#include "PacketHeader.h"

using namespace std;
//transaction packet

class Packet {
    private:
        PacketHeader pheader;
    public:
        void setpHeader(PacketHeader ph){
            pheader= ph;
        }
};

class ARTpacket: public Packet {
    private:
        string accrequestattribute;
    public:
        ARTpacket(){
            accrequestattribute = "accrequestattribute";
        };
        string getAccrequestattribute() const { return accrequestattribute; }
        void setAccrequestattribute(const string &x) { accrequestattribute = x; }
};

class DTTpacket: public Packet {
    private:
        string dttmessage;

    public:
        string getDttmessage() const { return dttmessage; }
        void setDttmessage(const string &dttmessage_) { dttmessage = dttmessage_; }
};
/* 
 struct Header {
    string txHash;
    string txAddr;
    string txSigICPMSig;

    string getTxHash() const { return txHash; }
    string getTxAddr() const { return txAddr; }
    string getTxSigICPMSig() const { return txSigICPMSig; }
    void setTxHash(const string &x) { txHash = x; }
    void setTxAddr(const string &x) { txAddr = x; }
    void setTxSigICPMSig(const string &x) { txSigICPMSig = x; }
 };
 */