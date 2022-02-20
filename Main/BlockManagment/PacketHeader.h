#include <stdio.h>
#include <string>

using namespace std;
//transaction packet
struct PacketHeader
{
    
    string subjectID;
    string objlvl;
    string objID;
    string subjlvl;
    PacketHeader()
    {
        subjectID = "testHeaderID";
        objlvl = "testHeaderObjectLevel";
        objID = "testHeaderObjectID";
        subjlvl = "testHeadersubjectlvl";
    };
    PacketHeader(string x, string y, string z, string v)
    {
        subjectID = x;
        objlvl = y;
        objID = z;
        subjlvl = v;
    };

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