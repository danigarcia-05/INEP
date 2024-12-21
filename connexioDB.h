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

class ConnexioDB {
private:
    mysql::MySQL_Driver* driver;
    Connection* con;
    Statement* stmt;
    
    static ConnexioDB* _ins;  // Corregido: el puntero estático debe ser de tipo ConnexioBD*
    ConnexioDB();  // Constructor privado

public:
    static ConnexioDB& getInstance();  // Método estático que retorna un puntero de tipo ConnexioBD*

    ~ConnexioDB();  // Destructor

    sql::ResultSet* consultaSQL(const string& sql);  // Método para consulta SQL
    void executarSQL(const string& sql);  // Método para ejecutar SQL
};

#endif
