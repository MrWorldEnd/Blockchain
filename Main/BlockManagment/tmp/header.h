#include <iostream>
 
using namespace std;
//transaction packet

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

    friend std::ostream& operator<<(std::ostream &out, Header h);
 };
ostream& operator<<(std::ostream &out, Header h)
{
    out << h.getTxAddr << " " << h.getTxSigICPMSig << " " << h.getTxHash;
    return out;
}