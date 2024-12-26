#include "CercadoraRelacionades.h"

CercadoraRelacionades::CercadoraRelacionades() {
}

vector<string> CercadoraRelacionades::cercaRelacionades(string titolC) {
    ConnexioDB& connexio = ConnexioDB::getInstance();
    vector<string> resultat;

    // Establim la sentència SQL.
    string sql = "SELECT * FROM relacionat WHERE titol_x = '" + titolC + "'";
    sql::ResultSet* res = connexio.consultaSQL(sql);

    // Mirem si existeix un usuari amb el sobrenom.ac
    while (res->next()) {
        resultat.push_back(res->getString("titol_y"));
    }
    return resultat;
}