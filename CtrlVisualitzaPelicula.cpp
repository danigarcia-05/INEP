#include "CtrlVisualitzaPelicula.h"
    

CtrlVisualitzaPelicula::CtrlVisualitzaPelicula(){
    PetitFlix& petitFlix = PetitFlix::getInstance();
}

//Falta TxVisualitzaPelicula
DTOPelicula CtrlVisualitzaPelicula::consultaPelicula(string titolP) {
    TxConsultaPelicula txConsultaPelicula;
    txConsultaPelicula.executar(titolP);
    DTOPelicula infoP = txConsultaPelicula.obteResultat();
    return infoP;
}

//Mirar si vale la pena conservarlo
void CtrlVisualitzaPelicula::consultaPeliculaUsuari(string titolP) {
    TxConsultaVisualitzacioPelicula txConsultaVisualitzacioPelicula;
    PetitFlix& petitFlix = PetitFlix::getInstance();
    PassarelaUsuari usuari = *(petitFlix.obteUsuari());
    _sobrenom = usuari.obteSobrenom();
    txConsultaVisualitzacioPelicula.executar(titolP, _sobrenom);
    _peliculaUsuari = txConsultaVisualitzacioPelicula.obteVisualitzacioPelicula();
}

void CtrlVisualitzaPelicula::modificaVisualitzacioPelicula(string titolP){
    if (_peliculaUsuari.obteTitolPelicula() == "") {
        PassarelaVisualitzaPel visualitzacio(_sobrenom, titolP, utils::dataActual(), 1);
        visualitzacio.insereix();
    }
    else {
        _peliculaUsuari.setNumVisualitzacions(_peliculaUsuari.obteNumVisualitzacions() + 1);
        _peliculaUsuari.setData(utils::dataActual());
        _peliculaUsuari.modifica();
    }   
}

vector<string> CtrlVisualitzaPelicula::consultaRelacionades(string titolP) {
    vector<string> cjTitolPelicules;
    TxConsultaRelacionades txConsultaRelacionades;
    txConsultaRelacionades.executar(titolP);
    cjTitolPelicules = txConsultaRelacionades.obteRelacionades();
    return cjTitolPelicules;
}