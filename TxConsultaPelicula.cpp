#include "TxConsultaPelicula.h"

TxConsultaPelicula::TxConsultaPelicula() {

}

void TxConsultaPelicula::executar(string titolP) {
    CercadoraPelicula cercadoraPel;
    _pelicula = cercadoraPel.cercaPelicula(titolP);

    string titol;
    string descripcio;
    string qualificacio;
    string data;
    int duracio;
    string tipus;

    titol = _pelicula.obteTitol();
    descripcio = _pelicula.obteDescripcio();
    qualificacio = _pelicula.obteQualificacio();
    data = _pelicula.obteDataEstrena();
    duracio = _pelicula.obteDuracio();
    tipus = _pelicula.obteTipus();

    DTOPelicula resultat(titol, descripcio, qualificacio, data, duracio, tipus);
    _resultat = resultat;
}

DTOPelicula TxConsultaPelicula::obteResultat() {
    return _resultat;
}

PassarelaPelicula TxConsultaPelicula::obtePelicula() {
    return _pelicula;
}