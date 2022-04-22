#include <iostream>
#include "Objects.h"
#include "Packet.h"


bool validateTx(Objects user,Objects item){
    bool result = false;
    if (user.getaccesslvl() > item.getaccesslvl())
        result = true;
    return result;
}

PacketHeader genPacketHeader(Objects user,Objects item){
    PacketHeader x = PacketHeader(user.getid(),user.getaccesslvl(),item.getid(),item.getaccesslvl());
    return x;
}


