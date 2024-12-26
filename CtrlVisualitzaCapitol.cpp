#include "CtrlVisualitzaCapitol.h"


CtrlVisualitzaCapitol::CtrlVisualitzaCapitol() {

}


int CtrlVisualitzaCapitol::obteNumTemporades(string nomS){
    CercadoraTemporada cercadoraTemporada;
    vector<PassarelaTemporada> vP = cercadoraTemporada.cercaTemporades(titolS);
    return vP.size();
}


void CtrlVisualitzaCapitol::obteCapitols(string titolS, int numTemporada){
    TxConsultaCapitols txConsultaCapitols;
    _capitols = txConsultaCapitols.consulta(titolS, numTemporada);
}


vector<DTOCapitol> CtrlVisualitzaCapitol::obteResultatCapitols() {
    return _capitols;
}


string CtrlVisualitzaCapitol::consultaSerieUsuari(string titolS, int numTemporada, int numCapitol) {
    PetitFlix& petitFlix = PetitFlix::getInstance();
    PassarelaUsuari usuari = *(petitFlix.obteUsuari());
    string sobrenomU = usuari.obteSobrenom();
    TxConsultaVisualitzacioCapitol txConsultaVisualitzacioCapitol;
    txConsultaVisualitzacioCapitol.executar(sobrenomU, titolS, numTemporada, numCapitol);
    _capitolUsuari = txConsultaVisualitzacioCapitol.obteCapitol();
    return sobrenomU;
}

void CtrlVisualitzaCapitol::visualitzaCapitol(string sobrenomU, string titolS, int numTemporada, int numCapitol){
    if (_capitolUsuari.obteTitolSerie() == "") {
        PassarelaVisualitzaSerie visualitzacio(sobrenomU, titolS, numTemporada, numCapitol, utils::dataActual(), 1);
        visualitzacio.insereix();
    }
    else {
        _capitolUsuari.setNumVisualitzacions(_capitolUsuari.obteNumVisualitzacions() + 1);
        _capitolUsuari.setData(utils::dataActual());
        _capitolUsuari.modifica();
    }
}

