#include "TxConsultaVisualitzacioCapitol.h"

TxConsultaVisualitzacioCapitol::TxConsultaVisualitzacioCapitol() {
    
}

void TxConsultaVisualitzacioCapitol::executar(string sobrenomU, string titolSerie, int numTemporada, int numero) {
    CercadoraVisualitzaCapitol cercadoraCapitol;
    _capitolVisualitzat = cercadoraCapitol.cercaVisualitzaCapitol(sobrenomU, titolSerie, numTemporada, numero);
}

PassarelaVisualitzaCapitol TxConsultaVisualitzacioCapitol::obteVisualitzacioCapitol() {
    return _capitolVisualitzat;
}