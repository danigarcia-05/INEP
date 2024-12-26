#include "TxConsultaVisualitzacioPelicula.h"

TxConsultaVisualitzacioPelicula::TxConsultaVisualitzacioPelicula() {
    
}

void TxConsultaVisualitzacioPelicula::executar(string titolP, string usuari) {
    CercadoraVisualitzaPel cercadoraPel;
    _peliculaV = cercadoraPel.cercaVisualitzaPelEspecifica(usuari, titolP);
}

PassarelaVisualitzaPel TxConsultaVisualitzacioPelicula::obteVisualitzacioPelicula() {
    return _peliculaV;
}