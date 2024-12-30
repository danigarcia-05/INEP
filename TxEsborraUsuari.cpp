#include "TxEsborraUsuari.h"


TxEsborraUsuari::TxEsborraUsuari() {
}

TxEsborraUsuari::TxEsborraUsuari(string contraU) : _contraU(contraU){ 
}

void TxEsborraUsuari::executar(){
    PetitFlix& petitFlix = PetitFlix::getInstance();
    PassarelaUsuari usu = *(petitFlix.obteUsuari());
    string c = usu.obteContrasenya();
    
    if (c != _contraU) {
        throw runtime_error("ErrorContrasenya");
    }
    usu.esborra();
    petitFlix.tancaSessio();
}

TxEsborraUsuari::~TxEsborraUsuari() {}