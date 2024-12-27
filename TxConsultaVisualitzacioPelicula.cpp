#include "TxConsultaVisualitzacioPelicula.h"

TxConsultaVisualitzacioPelicula::TxConsultaVisualitzacioPelicula() {
    
}

void TxConsultaVisualitzacioPelicula::executar(string titolP, string usuari) {
    CercadoraVisualitzaPel cercadoraPel;
    _peliculaV = cercadoraPel.cercaVisualitzaPelEspecifica(usuari, titolP);
   
    _cjVisualitzacioPelicula = cercadoraPel.cercaVisualitzaPel(usuari);
    vector<DTOVisualitzacioPelicula> resultat;
    for(int i = 0; i < _cjVisualitzacioPelicula.size(); ++i){        
        string data = utils::dataAmbHora(_cjVisualitzacioPelicula[i].obteData());
        string titol = _cjVisualitzacioPelicula[i].obteTitolPelicula();
        string sobrenom = _cjVisualitzacioPelicula[i].obteSobrenom();
        int visualitzacions = _cjVisualitzacioPelicula[i].obteNumVisualitzacions();
        DTOVisualitzacioPelicula pv(titol, sobrenom, data, visualitzacions);
        resultat.push_back(pv);
    }
    _resultat = resultat;
}

void TxConsultaVisualitzacioPelicula::executarVP(string usuari) {
    CercadoraVisualitzaPel cercadoraPel;   
    _cjVisualitzacioPelicula = cercadoraPel.cercaVisualitzaPel(usuari);
    vector<DTOVisualitzacioPelicula> resultat;
    for(int i = 0; i < _cjVisualitzacioPelicula.size(); ++i){        
        string data = utils::dataAmbHora(_cjVisualitzacioPelicula[i].obteData());
        string titol = _cjVisualitzacioPelicula[i].obteTitolPelicula();
        string sobrenom = _cjVisualitzacioPelicula[i].obteSobrenom();
        int visualitzacions = _cjVisualitzacioPelicula[i].obteNumVisualitzacions();
        DTOVisualitzacioPelicula pv(titol, sobrenom, data, visualitzacions);
        resultat.push_back(pv);
    }
    _resultat = resultat;
}

PassarelaVisualitzaPel TxConsultaVisualitzacioPelicula::obteVisualitzacioPelicula() {
    return _peliculaV;
}

vector<PassarelaVisualitzaPel> TxConsultaVisualitzacioPelicula::obteConjuntVisualitzacionsPelicules(){
    return _cjVisualitzacioPelicula;
}
    
vector<DTOVisualitzacioPelicula> TxConsultaVisualitzacioPelicula::obteResultat(){
    return _resultat;
}