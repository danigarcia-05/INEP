#include "TxConsultaContingut.h"

TxConsultaContingut::TxConsultaContingut() {

}

void TxConsultaContingut::executar(string titolC) {
    CercadoraContingut cercadoraC;
    _contingut = cercadoraPel.cercaPelicula(titolC);

    string titol, descripcio, qualificacio, data, tipus;
    int duracio;

    titol = _pelicula.obteTitol();
    descripcio = _pelicula.obteDescripcio();
    qualificacio = _pelicula.obteQualificacio();
    data = _pelicula.obteDataEstrena();
    duracio = _pelicula.obteDuracio();
    tipus = _pelicula.obteTipus();

    DTOPelicula resultat(titol, descripcio, qualificacio, data, duracio, tipus);
    _resultat = resultat;
}

DTOPelicula TxConsultaContingut::obteResultat() {
    return _resultat;
}

PassarelaPelicula TxConsultaContingut::obtePelicula() {
    return _pelicula;
}