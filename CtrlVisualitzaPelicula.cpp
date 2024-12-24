#include "CtrlVisualitzaPelicula.h"
    

CtrlVisualitzaPelicula::CtrlVisualitzaPelicula(){
        
}

DTOPelicula CtrlVisualitzaPelicula::consultaVisualitzacioPelicula() {
    TxConsultaUsuari txConsultaUsuari;
    txConsultaUsuari.executar();
    DTOPelicula infoUsu = txConsultaUsuari.obteResultat();
    _pelicula = txConsultaUsuari.obteUsuari();
    return infoUsu;
}
    
void CtrlVisualitzaPelicula::modificaVisualitzacioPelicula(string sobrenomU, string titolP, string dataVisualitzacioU, string numVisualitzacionsU){
    if (sobrenomU != "") _usuari.setNom(nomU);
    if (titolP != "") _usuari.setTitol(contraU);
    if (correuU!="") _usuari.setCorreuElectronic(correuU);
    if (neixU!="") _usuari.setDataNaixament(neixU);
    if (modalitatU != "") _usuari.setModalitatSubscripcio(modalitatU);
    if (nomU != "" or contraU != "" or correuU != "" or neixU != "" or modalitatU != "") {
        _usuari.modifica();
        PetitFlix& petitFlix = PetitFlix::getInstance();
        petitFlix.modificaUsuari(_usuari.obteNom(), _usuari.obteContrasenya(), _usuari.obteDataNaixament(), _usuari.obteCorreuElectronic(), _usuari.obteModalitatSubscripcio());
    }
}