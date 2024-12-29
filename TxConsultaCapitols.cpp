#include "TxConsultaCapitols.h"


TxConsultaCapitols::TxConsultaCapitols() {

}

void TxConsultaCapitols::executar(string nomS, int numTemporada) {
    CercadoraCapitol cercadoraC;
    _capitols = cercadoraC.cercaCapitolsTemporada(nomS, numTemporada);
    string titolSerie, titol, dataEstrena, qualificacio, modalitat;
    int numTemp, numero, duracio;

    vector<DTOCapitol> resultat;
    unsigned int mida = _capitols.size();
    for (unsigned int i = 0; i < mida; ++i) {
        titolSerie = _capitols[i].obteTitolSerie();
        titol = _capitols[i].obteTitol();
        dataEstrena = convertitADDMMYYYY(_capitols[i].obteDataEstrena());
        qualificacio = _capitols[i].obteQualificacio();
        numTemp = _capitols[i].obteNumTemporada();
        numero = _capitols[i].obteNumero();
        duracio = _capitols[i].obteDuracio();
        modalitat = _capitols[i].obteModalitat();
        DTOCapitol capitol(titolSerie, numTemp, numero, titol, dataEstrena, qualificacio, duracio, modalitat);
        resultat.push_back(capitol);
    }
    _resultat = resultat;
}

vector<DTOCapitol> TxConsultaCapitols::obteResultat() {
    return _resultat;
}

vector<PassarelaCapitol> TxConsultaCapitols::obteCapitols() {
    return _capitols;
}




