#include "TxInfoVisualitzacions.h"

TxInfoVisualitzacions::TxInfoVisualitzacions() 
    : _numVisualitzacions(0, 0){}


void TxInfoVisualitzacions::executar(){
    PetitFlix& petitFlix = PetitFlix::getInstance();
    PassarelaUsuari* u = petitFlix.obteUsuari();
    string sobrenomU = u->obteSobrenom();

    CercadoraVisualitzaPel cercadoraPel;
    CercadoraVisualitzaSerie cercadoraSerie;
    
    vector<PassarelaVisualitzaPel> visualitzacionsPel = cercadoraPel.cercaVisualitzaPel(sobrenomU);
    vector<PassarelaVisualitzaSerie> visualitzacionsS = cercadoraSerie.cercaVisualitzaSerie(sobrenomU);

    for (int i = 0; i < visualitzacionsPel.size(); ++i) _numVisualitzacions.first += visualitzacionsPel[i].obteNumVisualitzacions();
    for (int i = 0; i < visualitzacionsS.size(); ++i) _numVisualitzacions.second += visualitzacionsS[i].obteNumVisualitzacions();
}

pair<int,int> TxInfoVisualitzacions::obteResultat() const {
    return _numVisualitzacions;
}