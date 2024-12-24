#include "CtrlVisualitzaPelicula.h"
    

CtrlVisualitzaPelicula::CtrlVisualitzaPelicula(){
        
}

//Falta TxVisualitzaPelicula
DTOVisualitzacioPelicula CtrlVisualitzaPelicula::consultaVisualitzacioPelicula() {
    TxConsultaUsuari txConsultaUsuari;
    txConsultaUsuari.executar();
    DTOVisualitzacioPelicula infoP = txConsultaUsuari.obteResultat();
    _pelicula = txConsultaUsuari.obteUsuari();
    return infoP;
}
    
void CtrlVisualitzaPelicula::modificaVisualitzacioPelicula(){
    if ("No existe") {
        //HACER LO MISMO QUE EL ELSE
        
    }
    else {
        _pelicula.setNumVisualitzacions(_pelicula.obteNumVisualitzacions() + 1);
        _pelicula.setData(utils::dataActual());

        _pelicula.modifica();
    }    
}