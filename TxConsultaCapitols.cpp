#include "TxConsultaCapitols.h"


TxConsultaCapitols::TxConsultaCapitols() {

}

void TxConsultaCapitols::executar(string nomS, int numTemporada) {
    CercadoraCapitol cercadoraC;
    vector<PassarelaCapitol> cjCapitols = cercadoraC.cercaCapitolsTemporada(nomS, numTemporada);
    string titolSerie, titol, dataEstrena, qualificacio, modalitat;
    int numTemp, numero, duracio;

    vector<DTOCapitol> resultat;
    for (size_t  i = 0; i < cjCapitols.size(); ++i) {
        titolSerie = cjCapitols[i].obteTitolSerie();
        titol = cjCapitols[i].obteTitol();
        dataEstrena = convertitADDMMYYYY(cjCapitols[i].obteDataEstrena());
        qualificacio = cjCapitols[i].obteQualificacio();
        numTemp = cjCapitols[i].obteNumTemporada();
        numero = cjCapitols[i].obteNumero();
        duracio = cjCapitols[i].obteDuracio();
        modalitat = cjCapitols[i].obteModalitat();
        DTOCapitol capitol(titolSerie, numTemp, numero, titol, dataEstrena, qualificacio, duracio, modalitat);
        resultat.push_back(capitol);
    }
    _capitols = resultat;
}

vector<DTOCapitol> TxConsultaCapitols::obteResultat() {
    return _capitols;
}




