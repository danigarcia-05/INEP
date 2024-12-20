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
    
    void CtrlModificaUsuauri::modificaUsuari(string nomU, string contraU, string correuU, date neixU, subscripcio subsU) {
        if (nomU!="") _usuari.entraNom(nomU);
        if (contraU!="") _usuari.entraContrasenya(contraU);
        if (correuU!="") _usuari.entraCorreuElectronic(correuU);
        if (neixU!="") _usuari.entraDataNaixament(neixU);
        if (subsU!="") _usuari.entraModalitatSubscripcio(subsU);
        if (nomU!="" or contraU!="" or correuU!="" or neixU!="" or subsU!="") _usuari.modifica();
    }
