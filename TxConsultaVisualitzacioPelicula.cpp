#include "TxConsultaVisualitzacioPelicula.h"

TxConsultaVisualitzacioPelicula::TxConsultaVisualitzacioPelicula() {
    
}

void TxConsultaVisualitzacioPelicula::executar(string titolP) {
    PetitFlix& petitFlix = PetitFlix::getInstance();
    PassarelaUsuari usuari = *(petitFlix.obteUsuari());
    CercadoraVisualitzaPel cercadoraPel;
    _pelicula = cercadoraPel.cercaVisualitzaPelEspecifica(usuari.obteSobrenom(), titolP);

    string sobrenom, titolPelicula, data;
    int numVisualitzacions;

    sobrenom = _pelicula.obteSobrenom();
    titolPelicula = _pelicula.obteTitolPelicula();
    data = _pelicula.obteData();
    numVisualitzacions = _pelicula.obteNumVisualitzacions();

    DTOVisualitzacioPelicula resultat(sobrenom, titolPelicula, data, numVisualitzacions);
    _resultat = resultat;
}

DTOVisualitzacioPelicula TxConsultaVisualitzacioPelicula::obteResultat() {
    return _resultat;
}

PassarelaVisualitzaPel TxConsultaVisualitzacioPelicula::obteVisualitzacioPelicula() {
    return _pelicula;
}