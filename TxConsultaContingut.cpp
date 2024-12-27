#include "TxConsultaContingut.h"

TxConsultaContingut::TxConsultaContingut() {

}

void TxConsultaContingut::executar(string titolC) {
    CercadoraContingut cercadoraC;
    _contingut = cercadoraC.cercaContingut(titolC);

    string titol, descripcio, qualificacio, tipus;

    titol = _contingut.obteTitol();
    descripcio = _contingut.obteDescripcio();
    qualificacio = _contingut.obteQualificacio();
    tipus = _contingut.obteTipus();

    DTOContingut resultat(titol, descripcio, qualificacio, tipus);
    _resultat = resultat;
}

DTOContingut TxConsultaContingut::obteResultat() {
    return _resultat;
}

PassarelaContingut TxConsultaContingut::obteContingut() {
    return _contingut;
}