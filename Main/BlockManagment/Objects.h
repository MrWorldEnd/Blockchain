//
// Created by mrworldend on 19/voidvoidvoidvoid04/22.
//
#include <iostream>
#include <vector>

class devides
{
    private:
        int id;
        int accesslvl;
    public:
        void setid(int x){id = x;};
        int getid(){return id;};

        void setaccesslvl(int x){accesslvl = x;};
        int getaccesslvl(){return accesslvl;};
        
        devides(){
            setaccesslvl(0);
            setid(0);
        }

        devides(int x, int y){
            setaccesslvl(x);
            setid(y);
        }
};
class IotDevice : public devides
{
    private:
        char state;
    public:
        void turnOn(){state = 1;}
        void turnOff(){state = 0;}

        char getstate() {return state;}

        void toggle(){
            if(state == 1){turnOff();}
            else{turnOff();};}
};

struct Request
{
    devides user;
    devides iotDevice;
};
