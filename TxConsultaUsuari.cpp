#include "TxConsultaUsuari.h"

TxConsultaUsuari::TxConsultaUsuari(){

}

//DOBLE BARRA
bool TxConsultaUsuari::executar(){
    PetitFlix& petitFlix = PetitFlix::getInstance();
    if (petitFlix.obteUsuari() == nullptr) return false;
    _usuari = *(petitFlix.obteUsuari());

    string nomU, sobrenomU, correuU, modalitatU, dataNaixementU;
    nomU = _usuari.obteNom();
    sobrenomU = _usuari.obteSobrenom();
    correuU = _usuari.obteCorreuElectronic();

    dataNaixementU = utils::convertitADDMMYYYY(_usuari.obteDataNaixament()); // DOBRE BARRA --> FUNCION?
    modalitatU = _usuari.obteModalitatSubscripcio();

    DTOUsuari resultat(nomU, sobrenomU, correuU, dataNaixementU, modalitatU);
    _resultat = resultat;
    return true;
}
DTOUsuari TxConsultaUsuari::obteResultat(){
    return _resultat;
}

PassarelaUsuari TxConsultaUsuari::obteUsuari(){
    return _usuari;
}