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

PassarelaVisualitzaCapitol TxConsultaVisualitzacioCapitol::obteVisualitzacioCapitol() {
    return _capitolVisualitzat;
}

DTOVisualitzacioCapitol TxConsultaVisualitzacioCapitol::obteResultat(){
    return _resultat;
}