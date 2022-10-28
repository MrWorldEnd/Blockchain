#include <iostream>

using namespace std;

 struct TxHeader {
    string txHash;
    string txAddr;
    string txSigICPMSig;

    string timestamp;
    string receiverKey;
    string senderKey;

    string gettimestamp() const {return timestamp;}
    string getreceiverKey() const {return receiverKey;}
    string getsenderKey() const {return senderKey;}

    void settimestamp(const string x)  {timestamp = x;}
    void setreceiverKey(const string x)  {receiverKey = x;}
    void setsenderKey(const string x)  {senderKey = x;}

    string getTxHash() const { return txHash; }
    string getTxAddr() const { return txAddr; }
    string getTxSigICPMSig() const { return txSigICPMSig; }
    void setTxHash(const string &x) { txHash = x; }
    void setTxAddr(const string &x) { txAddr = x; }
    void setTxSigICPMSig(const string &x) { txSigICPMSig = x; }
 };


