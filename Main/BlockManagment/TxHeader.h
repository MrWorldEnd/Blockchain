#include <iostream>

using namespace std;

 struct TxHeader {
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


