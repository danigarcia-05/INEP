#include "CtrlVisualitzaPelicula.h"
    

CtrlVisualitzaPelicula::CtrlVisualitzaPelicula(){
        
}

DTOVisualitzacioPelicula CtrlVisualitzaPelicula::consultaVisualitzacioPelicula() {
    TxConsultaUsuari txConsultaUsuari;
    txConsultaUsuari.executar();
    DTOPelicula infoUsu = txConsultaUsuari.obteResultat();
    _pelicula = txConsultaUsuari.obteUsuari();
    return infoUsu;
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