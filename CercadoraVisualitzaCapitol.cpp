#include "CercadoraVisualitzaCapitol.h"

CercadoraVisualitzaCapitol::CercadoraVisualitzaCapitol(){

}

CercadoraVisualitzaCapitol& CercadoraVisualitzaCapitol::getInstance() {
    static CercadoraVisualitzaCapitol instance;  
    return instance;
}

PassarelaVisualitzaCapitol CercadoraVisualitzaCapitol::cercaVisualitzaCapitol(string sobrenomU, string nomS, int numTemporada, int numCapitol){
    ConnexioDB& con = ConnexioDB::getInstance();
    string comanda = "SELECT * FROM visualitzacio_capitol WHERE sobrenom_usuari = '" + sobrenomU + 
        "' AND titol_serie = '" + nomS + "' AND num_temporada = " + to_string(numTemporada) + 
        " AND num_capitol = " + std::to_string(numCapitol) + 
        " ORDER BY data DESC;";

    sql::ResultSet* res = con.consultaSQL(comanda);

    PassarelaVisualitzaCapitol capitol;

    // Mirem si existeix un usuari amb el sobrenom.
    if (res->next()) {
        capitol.setSobrenom(res->getString("sobrenom_usuari"));
        capitol.setTitolSerie(res->getString("titol_serie"));
        capitol.setNumVisualitzacions(res->getInt("num_visualitzacions"));
        capitol.setNumTemporada(res->getInt("num_temporada"));
        capitol.setNumCapitol(res->getInt("num_capitol"));
        capitol.setData(res->getString("data"));
    }
    return capitol;
}

vector<PassarelaVisualitzaCapitol> CercadoraVisualitzaCapitol::cercaVisualitzaCapitolsUsuari(string sobrenomU){
    ConnexioDB& con = ConnexioDB::getInstance();
    vector<PassarelaVisualitzaCapitol> cjVisualitzacionsCapitol;

    string comanda = "SELECT * FROM visualitzacio_capitol WHERE sobrenom_usuari = '" + sobrenomU + "' ORDER BY data DESC";
    sql::ResultSet* res = con.consultaSQL(comanda);

    // Mirem si existeix un usuari amb el sobrenom.
    while (res->next()) {
        PassarelaVisualitzaCapitol pvc;
        pvc.setSobrenom(res->getString("sobrenom_usuari"));
        pvc.setTitolSerie(res->getString("titol_serie"));
        pvc.setNumVisualitzacions(res->getInt("num_visualitzacions"));
        pvc.setNumTemporada(res->getInt("num_temporada"));
        pvc.setNumCapitol(res->getInt("num_capitol"));
        pvc.setData(res->getString("data"));
        cjVisualitzacionsCapitol.push_back(pvc);
    }
    return cjVisualitzacionsCapitol;
}

CercadoraVisualitzaCapitol::~CercadoraVisualitzaCapitol() {
    
}
    