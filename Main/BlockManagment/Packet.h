#include <stdio.h>
#include <ctime>
#include <string>
#include "TxHeader.h"

using namespace std;
//transaction packet

class Packet {
    private:
        TxHeader pheader;
        string pinfo;
    public:
        void setpHeader(TxHeader ph){
            pheader= ph;
        }
        void setpPinfo(string x){
            pinfo= x;
        }
};

class ARTpacket: public Packet {
    private:
        string accrequestattribute;
    public:
        ARTpacket():Packet(){
            setpPinfo("access request attribute");  
        };
        string getAccrequestattribute() const { return accrequestattribute; }
        void setAccrequestattribute(const string &x) { accrequestattribute = x; }
};

class DTTpacket: public Packet {
    private:
        string dttmessage;

    public:
        DTTpacket():Packet(){
            setpPinfo("Data Transmission packet");
        };
        string getDttmessage() const { return dttmessage; }
        void setDttmessage(const string &dttmessage_) { dttmessage = dttmessage_; }
};
/* 

 */
