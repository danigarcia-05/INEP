#include "CtrlModificaUsuauri.h"
    

    CtrlModificaUsuauri::CtrlModificaUsuauri() {
        
    }

    DTOUsuari CtrlModificaUsuauri::consultaUsuari() {
        TxConsultaUsuari TxConsultaUsuari();
        TxConsultaUsuari.executar();
        DTOUsuari infoUsu = TxConsultaUsuari.obteResultat()  
        PassarelaUsuari usuari = TxConsultaUsuari.obteUsuari();       //revisar això
        return infoUsu;
    }
    
    void CtrlModificaUsuauri::modificaUsuari(string nomU, string contraU, string correuU, data neixU, subscripcio subsU) {
        if (nomU!="") _usuari.setNom(nomU);
        if (contraU!="") _usuari.setContrasenya(contraU);
        if (correuU!="") _usuari.setCorreuElectronic(correuU);
        if (neixU!="") _usuari.setDataNaixament(neixU);
        if (subsU!="") _usuari.setModalitatSubscripcio(subsU);
        if (nomU!="" or contraU!="" or correuU!="" or neixU!="" or subsU!="") _usuari.modifica();
    }
