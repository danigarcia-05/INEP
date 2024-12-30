#include "TxConsultaRelacionades.h"

TxConsultaRelacionades::TxConsultaRelacionades() {

}

void TxConsultaRelacionades::executar(string titolC) {
    CercadoraRelacionades& cercadoraR = CercadoraRelacionades::getInstance();
    _relacionades = cercadoraR.cercaRelacionades(titolC);
}

vector<string> TxConsultaRelacionades::obteRelacionades() {
    return _relacionades;
}

TxConsultaRelacionades::~TxConsultaRelacionades() {}


