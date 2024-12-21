#ifndef CONNEXIODB_HPP
#define CONNEXIODB_HPP
#pragma once
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>
#include <string>

using namespace sql;
using namespace std;  // Añadido para evitar problemas con el tipo 'string'

class ConnexioBD {
private:
    mysql::MySQL_Driver* driver;
    Connection* con;
    Statement* stmt;
    
    static ConnexioBD* ins;  // Corregido: el puntero estático debe ser de tipo ConnexioBD*
    ConnexioBD();  // Constructor privado

public:
    static ConnexioBD* getInstance();  // Método estático que retorna un puntero de tipo ConnexioBD*

    ~ConnexioBD();  // Destructor

    sql::ResultSet* consultaSQL(const string& sql);  // Método para consulta SQL
    void executarSQL(const string& sql);  // Método para ejecutar SQL
};

#endif
