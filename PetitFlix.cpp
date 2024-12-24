#include "PetitFlix.h"

PetitFlix* PetitFlix::_ins = nullptr;
PassarelaUsuari* PetitFlix::_usuari = nullptr;


PetitFlix::PetitFlix(){}

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

void PetitFlix::modificaUsuari(string nom, string contrasenya, string dataN, string correuE, string modalitatS) {
    _usuari->setNom(nom);
    _usuari->setContrasenya(contrasenya);
    _usuari->setCorreuElectronic(correuE);
    _usuari->setDataNaixament(dataN);
    _usuari->setModalitatSubscripcio(modalitatS);
}

void PetitFlix::modificaContrasenya(string contrasenya) {
    _usuari->setContrasenya(contrasenya);
}

