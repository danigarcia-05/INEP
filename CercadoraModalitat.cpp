#include "CercadoraModalitat.h"

CercadoraModalitat::CercadoraModalitat() {

}

void CercadoraModalitat::existeix(string mod) {
    ConnexioDB& con = ConnexioDB::getInstance();

    std::string comanda = "SELECT * FROM modalitat_subscripcio WHERE nom = '" + mod + "';";
    sql::ResultSet* res = con.consultaSQL(comanda);

    // Verificamos si la consulta retorna alg�n resultado
    if (!res->next()) {
        // Si no hay resultados, lanzamos una excepci�n con un mensaje de error
        throw std::runtime_error("ModalitatNoExisteix");
    }
}

