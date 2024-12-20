#include "TxRegistraUsuari.h"

TxRegistraUsuari::TxRegistraUsuari(string nU, string sU, string cU, string ceU, data dnU, subscripcio msU) {
    _nomU = nU;
    _sobrenomU = sU;
    _contrasenyaU = cU;
    _correuElectronicU = ceU;
    _dataNaixement = dnU;
    _modalitatSubscripcio = msU;
}


void TxRegistraUsuari::executar() {
    try{
        PassarelaUsuari u(_nomU, _sobrenomU, _contrasenyaU, _correuElectronicU, _dataNaixement, _modalitatSubscripcio); 
        u.insereix();
    }
    catch (const exception& e) {
        string error_msg = e.what();
        if(error_msg == "SobrenomExisteix") runtime_error();
        else if(error_msg == "CorreuExisteix") runtime_error();
        else if(error_msg == "ModalitatNoExisteix") runtime_error();
    }
    
}