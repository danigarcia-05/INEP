#include "TxConsultaMesVistes.h"

TxConsultaMesVistes::TxConsultaMesVistes() {

}

void TxConsultaMesVistes::executar() {
    CercadoraPelicula cercadoraP;
    CercadoraContingut cercadoraC;
    _cjPP = cercadoraP.cercaPeliculesMesVistes();
    string titol, descripcio, qualificacio, data, tipus;
    int duracio, visGlobals;
    for (int i = 0; i < _cjPP.size(); i++) {
        titol = _cjPP[i].obteTitol();
        data = utils::convertitADDMMYYYY(_cjPP[i].obteDataEstrena());
        duracio = _cjPP[i].obteDuracio();
        visGlobals = _cjPP[i].obteVisualitzacionsGlobals();
        PassarelaContingut cont = cercadoraC.cercaContingut(titol);
        descripcio = cont.obteDescripcio();
        qualificacio = cont.obteQualificacio();

        DTOPelicula resultat(titol, descripcio, qualificacio, data, duracio, "pelicula", visGlobals);
        _resultat.push_back(resultat);
    }
}

vector<DTOPelicula> TxConsultaMesVistes::obteResultat() {
    return _resultat;
}

vector<PassarelaPelicula> TxConsultaMesVistes::obtePelicules() {
    return _cjPP;
}