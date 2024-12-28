#include "TxConsultaNovetats.h"

TxConsultaNovetats::TxConsultaNovetats() {

}

void TxConsultaNovetats::executar(string mod) {
    CercadoraPelicula cercadoraP;
    vector<PassarelaPelicula> cjPel = cercadoraP.cercaNovesEstrenes(mod);
    CercadoraContingut cercadoraContingut;
    for (int i=0; i<cjPel.size(); ++i) {
        string titol, dataEstrena, modalitat;
        int duracio, visGlobals;

        titol = cjPel[i].obteTitol();
        dataEstrena = utils::convertitADDMMYYYY(cjPel[i].obteDataEstrena());
        duracio = cjPel[i].obteDuracio();
        visGlobals = cjPel[i].obteVisualitzacionsGlobals();
        modalitat = cjPel[i].obteModalitat();

        PassarelaContingut contingut = cercadoraContingut.cercaContingut(titol);

        string descripcio, qualificacio, tipus, subscripcio;
        descripcio = contingut.obteDescripcio();
        qualificacio = contingut.obteQualificacio();
        tipus = contingut.obteTipus();

        DTOPelicula pel(titol, descripcio, qualificacio, dataEstrena, duracio, tipus, visGlobals, modalitat);

        _pelicules.push_back(pel);
    }

    CercadoraCapitol cercadoraC;
    vector<PassarelaCapitol> cjCap = cercadoraC.cercaNovesEstrenes(mod);
    for (int i=0; i<cjCap.size(); ++i) {
        string titolS, titolC, dataE, qualificacio, modalitat;
        int numT, numC, duracio;

        titolS = cjCap[i].obteTitolSerie();
        numT = cjCap[i].obteNumTemporada();
        numC = cjCap[i].obteNumero();
        titolC = cjCap[i].obteTitol();
        dataE = utils::convertitADDMMYYYY(cjCap[i].obteDataEstrena());
        qualificacio = cjCap[i].obteQualificacio();  
        duracio = cjCap[i].obteDuracio();           
        modalitat = cjCap[i].obteModalitat();           

        DTOCapitol cap(titolS, numT, numC, titolC, dataE, qualificacio, duracio, modalitat);
        _capitols.push_back(cap);
    }
}

vector<DTOPelicula> TxConsultaNovetats::obtePelicules() {
    return _pelicules;
}

vector<DTOCapitol> TxConsultaNovetats::obteCapitols() {
    return _capitols;
}