#include <iostream>
#include <cstring>
 
using namespace std;

 struct Header {
    string txHash;
    string txAddr;
    string txSigICPMSig;
 };

 struct ARTPayload {
    string subjectID;
    string objlvl;
    string objID;
    string subjlvl;
    string accrequestattribute;
 };

 struct DTTPayload {
    string subjectID;
    string objlvl;
    string objID;
    string subjlvl;
    //ObjectDataTransfer to add
 };