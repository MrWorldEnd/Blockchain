#include <stdio.h>
#include <ctime>
#include <string>

using namespace std;
//transaction packet

class Payload {
    private:
        string subjectID;
        string objlvl;
        string objID;
        string subjlvl;

    public:

        void setSbjID();
        void setSubjectID(const string &x) { subjectID = x; }
        void setObjlvl(const string &x) { objlvl = x; }
        void setObjID(const string &x) { objID = x; }
        void setSubjlvl(const string &x) { subjlvl = x; }
        
        string getSubjectID() const { return subjectID; }
        string getObjlvl() const { return objlvl; }
        string getObjID() const { return objID; }
        string getSubjlvl() const { return subjlvl; }
};

class ARTpayload: public Payload {
    private:
        string accrequestattribute;
    public:
        string getAccrequestattribute() const { return accrequestattribute; }
        void setAccrequestattribute(const string &x) { accrequestattribute = x; }
};

class DTTpayload: public Payload {
    private:
        string dttmessage;

    public:
        string getDttmessage() const { return dttmessage; }
        void setDttmessage(const string &dttmessage_) { dttmessage = dttmessage_; }
};

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

struct Packet {
    private:
        Header header;
        Payload payload;
};