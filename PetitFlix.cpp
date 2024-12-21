#include "PetitFlix.h"

PetitFlix& PetitFlix::getInstance(){
    if (_ins == nullptr) {
        _ins = new PetitFlix();
    }
    return *_ins;
}

PetitFlix* PetitFlix::_ins = nullptr;
PassarelaUsuari* PetitFlix::_usuari = nullptr;


PassarelaUsuari* PetitFlix::obteUsuari() const{
   return _usuari;
}

void PetitFlix::iniciaSessio(PassarelaUsuari u){
    *_usuari = u;
}

void PetitFlix::tancaSessio(){
    delete _usuari;
    _usuari = nullptr;
}