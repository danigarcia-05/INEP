#include "TxConsultaUsuari.h"

TxConsultaUsuari::TxConsultaUsuari(){

}

void TxConsultaUsuari::executar(){
    PetitFlix& petitFlix = PetitFlix::getInstance();
    _usuari = *(petitFlix.obteUsuari());
    
    string nomU, sobrenomU, correuU, modalitatU, dataNaixementU;
    nomU = _usuari.obteNom();
    sobrenomU = _usuari.obteSobrenom();
    correuU = _usuari.obteCorreuElectronic();
    dataNaixementU = _usuari.obteDataNaixament();
    modalitatU = _usuari.obteModalitatSubscripcio();

    DTOUsuari resultat(nomU, sobrenomU, correuU, dataNaixementU, modalitatU);
    _resultat = resultat;
}
DTOUsuari TxConsultaUsuari::obteResultat(){
    return _resultat;
}

PassarelaUsuari TxConsultaUsuari::obteUsuari(){
    return _usuari;
}