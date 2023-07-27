#include <stdio.h>
#include <string>

#include "device.h"

using namespace std;
//transaction packet
class PacketPayload
{
       
    private:
        int subjectID;
        int subjlvl;
        int objlvl;
        int objID;
    public:
        PacketPayload()
        {
            subjectID = 0;
            objlvl = 0;
            objID = 0;
            subjlvl = 0;
        };
        PacketPayload(Device object, Device subject)
        {
            objID = object.getid();
            objlvl = object.getaccesslvl();
            subjectID = subject.getid();
            subjlvl = subject.getaccesslvl();
        }        
        PacketPayload(int x, int y, int z, int v)
        {
            objID = x;
            objlvl = y;
            subjectID = z;
            subjlvl = v;
        };

        void setObject(IotDevice object)
        {
            objID = object.getid();
            objlvl = object.getaccesslvl();
        }
        void setSubject(Device subject)
        {
            objID = subject.getid();
            objlvl = subject.getaccesslvl();
        }

        void setSubjectID(const int &x) { subjectID = x; }
        void setSubjlvl(const int &x) { subjlvl = x; }
        void setObjlvl(const int &x) { objlvl = x; }
        void setObjID(const int &x) { objID = x; }

        int getSubjectID() const { return subjectID; }
        int getSubjlvl() const { return subjlvl; }
        int getObjlvl() const { return objlvl; }
        int getObjID() const { return objID; }
            
        string getPayloadstr()
        {
            string x;
            x = "User Info: {" + to_string(subjectID) + "," + to_string(subjlvl) + "}\n";
            x = x + "Object Info: {" + to_string(objID) + "," + to_string(objlvl) + "}\n";
            x = x + to_string(isvalidreq());
            return x;
        }

        bool isvalidreq()
        {
            if (subjlvl >= objlvl)
                return true;
            return false;
        }
};
