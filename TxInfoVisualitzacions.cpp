#include "TxInfoVisualitzacions.h"

TxInfoVisualitzacions::TxInfoVisualitzacions() 
    : _numVisualitzacioPelicula(0), _numVisualitzacioSerie(0) {}


void TxInfoVisualitzacions::executar(){
    PetitFlix& petitFlix = PetitFlix::getInstance();
    PassarelaUsuari u = petitFlix.obteUsuari();
    string sobrenomU = u.obteSobrenom();

    CercadoraVisualitzaPel cercadoraPel;
    CercadoraVisualitzaSerie cercadoraSerie;
    
    PassarelaVisualitzaPel visualitzacionsPel = cercadoraPel.cercaVisualitzaPel(sobrenomU);
    PassarelaVisualitzaSerie visualitzacionsS = cercadoraSerie.cercaVisualitzaSerie(sobrenomU);

    Resultat._numVisualitzacioPelicula = visualitzacionsPel.obteNumVisualitzacions();
    Resultat._numVisualitzacioSerie = visualitzacionsS.obteNumVisualitzacions();
}

TxInfoVisualitzacions::Resultat TxInfoVisualitzacions::obteResultat() const {
    return { _numVisualitzacioPelicula, _numVisualitzacioSerie};
}