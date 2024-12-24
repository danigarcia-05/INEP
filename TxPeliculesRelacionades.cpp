#include "TxPeliculesRelacionades.h"

TxPeliculesRelacionades::TxPeliculesRelacionades() {

}

void TxPeliculesRelacionades::executar(string titolP) {
    CercadoraPelicula cercadoraPel;
    _pelicula = cercadoraPel.cercaPeliculesRelacionades(titolP);

    vector<DTOPelicula> resultat;
    for (int i = 0; i < _pelicula.size(); ++i) {
        DTOPelicula pelicula;
        pelicula.setTitol(_pelicula[i].obteTitol);
        pelicula.setDescripcio(_pelicula[i].obteDescripcio);
        pelicula.setQualificacio(_pelicula[i].obteQualificacio);
        pelicula.setDataP(_pelicula[i].obteDataEstrena);
        pelicula.setDuracio(_pelicula[i].obteDuracio);
        resultat.push_back(pelicula);
    }

    DTOVisualitzacioPelicula resultat(sobrenom, titolPelicula, data, numVisualitzacions);
    _resultat = resultat;
}

vector<DTOPelicula> TxPeliculesRelacionades::obteResultat() {
    return _resultat;
}

vector<PassarelaPelicula> TxPeliculesRelacionades::obtePelicula() {
    return _pelicula;
}