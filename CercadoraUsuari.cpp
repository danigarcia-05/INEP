#include "CercadoraUsuari.h"
#include "PassarelaUsuari.h"

PassarelaUsuari CercadoraUsuari::cercaUSuari(string sobrenomU) {
    PassarelaUsuari u;
    ConnexioBD& con = ConnexioBD::getInstance();
    string sql = "SELECT * FROM Usuari WHERE sobrenom = '" +
    sobrenomU + "'";
    sql::ResultSet* res = con.executarSelect(sql);
    // Si no troba cap fila, activa excepció
    if (!res->next()) {
        throw runtime_error("Usuari no existeix");
    }
    else {
        u.posaSobrenom(res->getString("sobrenom"));
        u.posaNom(res->getString("nom"));
        u.posaCorreuElectronic(res->getString("correu_electronic"));
        delete res;
    }
    return u;
}