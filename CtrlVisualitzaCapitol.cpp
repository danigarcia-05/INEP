#include "CtrlVisualitzaCapitol.h"


CtrlVisualitzaCapitol::CtrlVisualitzaCapitol() {

}

int CtrlVisualitzaCapitol::obteNumTemporades(string nomS){
    CercadoraTemporada cercadoraTemporada;
    _temporades = cercadoraTemporada.cercaTemporades(nomS);
    return _temporades.size();
}

vector<DTOCapitol> CtrlVisualitzaCapitol::obteCapitolsTemp(string nomS, int numTemporada) {
    if (numTemporada > _temporades.size()) throw runtime_error("TemporadaNoExisteix");
    TxConsultaCapitols txConsultaCapitols;
    txConsultaCapitols.executar(nomS, numTemporada);
    _capitols = txConsultaCapitols.obteCapitols();
    return txConsultaCapitols.obteResultat();
}

string CtrlVisualitzaCapitol::consultaSerieUsuari(string titolS, int numTemporada, int numCapitol) {
    PetitFlix& petitFlix = PetitFlix::getInstance();
    PassarelaUsuari usuari = *(petitFlix.obteUsuari());
    string sobrenomU = usuari.obteSobrenom();
  
    int mida = _capitols.size();
    if (numCapitol > mida) throw runtime_error("CapitolNoExisteix");

    cout << utils::convertitADDMMYYYY(_capitols[numCapitol].obteDataEstrena()) << "-----------" << utils::convertitADDMMYYYY(utils::dataActual()) << endl;
    utils::espera(2000);
    if (utils::dataMesGran(utils::convertitADDMMYYYY(_capitols[numCapitol].obteDataEstrena()), utils::convertitADDMMYYYY(utils::dataActual()))) {
        throw runtime_error("CapitolNoEstrenat");
    }
    if (not utils::esContingutApteEdat(utils::convertitADDMMYYYY(_capitols[numCapitol].obteDataEstrena()), utils::convertitADDMMYYYY(usuari.obteDataNaixament()))) throw runtime_error("SerieNoApropiada");
    
    cout << "1" << endl;
    cout << numCapitol << endl;
    utils::espera(2000);

    TxConsultaVisualitzacioCapitol txConsultaVisualitzacioCapitol;
    txConsultaVisualitzacioCapitol.executar(sobrenomU, titolS, numTemporada, numCapitol);
    _capitolUsuari = txConsultaVisualitzacioCapitol.obteVisualitzacioCapitol();

    return sobrenomU;
}

void CtrlVisualitzaCapitol::visualitzaCapitol(string sobrenomU, string titolS, int numTemporada, int numCapitol){
    if (_capitolUsuari.obteTitolSerie() == "") {
        PassarelaVisualitzaCapitol visualitzacio(sobrenomU, titolS, 1, numTemporada, numCapitol, utils::dataActual());
        visualitzacio.insereix();
    }
    else {
        _capitolUsuari.setNumVisualitzacions(_capitolUsuari.obteNumVisualitzacions() + 1);
        _capitolUsuari.setData(utils::dataActual());
        _capitolUsuari.modifica();
    }
}

