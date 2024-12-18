#include "PetitFlix.h"

PetitFlix* PetitFlix::getins(){
    if (ins == nullptr) {
        ins = new PetitFlix();
    }
    return ins;
}

PetitFlix* PetitFlix::ins = nullptr;