#include <iostream>
#include "Objects.h"
#include "PacketPayload.h"


bool validateTx(Objects user,Objects item){
    bool result = false;
    if (user.getaccesslvl() > item.getaccesslvl())
        result = true;
    return result;
}

//needs to form payload

PacketPayload genPacketHeader(Objects user,Objects item){
    PacketPayload x = PacketPayload(user.getid(),user.getaccesslvl(),item.getid(),item.getaccesslvl());
    return x;
}


