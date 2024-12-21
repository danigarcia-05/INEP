#include "CercadoraUsuari.h"
#include "PassarelaUsuari.h"
#include "connexioDB.h"
#include <stdexcept>  // Para std::runtime_error
#include <string>     // Para std::string
using namespace std;

PassarelaUsuari CercadoraUsuari::cercaUsuari(string sobrenomU) const {
    PassarelaUsuari u;
    ConnexioBD& con = ConnexioBD::getInstance();
    string sql = "SELECT * FROM Usuari WHERE sobrenom = '" +
    sobrenomU + "'";
    sql::ResultSet* res = con.executarSelect(sql);
    // Si no troba cap fila, activa excepció
    if (!res->next()) {
        throw runtime_error("UsuariNoExisteix");
    }
    else {
        u.setSobrenom(res->getString("sobrenom"));
        u.setNom(res->getString("nom"));
        u.setCorreuElectronic(res->getString("correu_electronic"));
        delete res;
    }
    return u;
}