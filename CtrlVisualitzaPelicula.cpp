#include "CtrlVisualitzaPelicula.h"
    

CtrlVisualitzaPelicula::CtrlVisualitzaPelicula(){
    PetitFlix& petitFlix = PetitFlix::getInstance();
    _usuari = *(petitFlix.obteUsuari());
}

//Falta TxVisualitzaPelicula
DTOPelicula CtrlVisualitzaPelicula::consultaPelicula(string titolP) {
    TxConsultaPelicula txConsultaPelicula;
    txConsultaPelicula.executar(titolP);
    DTOPelicula infoP = txConsultaPelicula.obteResultat();
    _pelicula = txConsultaPelicula.obtePelicula();
    return infoP;
}
    
void CtrlVisualitzaPelicula::modificaVisualitzacioPelicula(string titolP){
    TxConsultaVisualitzacioPelicula txConsultaVisualitzacioPelicula;
    txConsultaVisualitzacioPelicula.executar(titolP);
    _peliculaUsuari = txConsultaVisualitzacioPelicula.obteVisualitzacioPelicula();
    if (_peliculaUsuari.obteTitolPelicula() == "") {
        PassarelaVisualitzaPel visualitzacio(_usuari.obteSobrenom(), titolP, utils::dataActual(), 1);
        visualitzacio.insereix();
    }
    else {
        _peliculaUsuari.setNumVisualitzacions(_peliculaUsuari.obteNumVisualitzacions() + 1);
        _peliculaUsuari.setData(utils::dataActual());
        _peliculaUsuari.modifica();
    }    
}

vector<DTOPelicula> consultaPeliculesRelacionades(string titolP) {
    TxConsultaVisualitzacioPelicula txConsultaVisualitzacioPelicula;
    txConsultaVisualitzacioPelicula.executar(titolP);
    vector<PassarelaPelicula> cjPelicules = tx;
    
    return resultat;
}