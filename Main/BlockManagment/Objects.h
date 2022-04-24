//
// Created by mrworldend on 19/voidvoidvoidvoid04/22.
//
#include <iostream>
#include <vector>

class Objects
{
    private:
        int id;
        int accesslvl;
    public:
        void setid(int x){id = x;};
        int getid(){return id;};

        void setaccesslvl(int x){accesslvl = x;};
        int getaccesslvl(){return accesslvl;};
        
        Objects(){
            setaccesslvl(0);
            setid(0);
        }

        Objects(int x, int y){
            setaccesslvl(x);
            setid(y);
        }
};
class IotDevice : public Objects
{
    private:
        char state;
    public:
        void turnOn(){state = 1;}
        void turnOff(){state = 0;}

        char getstate() {return state;}
};

struct Request
{
    Objects user;
    Objects iotDevice;
};
