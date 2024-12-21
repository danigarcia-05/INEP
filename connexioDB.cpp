#include "connexioDB.h"

ConnexioBD* ConnexioBD::getInstance(){
    if (ins == nullptr) {
        ins = new ConnexioBD();
    }
    return ins;
}

ConnexioBD& ConnexioBD::ins = nullptr;

ConnexioDB::ConnexioBD() : driver(nullptr), con(nullptr), stmt(nullptr) {
    driver = sql::mysql::get_mysql_driver_instance();
    con = driver->connect("ubiwan.epsevg.upc.edu:3306", "inep13", "agheeGak0Ofe4m");
    con->setSchema("inep13");
    stmt = con->createStatement();
}

~ConnexioDB::ConnexioBD() {
    con->close();
}

sql::ResultSet* consultaSQL(const string& sql) {
		if (stmt != nullptr) {
			return stmt->executeQuery(sql);
		}
	}

	void executarSQL(const string& sql) {
		if (stmt != nullptr) {
			stmt->execute(sql);
		}
	}