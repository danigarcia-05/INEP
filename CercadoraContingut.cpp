#include "CercadoraContingut.h"


CercadoraContingut::CercadoraContingut() {

}

CercadoraContingut& CercadoraContingut::getInstance() {
    static CercadoraContingut instance;
    return instance;
}

CercadoraContingut::~CercadoraContingut() {
}

PassarelaContingut CercadoraContingut::cercaContingut(string titolC) { 
    ConnexioDB& connexio = ConnexioDB::getInstance();
    PassarelaContingut resultat;

    // Establim la sentència SQL.
    string sql = "SELECT * FROM contingut WHERE titol ='" + titolC + "'";
    sql::ResultSet* res = connexio.consultaSQL(sql);

    // Mirem si existeix un usuari amb el sobrenom.
    if (res->next()) {
        resultat.setTitol(res->getString("titol"));
        resultat.setDescripcio(res->getString("descripcio"));
        resultat.setQualificacio(res->getString("qualificacio"));
        resultat.setTipus(res->getString("tipus"));
    }
    else {
        throw runtime_error("ContingutNoExisteix");
    }
    return resultat;
}

vector<PassarelaContingut> CercadoraContingut::cercaContingutRelacionat(string titolC) {

    ConnexioDB& con = ConnexioDB::getInstance();
    vector<PassarelaContingut> cjContinguts;

    string comanda = "SELECT * FROM contingut WHERE titol_x ='" + titolC + "'";
    sql::ResultSet* res = con.consultaSQL(comanda);

    // Mirem si existeix un usuari amb el sobrenom.
    while (res->next()) {
        PassarelaContingut contingut;
        contingut.setTitol(res->getString("titol"));
        contingut.setDescripcio(res->getString("descripcio"));
        contingut.setQualificacio(res->getString("qualificacio"));
        contingut.setTipus(res->getString("tipus"));
        cjContinguts.push_back(contingut);
    }
    return cjContinguts;
}
