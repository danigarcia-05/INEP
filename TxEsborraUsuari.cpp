#include "TxEsborraUsuari.h"
#include "PetitFlix.h"
#include <stdexcept>  // Para runtime_error
#include <string>  // Para usar std::string
using namespace std;


TxEsborraUsuari::TxEsborraUsuari(string contraU){
    _contraU = contraU;
}

void TxEsborraUsuari::executar(){
    PetitFlix& petitFlix = PetitFlix::getInstance();
    PassarelaUsuari usu = *(petitFlix.obteUsuari());
    string c = usu.obteContrasenya();
    
    if (c != _contraU) {
        throw runtime_error("ErrorContrasenya");
    }
    usu.esborra();  
}