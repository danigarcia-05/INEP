#ifndef CONNEXIODB_HPP
#define CONNEXIODB_HPP
#pragma once

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>
#include <string>

class ConnexioDB {
private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;

    static ConnexioDB* _ins;  // Puntero estático a la instancia única
    ConnexioDB();             // Constructor privado

public:
    static ConnexioDB& getInstance();  // Método estático que retorna una referencia a la instancia única

    ~ConnexioDB();  // Destructor

    sql::ResultSet* consultaSQL(const std::string& sql);  // Método para consultas SQL
    void executarSQL(const std::string& sql);            // Método para ejecutar comandos SQL
};

#endif
