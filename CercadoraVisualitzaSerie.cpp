#include "CercadoraVisualitzaSerie.h"
#include "connexioDB.h"

CercadoraVisualitzaSerie::CercadoraVisualitzaSerie(){
    
}

PassarelaVisualitzaSerie CercadoraVisualitzaSerie::cercaVisualitzaSerie(string sobrenomU){
    PassarelaVisualitzaSerie pu;
    try {
        ConnexioBD connexio;

        string sql = "SELECT * FROM Usuari WHERE sobrenom='" + sobrenomU + "'";
        sql::ResultSet* res = connexio.consultaSQL(sql);

        // Mirem si existeix un usuari amb el sobrenom.
        if (res->next()) {
            pu.setSobrenom(res->getString("sobrenom"));
            pu.setTitolSerie(res->getString("titol_serie"));
            pu.setNumVisualitzacions(res->getString("num_visualitzacions"));
            pu.setNumTemporada(res->getString("num_temporada"));
            pu.setNumCapitol(res->getString("num_capitol"));
            pu.setData(res->getString("data"));
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