#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>

class ConnexioBD {
private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;

public:
    ConnexioBD() : driver(nullptr), con(nullptr), stmt(nullptr) {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("ubiwan.epsevg.upc.edu:3306", "inep13", "agheeGak0Ofe4m");
        con->setSchema("inep13");
        stmt = con->createStatement();
    }

    ~ConnexioBD() {
        con->close();
    }

    sql::ResultSet* consultaSQL(const string& sql) {
        if (stmt != nullptr) return stmt->executeQuery(sql);
    }

    void executarSQL(const string& sql) {
        if (stmt != nullptr) stmt->execute(sql);
    }
};