#include "CercadoraUsuari.h"


CercadoraUsuari::CercadoraUsuari(){
}

PassarelaUsuari CercadoraUsuari::cercaUsuari(string sobrenomU) const {
    PassarelaUsuari u;
    ConnexioDB& con = ConnexioDB::getInstance();
    string comanda = "SELECT * FROM usuari WHERE sobrenom = '" + sobrenomU + "'";
    sql::ResultSet* res = con.consultaSQL(comanda);
    // Si no troba cap fila, activa excepció
    if (not res->next()) {
        throw runtime_error("UsuariNoExisteix");
    }
    else {
        u.setSobrenom(res->getString("sobrenom"));
        u.setNom(res->getString("nom"));
        u.setCorreuElectronic(res->getString("correu_electronic"));
        u.setContrasenya(res->getString("contrasenya"));
        u.setDataNaixament(res->getString("data_naixement"));
        u.setModalitatSubscripcio(res->getString("subscripcio"));
        delete res;
    }
    return u;
}