#include "CtrlVisualitzaCapitol.h"


CtrlVisualitzaCapitol::CtrlVisualitzaCapitol() {

}

CtrlVisualitzaCapitol::~CtrlVisualitzaCapitol() {

}


int CtrlVisualitzaCapitol::obteNumTemporades(string nomS){
    CercadoraTemporada& cercadoraTemporada = CercadoraTemporada::getInstance();
    _temporades = cercadoraTemporada.cercaTemporades(nomS);
    return _temporades.size();
}

vector<DTOCapitol> CtrlVisualitzaCapitol::obteCapitolsTemp(string nomS, int numTemporada) {
    if (numTemporada > _temporades.size() or numTemporada <= 0) throw runtime_error("TemporadaNoExisteix");
    TxConsultaCapitols txConsultaCapitols;
    txConsultaCapitols.executar(nomS, numTemporada);
    _capitols = txConsultaCapitols.obteCapitols();
    return txConsultaCapitols.obteResultat();
}

void CtrlVisualitzaCapitol::consultaSerieUsuari(string titolS, int numTemporada, int numCapitol) {
    PetitFlix& petitFlix = PetitFlix::getInstance();
    _usuari = *(petitFlix.obteUsuari());
    string sobrenomU = _usuari.obteSobrenom();

    if (_usuari.obteModalitatSubscripcio() == "Infantil" and _capitols[numCapitol - 1].obteModalitat() != "Infantil") {
        throw runtime_error("ModalitatIncorrecta");
    }
    if (_usuari.obteModalitatSubscripcio() != "Completa" and _usuari.obteModalitatSubscripcio() != "Infantil") {
        throw runtime_error("ModalitatIncorrecta");
    }
  
    int mida = _capitols.size();
    if (numCapitol > mida) throw runtime_error("CapitolNoExisteix");

    if (utils::dataMesGran(utils::convertitADDMMYYYY(_capitols[numCapitol-1].obteDataEstrena()), utils::convertitADDMMYYYY(utils::dataActual()))) {
        throw runtime_error("CapitolNoEstrenat");
    }
    if (not utils::esContingutApteEdat(utils::convertitADDMMYYYY(_capitols[numCapitol-1].obteDataEstrena()), utils::convertitADDMMYYYY(_usuari.obteDataNaixament()))) throw runtime_error("SerieNoApropiada");

    TxConsultaVisualitzacioCapitol txConsultaVisualitzacioCapitol;
    txConsultaVisualitzacioCapitol.executar(sobrenomU, titolS, numTemporada, numCapitol);
    _capitolUsuari = txConsultaVisualitzacioCapitol.obteVisualitzacioCapitol();
}

void CtrlVisualitzaCapitol::visualitzaCapitol(string titolS, int numTemporada, int numCapitol){
    if (_capitolUsuari.obteTitolSerie() == "") {
        PassarelaVisualitzaCapitol visualitzacio(_usuari.obteSobrenom(), titolS, 1, numTemporada, numCapitol, utils::dataActual());
        visualitzacio.insereix();
    }
    else {
        _capitolUsuari.setNumVisualitzacions(_capitolUsuari.obteNumVisualitzacions() + 1);
        _capitolUsuari.setData(utils::dataActual());
        _capitolUsuari.modifica();
    }
}

