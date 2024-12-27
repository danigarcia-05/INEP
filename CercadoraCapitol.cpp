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
        cjCapitols.push_back(capitol);
    }
    return cjCapitols;
}

