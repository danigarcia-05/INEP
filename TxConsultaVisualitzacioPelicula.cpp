#include "TxConsultaVisualitzacioPelicula.h"

TxConsultaVisualitzacioPelicula::TxConsultaVisualitzacioPelicula() {
    
}

void TxConsultaVisualitzacioPelicula::executarVP(string usuari) {
    CercadoraVisualitzaPel& cercadoraPel = CercadoraVisualitzaPel::getInstance();

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

void TxConsultaVisualitzacioPelicula::executarPelVis(string titolP, string usuari) {
    CercadoraVisualitzaPel& cercadoraPel = CercadoraVisualitzaPel::getInstance();
    _peliculaV = cercadoraPel.cercaVisualitzaPelEspecifica(usuari, titolP);
   
    string data = utils::dataAmbHora(_peliculaV.obteData());
    string titol = _peliculaV.obteTitolPelicula();
    string sobrenom = _peliculaV.obteSobrenom();
    int visualitzacions = _peliculaV.obteNumVisualitzacions();

    DTOVisualitzacioPelicula pelVis(titol, sobrenom, data, visualitzacions);
    _pelVis = pelVis;
}

PassarelaVisualitzaPel TxConsultaVisualitzacioPelicula::obteVisualitzacioPelicula() {
    return _peliculaV;
}

DTOVisualitzacioPelicula TxConsultaVisualitzacioPelicula::obteResultatSingle() {
    return _pelVis;
}


vector<PassarelaVisualitzaPel> TxConsultaVisualitzacioPelicula::obteConjuntVisualitzacionsPelicules(){
    return _cjVisualitzacioPelicula;
}
    
vector<DTOVisualitzacioPelicula> TxConsultaVisualitzacioPelicula::obteResultat(){
    return _resultat;
}

TxConsultaVisualitzacioPelicula::~TxConsultaVisualitzacioPelicula() {}

