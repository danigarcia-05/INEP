
#include "connexioDB.h"

CercadoraVisualitzaSerie::CercadoraVisualitzaSerie(){
    
}

PassarelaVisualitzaSerie CercadoraVisualitzaSerie::cercaVisualitzaSerie(string sobrenomU){
    PassarelaVisualitzaSerie pu;
    try {
        ConnexioDB& con = ConnexioDB::getInstance();

        string comanda = "SELECT * FROM Usuari WHERE sobrenom='" + sobrenomU + "'";
        sql::ResultSet* res = con.consultaSQL(sql);

        // Mirem si existeix un usuari amb el sobrenom.
        if (res->next()) {
            pu.setSobrenom(res->getString("sobrenom"));
            pu.setTitolSerie(res->getString("titol_serie"));
            pu.setNumVisualitzacions(res->getInt("num_visualitzacions"));
            pu.setNumTemporada(res->getInt("num_temporada"));
            pu.setNumCapitol(res->getInt("num_capitol"));
            pu.setData(res->getData("data"));
        }
        else {
            throw std::runtime_error("");
        }
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }
    return pu;
}