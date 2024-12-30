#include "TxConsultaPelicula.h"

TxConsultaPelicula::TxConsultaPelicula() {

}


void TxConsultaPelicula::executar(string titolP) {
    CercadoraPelicula& cercadoraP = CercadoraPelicula::getInstance();
    CercadoraContingut& cercadoraC = CercadoraContingut::getInstance();
    _pelicula = cercadoraP.cercaPelicula(titolP);
    _contingut = cercadoraC.cercaContingut(titolP);

    string titol, descripcio, qualificacio, data, tipus, modalitat;
    int duracio, visGlobals;

    titol = _pelicula.obteTitol();
    descripcio = _contingut.obteDescripcio();
    qualificacio = _contingut.obteQualificacio();
    data = utils::convertitADDMMYYYY(_pelicula.obteDataEstrena());
    duracio = _pelicula.obteDuracio();
    tipus = _contingut.obteTipus();
    visGlobals = _pelicula.obteVisualitzacionsGlobals();
    modalitat = _pelicula.obteModalitat();

    DTOPelicula resultat(titol, descripcio, qualificacio, data, duracio, tipus, visGlobals, modalitat);
    _resultat = resultat;
}

DTOPelicula TxConsultaPelicula::obteResultat() {
    return _resultat;
}

PassarelaPelicula TxConsultaPelicula::obtePelicula() {
    return _pelicula;
}

PassarelaContingut TxConsultaPelicula::obteContingut() {
    return _contingut;
}

TxConsultaPelicula::~TxConsultaPelicula() {}
