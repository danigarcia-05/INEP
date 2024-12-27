#include "CtrlVisualitzaCapitol.h"


CtrlVisualitzaCapitol::CtrlVisualitzaCapitol() {

}

int CtrlVisualitzaCapitol::obteNumTemporades(string nomS){
    CercadoraTemporada cercadoraTemporada;
    vector<PassarelaTemporada> vP = cercadoraTemporada.cercaTemporades(nomS);
    return vP.size();
}

vector<DTOCapitol> CtrlVisualitzaCapitol::obteCapitolsTemp(string nomS, int numTemporada) {
    TxConsultaCapitols txConsultaCapitols;
    txConsultaCapitols.executar(nomS, numTemporada);
    return txConsultaCapitols.obteResultat();
}

string CtrlVisualitzaCapitol::consultaSerieUsuari(string titolS, int numTemporada, int numCapitol) {
    PetitFlix& petitFlix = PetitFlix::getInstance();
    PassarelaUsuari usuari = *(petitFlix.obteUsuari());
    string sobrenomU = usuari.obteSobrenom();
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

