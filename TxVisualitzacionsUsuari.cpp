#include "TxVisualitzacionsUsuari.h"

TxVisualitzacionsUsuari::TxVisualitzacionsUsuari() {
    // Constructor, si necesitas inicializar algo, hazlo aqu�.
}

void TxVisualitzacionsUsuari::executar() {
        // Ejecutar la transacci�n que consulta al usuario
        TxConsultaUsuari txConsultaUsuari;
        txConsultaUsuari.executar();
        PassarelaUsuari usuari = txConsultaUsuari.obteUsuari();
        string sobrenomU = usuari.obteSobrenom();
       
        // Ejecutar la consulta de visualizaci�n de pel�cula
        TxConsultaVisualitzacioPelicula txConsultaVisualitzacioPelicula;
        txConsultaVisualitzacioPelicula.executarVP(sobrenomU);
        _peliculaDTO = txConsultaVisualitzacioPelicula.obteResultat();
        vector<PassarelaVisualitzaPel> pelVis = txConsultaVisualitzacioPelicula.obteConjuntVisualitzacionsPelicules();
       
        // Ejecutar la consulta de visualizaci�n de cap�tulos
        TxConsultaVisualitzacioCapitol txConsultaVisualitzacioCapitol;
        txConsultaVisualitzacioCapitol.executarCV(sobrenomU);
        _capitolDTO = txConsultaVisualitzacioCapitol.obteCapitolsVisualitzats();
        vector<PassarelaVisualitzaCapitol> capVis = txConsultaVisualitzacioCapitol.obteConjuntVisualitzacionsCapitols();
        
        if (pelVis.size() == 0 and capVis.size() == 0) throw runtime_error("SenseVisualitzacions");
}

std::vector<DTOVisualitzacioPelicula> TxVisualitzacionsUsuari::obteVisualitzacionsPelicula() const {
    return _peliculaDTO;
}

std::vector<DTOVisualitzacioCapitol> TxVisualitzacionsUsuari::obteVisualitzacionsCapitol() const {
    return _capitolDTO;
}
