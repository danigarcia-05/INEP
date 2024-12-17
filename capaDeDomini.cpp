#pragma once
#include "capaDeDomini.h"

CapaDeDomini* CapaDeDomini::getins(){
    if (ins == nullptr) {
        ins = new CapaDeDomini();
    }
    return ins;
}

CapaDeDomini* CapaDeDomini::ins = nullptr;