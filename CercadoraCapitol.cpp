#include "CercadoraCapitol.h"
#include "utils.h"


CercadoraCapitol::CercadoraCapitol() {

}

vector<PassarelaCapitol> CercadoraCapitol::cercaCapitolsTemporada(string titolS, int numTemporada) {

    ConnexioDB& con = ConnexioDB::getInstance();
    vector<PassarelaCapitol> cjCapitols;

    string comanda = "SELECT * FROM capitol WHERE titol_serie = '" + titolS + "' AND numero_temporada = '" + std::to_string(numTemporada) + "';";;
    sql::ResultSet* res = con.consultaSQL(comanda);

    // Mirem si existeix un usuari amb el sobrenom.
    while (res->next()) {
        PassarelaCapitol capitol;
        capitol.setTitolSerie(res->getString("titol_serie"));
        capitol.setNumTemporada(res->getInt("numero_temporada"));
        capitol.setNumero(res->getInt("numero"));
        capitol.setTitol(res->getString("titol"));
        capitol.setDataEstrena(res->getString("data_estrena"));
        capitol.setQualificacio(res->getString("qualificacio"));
        capitol.setDuracio(res->getInt("duracio_capitol"));
        cjCapitols.push_back(capitol);
    }
    return cjCapitols;
}

vector<PassarelaCapitol> CercadoraCapitol::cercaNovesEstrenes(string mod) {
    vector<PassarelaCapitol> cjCapitols;
    if (mod == "Infantil" or mod == "Completa") {
        ConnexioDB& con = ConnexioDB::getInstance();
        string comanda;
        if (mod == "Infantil") {
            comanda = "SELECT * FROM capitol WHERE data_estrena <= NOW() AND modalitat = '" + mod + "' " +
                "ORDER BY data_estrena DESC LIMIT 5;";
        }
        else {
            comanda = "SELECT * FROM capitol WHERE data_estrena <= NOW() ORDER BY data_estrena DESC LIMIT 5;";
        }
        sql::ResultSet* res = con.consultaSQL(comanda);

        while (res->next()) {  // Asegurarse de que se encontró un resultado
            PassarelaCapitol capitol;
            capitol.setTitolSerie(res->getString("titol_serie"));
            capitol.setNumTemporada(res->getInt("numero_temporada"));
            capitol.setNumero(res->getInt("numero"));
            capitol.setTitol(res->getString("titol"));
            capitol.setDataEstrena(res->getString("data_estrena"));
            capitol.setQualificacio(res->getString("qualificacio"));
            capitol.setDuracio(res->getInt("duracio_capitol"));
            capitol.setModalitat(res->getString("modalitat"));
            cjCapitols.push_back(capitol);
        }
    }    
    return cjCapitols;
}


vector<PassarelaCapitol> CercadoraCapitol::cercaProperesEstrenes(string mod) {
    vector<PassarelaCapitol> cjCapitols;
    if (mod == "Infantil" or mod == "Completa") {
        ConnexioDB& con = ConnexioDB::getInstance();
        string comanda;
        if (mod == "Infantil") {
            comanda = "SELECT * FROM capitol WHERE data_estrena > NOW() AND modalitat = '" + mod + "' AND numero = 1 "
          "ORDER BY data_estrena ASC LIMIT 5;";

        }
        else {
            comanda = "SELECT * FROM capitol WHERE data_estrena > NOW() AND numero = 1 ORDER BY data_estrena ASC LIMIT 5;";

        }
        sql::ResultSet* res = con.consultaSQL(comanda);

        while (res->next()) {  // Asegurarse de que se encontró un resultado
            PassarelaCapitol capitol;
            capitol.setTitolSerie(res->getString("titol_serie"));
            capitol.setNumTemporada(res->getInt("numero_temporada"));
            capitol.setNumero(res->getInt("numero"));
            capitol.setTitol(res->getString("titol"));
            capitol.setDataEstrena(res->getString("data_estrena"));
            capitol.setQualificacio(res->getString("qualificacio"));
            capitol.setDuracio(res->getInt("duracio_capitol"));
            capitol.setModalitat(res->getString("modalitat"));
            cjCapitols.push_back(capitol);
        }
    }    
    return cjCapitols;
}

