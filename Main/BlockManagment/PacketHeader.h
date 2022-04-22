#include <stdio.h>
#include <string>

using namespace std;
//transaction packet
struct PacketHeader
{
    
    int subjectID;
    int objlvl;
    int objID;
    int subjlvl;
    PacketHeader()
    {
        subjectID = 0;
        objlvl = 0;
        objID = 0;
        subjlvl = 0;
    };
    PacketHeader(int x, int y, int z, int v)
    {
        objID = x;
        objlvl = y;
        subjectID = z;
        subjlvl = v;
    };

        void setSbjID();
        void setSubjectID(const int &x) { subjectID = x; }
        void setObjlvl(const int &x) { objlvl = x; }
        void setObjID(const int &x) { objID = x; }
        void setSubjlvl(const int &x) { subjlvl = x; }

        int getSubjectID() const { return subjectID; }
        int getObjlvl() const { return objlvl; }
        int getObjID() const { return objID; }
        int getSubjlvl() const { return subjlvl; }
};