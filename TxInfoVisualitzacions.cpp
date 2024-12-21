#include "TxInfoVisualitzacions.h"

TxInfoVisualitzacions::TxInfoVisualitzacions() 
    : _numVisualitzacions(0, 0){}


void TxInfoVisualitzacions::executar(){
    PetitFlix& petitFlix = PetitFlix::getInstance();
    PassarelaUsuari* u = petitFlix.obteUsuari();
    string sobrenomU = u->obteSobrenom();

    CercadoraVisualitzaPel cercadoraPel;
    CercadoraVisualitzaSerie cercadoraSerie;
    
    PassarelaVisualitzaPel visualitzacionsPel = cercadoraPel.cercaVisualitzaPel(sobrenomU);
    Passare visualitzacionsS = cercadoraSerie.cercaVisualitzaSerie(sobrenomU);

    
    _numVisualitzacions.first = visualitzacionsPel.obteNumVisualitzacions();
    _numVisualitzacions.second = visualitzacionsS.obteNumVisualitzacions();
}

pair<int,int> TxInfoVisualitzacions::obteResultat() const {
    return _numVisualitzacions;
}