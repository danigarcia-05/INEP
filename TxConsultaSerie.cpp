#include "TxConsultaSerie.h"

TxConsultaSerie::TxConsultaSerie(){

}

void TxConsultaSerie::executar(){
    PetitFlix& petitFlix = PetitFlix::getInstance();
    _serie = *(petitFlix.obteSerie());
    int temp=_serie.obteT

    string _sobrenom;
    string _titolSerie;
    int _numVisualitzacions;
    int _numTemporada;
    int _numCapitol;
    string _data;

    string nomU, sobrenomU, correuU, modalitatU, dataNaixementU;
    nomU = _usuari.obteNom();
    sobrenomU = _usuari.obteSobrenom();
    correuU = _usuari.obteCorreuElectronic();
    dataNaixementU = _usuari.obteDataNaixament();
    modalitatU = _usuari.obteModalitatSubscripcio();

    DTOUsuari resultat(nomU, sobrenomU, correuU, dataNaixementU, modalitatU);
    _resultat = resultat;
}
DTOUsuari TxConsultaSerie::obteResultat(){
    return _resultat;
}

PassarelaUsuari TxConsultaSerie::obteUsuari(){
    return _serie;
}