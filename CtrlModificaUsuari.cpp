#include "CtrlModificaUsuari.h"
    

    CtrlModificaUsuari::CtrlModificaUsuari() : _usuari(){
        
    }

    DTOUsuari CtrlModificaUsuari::consultaUsuari() {
        TxConsultaUsuari txConsultaUsuari;
        txConsultaUsuari.executar();
        DTOUsuari infoUsu = txConsultaUsuari.obteResultat();
        PassarelaUsuari usuari = txConsultaUsuari.obteUsuari();       //revisar això
        return infoUsu;
    }
    
    void CtrlModificaUsuari::modificaUsuari(string nomU, string contraU, string correuU, Data neixU, string subsU) {
        if (nomU!="") _usuari.setNom(nomU);
        if (contraU!="") _usuari.setContrasenya(contraU);
        if (correuU!="") _usuari.setCorreuElectronic(correuU);
        if (neixU!="") _usuari.setDataNaixament(neixU);
        if (subsU!="") _usuari.setModalitatSubscripcio(subsU);
        if (nomU!="" or contraU!="" or correuU!="" or neixU!="" or subsU!="") _usuari.modifica();
    }
