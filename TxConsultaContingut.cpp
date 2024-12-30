#include "TxConsultaContingut.h"

TxConsultaContingut::TxConsultaContingut() {

}

TxConsultaContingut::~TxConsultaContingut() {

}

void TxConsultaContingut::executar(string titolC) {
    CercadoraContingut& cercadoraC = CercadoraContingut::getInstance();
    _contingut = cercadoraC.cercaContingut(titolC);

    string titol, descripcio, qualificacio, tipus, modalitat;

    titol = _contingut.obteTitol();
    descripcio = _contingut.obteDescripcio();
    qualificacio = _contingut.obteQualificacio();
    tipus = _contingut.obteTipus();
    modalitat = _contingut.obteSubscripcio();

    DTOContingut resultat(titol, descripcio, qualificacio, tipus, modalitat);
    _resultat = resultat;
}

DTOContingut TxConsultaContingut::obteResultat() {
    return _resultat;
}

PassarelaContingut TxConsultaContingut::obteContingut() {
    return _contingut;
}