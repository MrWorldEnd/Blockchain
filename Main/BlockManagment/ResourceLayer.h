#include <iostream>
#include "Objects.h"


bool validateTx(Objects user,Objects item){
    bool result = false;
    if (user.getaccesslvl() > item.getaccesslvl())
        result = true;
    return result;
}




