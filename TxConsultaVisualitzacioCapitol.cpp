#include "TxConsultaVisualitzacioCapitol.h"

TxConsultaVisualitzacioCapitol::TxConsultaVisualitzacioCapitol() {
    
}

void TxConsultaVisualitzacioCapitol::executar(string sobrenomU, string titolSerie, int numTemporada, int numero) {
    CercadoraVisualitzaCapitol cercadoraCapitol;
    _capitolVisualitzat = cercadoraCapitol.cercaVisualitzaCapitol(sobrenomU, titolSerie, numTemporada, numero);

    string sobrenom, titolS, data;
    int numTemp, numCapitol, numVisualitzacio;

    sobrenom = _capitolVisualitzat.obteSobrenom();
    titolS = _capitolVisualitzat.obteTitolSerie();
    data = _capitolVisualitzat.obteData();
    numTemp = _capitolVisualitzat.obteNumTemporada();
    numCapitol = _capitolVisualitzat.obteNumCapitol();
    numVisualitzacio = _capitolVisualitzat.obteNumVisualitzacions();

    DTOVisualitzacioCapitol resultat(sobrenom, titolS, numTemp, numCapitol, data, numVisualitzacio);
    _resultat = resultat;
}

void TxConsultaVisualitzacioCapitol::executarCV(string sobrenomU) {
    CercadoraVisualitzaCapitol cercadoraVisualitzaCapiol;
    _cjVisualitzacioCapitol = cercadoraVisualitzaCapiol.cercaVisualitzaCapitolsUsuari(sobrenomU);
    
    string sobrenom, titolS, data;
    int numTemp, numCapitol, numVisualitzacio;
    for (int i = 0; i < _cjVisualitzacioCapitol.size(); ++i) {
        sobrenom = _cjVisualitzacioCapitol[i].obteSobrenom();
        titolS = _cjVisualitzacioCapitol[i].obteTitolSerie();
        data = utils::dataAmbHora(_cjVisualitzacioCapitol[i].obteData());
        numTemp = _cjVisualitzacioCapitol[i].obteNumTemporada();
        numCapitol = _cjVisualitzacioCapitol[i].obteNumCapitol();
        numVisualitzacio = _cjVisualitzacioCapitol[i].obteNumVisualitzacions();
        DTOVisualitzacioCapitol resultat(sobrenom, titolS, numTemp, numCapitol, data, numVisualitzacio);
        _capitolsVisualitzats.push_back(resultat);
    }
}

PassarelaVisualitzaCapitol TxConsultaVisualitzacioCapitol::obteVisualitzacioCapitol() {
    return _capitolVisualitzat;
}

DTOVisualitzacioCapitol TxConsultaVisualitzacioCapitol::obteResultat(){
    return _resultat;
}

vector<DTOVisualitzacioCapitol> TxConsultaVisualitzacioCapitol::obteCapitolsVisualitzats() {
    return _capitolsVisualitzats;
}

vector<PassarelaVisualitzaCapitol> TxConsultaVisualitzacioCapitol::obteConjuntVisualitzacionsCapitols() {
    return _cjVisualitzacioCapitol;
}    