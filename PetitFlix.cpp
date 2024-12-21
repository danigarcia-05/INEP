#include "PetitFlix.h"

PetitFlix* PetitFlix::_ins = nullptr;
PassarelaUsuari* PetitFlix::_usuari = nullptr;

PetitFlix::PetitFlix() : _usuari(nullptr){
}

PetitFlix& PetitFlix::getInstance() {
    if (_ins == nullptr) {
        _ins = new PetitFlix();
    }
    return *_ins;
}

// En PetitFlix.cpp
PassarelaUsuari* PetitFlix::obteUsuari() {
    return _usuari;  // O la lógica que desees aquí
}

void PetitFlix::iniciaSessio(PassarelaUsuari u){
   if (_usuari == nullptr) {
        _usuari = new PassarelaUsuari(u); 
    } else {
        *_usuari = u;  
    }
}

void PetitFlix::tancaSessio(){
    delete _usuari;
    _usuari = nullptr;
}
