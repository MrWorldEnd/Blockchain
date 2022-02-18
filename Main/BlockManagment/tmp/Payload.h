#include <iostream>
 
using namespace std;

class Payload {
    private:
        string subjectID;
        string objlvl;
        string objID;
        string subjlvl;

        string packetype;

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


        friend std::ostream& operator<<(std::ostream &out, Payload x);
};

ostream& operator<<(ostream &out, Payload x)
{
    out << "Object ID: "<< x.getObjID << " Object level: " << x.getObjlvl << " Subject ID: " << x.getSubjectID <<" Subject level: " <<  x.getSubjlvl;
    return out;
}

class ARTpayload: public Payload {
    private:
        string accrequestattribute;
    public:
        string getAccrequestattribute() const { return accrequestattribute; }
        void setAccrequestattribute(const string &x) { accrequestattribute = x; }

        friend std::ostream& operator<<(std::ostream &out, ARTpayload x);
};
ostream& operator<<(ostream &out, ARTpayload x)
{
    out << "Object ID: "<< x.getObjID << " Object level: " << x.getObjlvl << " Subject ID: " << x.getSubjectID <<" Subject level: " <<  x.getSubjlvl << " ART packet ";
    return out;
}

class DTTpayload: public Payload {
    private:
        string dttmessage;

    public:
        string getDttmessage() const { return dttmessage; }
        void setDttmessage(const string &dttmessage_) { dttmessage = dttmessage_; }

        friend std::ostream& operator<<(std::ostream &out, DTTpayload x);
};
ostream& operator<<(ostream &out, DTTpayload x)
{
    out << "Object ID: "<< x.getObjID << " Object level: " << x.getObjlvl << " Subject ID: " << x.getSubjectID <<" Subject level: " <<  x.getSubjlvl << " DTT packet ";
    return out;;
    return out;
}
