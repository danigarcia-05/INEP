#include "TxRegistraUsuari.h"

TxRegistraUsuari::TxRegistraUsuari(string nU, string sU, string cU, string ceU, string dnU, string msU) {
    _nomU = nU;
    _sobrenomU = sU;
    _contrasenyaU = cU;
    _correuElectronicU = ceU;
    _dataNaixement = dnU;
    _modalitatSubscripcio = msU;
}

void TxRegistraUsuari::executar() {
    PassarelaUsuari u(_nomU, _sobrenomU, _contrasenyaU, _correuElectronicU, _dataNaixement, _modalitatSubscripcio); 
    u.insereix();
}
