#include <iostream>
#include "Objects.h"

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

bool validateTx(Objects user,Objects item){
    bool result = false;
    if (user.getaccesslvl() > item.getaccesslvl())
        result = true;
    return result;
}

