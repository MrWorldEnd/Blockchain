#include <stdio.h>
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
        Packet(){
            pheader = TxHeader();
            pinfo = "Undefined Packet";
            payload = PacketPayload();
        }
        Packet(Device user, Device item){
            pheader= TxHeader();
            
            pheader.setreceiverKey();
            pheader.setsenderKey();
            pheader.settimestamp();
            pheader.setTxAddr();


            payload = PacketPayload();

            payload.setObjID(item.getid());
            payload.setObjlvl(item.getaccesslvl());
            payload.setSubjectID(user.getid());
            payload.setSubjlvl(user.getaccesslvl());

            pinfo = "Undefined Packet";
            if(validateTx(user,item)){
                pinfo = "invalid packet";
            }
            
        }
        virtual bool validateTx(Device user,Device item){
            bool result = false;
            
            if (user.getaccesslvl() > item.getaccesslvl())
                result = true;
            return result;
        }
        virtual void setpHeader(TxHeader ph){
            pheader= ph;
        }
        virtual void setpPinfo(string x){
            pinfo= x;
        }
        virtual void setpayload(PacketPayload x){
            payload = x;
        }

        virtual string getPinfo(){
            return pinfo;
        }

        virtual PacketPayload getPayload(){return payload;}
        virtual TxHeader getheader(){return pheader;}

        virtual string packetStr(){
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
        string getArt() const { return accrequestattribute;}
        void setArt(const string &x) { accrequestattribute = x;}

        

        



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
