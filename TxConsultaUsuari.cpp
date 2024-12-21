#include "TxConsultaUsuari.h"

TxConsultaUsuari::TxConsultaUsuari(){

}

void TxConsultaUsuari::executar(){
    PetitFlix& petitFlix = PetitFlix::getInstance();
    PassarelaUsuari usuari = petitFlix.obteUsuari();
    
    string nomU, sobrenomU, correuU, modalitatU, dataNaixementU;
    nomU = usuari.obteNom();
    sobrenomU = usuari.obteSobrenom();
    correuU = usuari.obteCorreuElectronic();
    dataNaixementU = usuari.obteDataNaixament();
    modalitatU = usuari.obteModalitatSubscripcio();

    DTOUsuari resultat(nomU, sobrenomU, correuU, dataNaixementU, modalitatU);
    _resultat = resultat;
}
DTOUsuari TxConsultaUsuari::obteResultat(){
    return _resultat;
}

PassarelaUsuari TxConsultaUsuari::obteUsuari(){
    return _usuari;
}