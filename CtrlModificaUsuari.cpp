#include "CtrlModificaUsuauri.h"
    

    CtrlModificaUsuauri::CtrlModificaUsuauri() {
        
    }

    DTOUsuari CtrlModificaUsuauri::consultaUsuari() {
        string nom=_usuari.obteNom();
        string sobrenom=_usuari.obteSobrenom();
        string correu=_usuari.obteCorreuElectronic();
        string dataN=_usuari.obteDataNaixament();
        string modalitatN=_usuari.obteModalitatSubscripcio();
        DTOUsuari infoU(nom, sobrenom, correu, dataN, modalitatN);
        return infoU;
    }
    
    void CtrlModificaUsuauri::modificaUsuari(string nomU, string contraU, string correuU, date neixU, subscripcio subsU) {
        
    }

    void CtrlModificaUsuauri::executar() {

    }
