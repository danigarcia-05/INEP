#include "CtrlVisualitzaPelicula.h"
    

CtrlVisualitzaPelicula::CtrlVisualitzaPelicula(){
    PetitFlix& petitFlix = PetitFlix::getInstance();
}

CtrlVisualitzaPelicula::~CtrlVisualitzaPelicula() {

}

//Falta TxVisualitzaPelicula
DTOPelicula CtrlVisualitzaPelicula::consultaPelicula(string titolP) {
    TxConsultaPelicula txConsultaPelicula;
    txConsultaPelicula.executar(titolP);
    DTOPelicula infoP = txConsultaPelicula.obteResultat();
    _infoP = txConsultaPelicula.obtePelicula();
    _infoC = txConsultaPelicula.obteContingut();
    return infoP;
}

//Mirar si vale la pena conservarlo
void CtrlVisualitzaPelicula::consultaPeliculaUsuari(string titolP) {
    PetitFlix& petitFlix = PetitFlix::getInstance();
    _usuari = *(petitFlix.obteUsuari());
    
    if (utils::dataMesGran(utils::convertitADDMMYYYY(_infoP.obteDataEstrena()), utils::convertitADDMMYYYY(utils::dataActual()))) {
        throw runtime_error("PeliculaNoEstrenada");
    }
   
    if (_usuari.obteModalitatSubscripcio() == "Infantil" and _infoP.obteModalitat() != "Infantil") {
        throw runtime_error("ModalitatIncorrecta");
    } 
   
    string qualificacio = _infoC.obteQualificacio();
    if (not utils::esContingutApteEdat(qualificacio, utils::convertitADDMMYYYY(_usuari.obteDataNaixament()))) {
        throw runtime_error("PeliculaNoApropiada");
    }

    TxConsultaVisualitzacioPelicula txConsultaVisualitzacioPelicula;
    string sobrenom = _usuari.obteSobrenom();
    txConsultaVisualitzacioPelicula.executarPelVis(titolP, sobrenom);
    _peliculaUsuari = txConsultaVisualitzacioPelicula.obteVisualitzacioPelicula();
}

void CtrlVisualitzaPelicula::modificaVisualitzacioPelicula(string titolP){    
    if (_peliculaUsuari.obteTitolPelicula() == "") {
        PassarelaVisualitzaPel visualitzacio(_usuari.obteSobrenom(), titolP, utils::dataActual(), 1);
        visualitzacio.insereix();
    }
    else {
        _peliculaUsuari.setNumVisualitzacions(_peliculaUsuari.obteNumVisualitzacions() + 1);
        _peliculaUsuari.setData(utils::dataActual());
        _peliculaUsuari.modifica();
    }
    _infoP.setVisualitzacionsGlobals(_infoP.obteVisualitzacionsGlobals() + 1);
    _infoP.modifica();
}

void CtrlVisualitzaPelicula::consultaRelacionades(string titolP) {
    vector<string> cjTitolPelicules;
    TxConsultaRelacionades txConsultaRelacionades;
    txConsultaRelacionades.executar(titolP);
    cjTitolPelicules = txConsultaRelacionades.obteRelacionades();

    for (int i = 0; i < cjTitolPelicules.size(); ++i) {
        DTOPelicula p = consultaPelicula(cjTitolPelicules[i]);
        _resultat.push_back(p);
    }

    sort(_resultat.begin(), _resultat.end(),
        [](const DTOPelicula& p1, const DTOPelicula& p2) {
            return utils::convertirAFormatoComparacion(p1.obteDataP()) > utils::convertirAFormatoComparacion(p2.obteDataP());  // Compara el atributo 'data' de los objetos
        });
}

vector<DTOPelicula> CtrlVisualitzaPelicula::obteResultat() {
    return _resultat;
}
