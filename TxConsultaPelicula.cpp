#include "TxConsultaPelicula.h"

TxConsultaPelicula::TxConsultaPelicula() {

}

void TxConsultaPelicula::executar(string titolP) {
    CercadoraPelicula cercadoraP;
    CercadoraContingut cercadoraC;
    _pelicula = cercadoraP.cercaPelicula(titolP);
    _contingut = cercadoraC.cercaContingut(titolP);

    string titol, descripcio, qualificacio, data, tipus;
    int duracio;

    titol = _pelicula.obteTitol();
    descripcio = _contingut.obteDescripcio();
    qualificacio = _contingut.obteQualificacio();
    data = utils::convertToDatetime(_pelicula.obteDataEstrena());
    duracio = _pelicula.obteDuracio();
    tipus = _contingut.obteTipus();

    DTOPelicula resultat(titol, descripcio, qualificacio, data, duracio, tipus);
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
