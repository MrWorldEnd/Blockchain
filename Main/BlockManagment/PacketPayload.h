#include <stdio.h>
#include <string>

using namespace std;
//transaction packet
struct PacketPayload
{
    
    int subjectID;
    int subjlvl;
    int objlvl;
    int objID;

    PacketPayload()
    {
        subjectID = 0;
        objlvl = 0;
        objID = 0;
        subjlvl = 0;
    };
    PacketPayload(int x, int y, int z, int v)
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

        string getPayloadstr(){
            string x;
            x = "User Info: {" + to_string(subjectID) + "," + to_string(subjlvl) + "}\n";
            x = x + "Object Info: {" + to_string(objID) + "," + to_string(objlvl) + "}\n";
            return x;
        }
};