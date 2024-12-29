#include "TxVisualitzacionsUsuari.h"

TxVisualitzacionsUsuari::TxVisualitzacionsUsuari() {
    // Constructor, si necesitas inicializar algo, hazlo aquí.
}

void TxVisualitzacionsUsuari::executar() {
        // Ejecutar la transacción que consulta al usuario
        TxConsultaUsuari txConsultaUsuari;
        txConsultaUsuari.executar();
        PassarelaUsuari usuari = txConsultaUsuari.obteUsuari();
        string sobrenomU = usuari.obteSobrenom();
       
        // Ejecutar la consulta de visualización de película
        TxConsultaVisualitzacioPelicula txConsultaVisualitzacioPelicula;
        txConsultaVisualitzacioPelicula.executarVP(sobrenomU);
        _peliculaDTO = txConsultaVisualitzacioPelicula.obteResultat();
        vector<PassarelaVisualitzaPel> pelVis = txConsultaVisualitzacioPelicula.obteConjuntVisualitzacionsPelicules();
       
        // Ejecutar la consulta de visualización de capítulos
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
