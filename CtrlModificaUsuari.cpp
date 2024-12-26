#include "CtrlModificaUsuari.h"
    

    CtrlModificaUsuari::CtrlModificaUsuari(){
        
    }

    DTOUsuari CtrlModificaUsuari::consultaUsuari() {
        TxConsultaUsuari txConsultaUsuari;
        txConsultaUsuari.executar();
        DTOUsuari infoUsu = txConsultaUsuari.obteResultat();
        _usuari = txConsultaUsuari.obteUsuari();
        return infoUsu;
    }
    
    void CtrlModificaUsuari::modificaUsuari(string nomU, string contraU, string correuU, string neixU, string modalitatU) {
        if (nomU != "") _usuari.setNom(nomU);
        if (contraU != "") _usuari.setContrasenya(contraU);
        if (correuU!="") _usuari.setCorreuElectronic(correuU);
        if (neixU!="") _usuari.setDataNaixament(utils::convertToDatetime(neixU));
        if (modalitatU != "") _usuari.setModalitatSubscripcio(modalitatU);
        if (nomU != "" or contraU != "" or correuU != "" or neixU != "" or modalitatU != "") {
            _usuari.modifica();
            PetitFlix& petitFlix = PetitFlix::getInstance();
            petitFlix.modificaUsuari(_usuari.obteNom(), _usuari.obteContrasenya(), _usuari.obteDataNaixament(), _usuari.obteCorreuElectronic(), _usuari.obteModalitatSubscripcio());
        }
    }

    void CtrlModificaUsuari::modificaContrasenya(string contraU) {
        _usuari.setContrasenya(contraU);
        _usuari.modifica();
        PetitFlix& petitFlix = PetitFlix::getInstance();
        petitFlix.modificaContrasenya(_usuari.obteContrasenya());
    }
