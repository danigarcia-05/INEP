#include "CercadoraVisualitzaSerie.h"


CercadoraVisualitzaSerie::CercadoraVisualitzaSerie(){
}

vector<PassarelaVisualitzaSerie> CercadoraVisualitzaSerie::cercaVisualitzaSerie(string sobrenomU){
        ConnexioDB& con = ConnexioDB::getInstance();
        vector<PassarelaVisualitzaSerie> cjVisualitzacionsSerie;

        string comanda = "SELECT * FROM visualitzacio_capitol WHERE sobrenom_usuari='" + sobrenomU + "'";
        sql::ResultSet* res = con.consultaSQL(comanda);

        // Mirem si existeix un usuari amb el sobrenom.
        while (res->next()) {
            PassarelaVisualitzaSerie pvs;
            pvs.setSobrenom(res->getString("sobrenom"));
            pvs.setTitolSerie(res->getString("titol_serie"));
            pvs.setNumVisualitzacions(res->getInt("num_visualitzacions"));
            pvs.setNumTemporada(res->getInt("num_temporada"));
            pvs.setNumCapitol(res->getInt("num_capitol"));
            pvs.setData(res->getString("data"));
            cjVisualitzacionsSerie.push_back(pvs);
        }
        return cjVisualitzacionsSerie;
    }
    