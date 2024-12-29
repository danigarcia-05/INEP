#include "TxProperesEstrenes.h"

TxProperesEstrenes::TxProperesEstrenes() {

}

void TxProperesEstrenes::executar(string mod) {
    CercadoraPelicula cercadoraP;
    vector<PassarelaPelicula> cjPel = cercadoraP.cercaProperesEstrenes(mod);

    CercadoraCapitol cercadoraC;
    vector<PassarelaCapitol> cjCap = cercadoraC.cercaProperesEstrenes(mod);

    CercadoraContingut cercaCont;

    unsigned int midaT = cjPel.size() + cjCap.size();
    unsigned int i = 0, p = 0, c = 0;
    while ((i < midaT) and (i < 5)) {
        string data, tipus, titol, qualificacio;
        int detalls;
        if ((c == cjCap.size()) or (utils::dataMesPetit(cjPel[p].obteDataEstrena(), cjCap[c].obteDataEstrena()))) {
            data = utils::convertitADDMMYYYY(cjPel[p].obteDataEstrena());
            tipus = "Pel·lícula";
            titol = cjPel[p].obteTitol();
            detalls = cjPel[p].obteDuracio();
            PassarelaContingut contingut = cercaCont.cercaContingut(titol);
            qualificacio = contingut.obteQualificacio();
            ++p;
        }
        else {
            data = utils::convertitADDMMYYYY(cjCap[c].obteDataEstrena());
            tipus = "Sèrie";
            titol = cjCap[c].obteTitolSerie();
            qualificacio = cjCap[c].obteQualificacio();
            detalls = cjCap[c].obteNumTemporada();
            ++c;
        }
        DTONovetat nov(data, tipus, titol, qualificacio, detalls);
        _resultat.push_back(nov);
        ++i;
    }
}

vector<DTONovetat> TxProperesEstrenes::obteResultat() {
    return _resultat;
}


