#include "connexioDB.h"

// Inicialización del puntero estático
ConnexioDB* ConnexioDB::_ins = nullptr;

ConnexioDB& ConnexioDB::getInstance() {
    if (_ins == nullptr) {
        _ins = new ConnexioDB();
    }
    return *_ins;
}

ConnexioDB::ConnexioDB() : driver(nullptr), con(nullptr), stmt(nullptr) {
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("ubiwan.epsevg.upc.edu:3306", "inep13", "agheeGak0Ofe4m");
    con->setSchema("inep13");
    stmt = con->createStatement();
}

ConnexioDB::~ConnexioDB() {
    if (stmt) delete stmt;
    if (con) {
        con->close();
        delete con;
    }
}

sql::ResultSet* ConnexioDB::consultaSQL(const std::string& sql) {
    if (stmt != nullptr) {
        return stmt->executeQuery(sql);
    }
    return nullptr;
}

void ConnexioDB::executarSQL(const std::string& sql) {
    if (stmt != nullptr) {
        stmt->execute(sql);
    }
}
