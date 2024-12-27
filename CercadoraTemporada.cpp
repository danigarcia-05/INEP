#include "CercadoraTemporada.h"

CercadoraTemporada::CercadoraTemporada() {
}

PassarelaTemporada CercadoraTemporada::cercaTemporada(string titolS, int numTemporada) {
    PassarelaTemporada temporada;
    ConnexioDB& con = ConnexioDB::getInstance();

    string comanda = "SELECT * FROM temporada WHERE titol_serie = '" + titolS + "' AND numero = " + to_string(numTemporada) + ";";
    sql::ResultSet* res = con.consultaSQL(comanda);

    if (not res->next()) {
        throw runtime_error("TemporadaNoExisteix");
    }
    else {
        temporada.setTitol(res->getString("titol_serie"));
        temporada.setNumTemporada(res->getInt("numero"));
        delete res;
    }
    return temporada;
}

vector<PassarelaTemporada> CercadoraTemporada::cercaTemporades(string titolS) {
    ConnexioDB& connexio = ConnexioDB::getInstance();
    vector<PassarelaTemporada> cjTemporades;

    // Establim la sentència SQL.
    string sql = "SELECT * FROM temporada WHERE titol_serie = '" + titolS + "'";
    sql::ResultSet* res = connexio.consultaSQL(sql);

    // Mirem si existeix un usuari amb el sobrenom.
    while (res->next()) {
        PassarelaTemporada temporada;
        temporada.setTitol(res->getString("titol_serie"));
        temporada.setNumTemporada(res->getInt("numero"));
        cjTemporades.push_back(temporada);
    }
    return cjTemporades;
}