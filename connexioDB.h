#ifndef CONNEXIODB_HPP
#define CONNEXIODB_HPP
#pragma once

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
using namespace std;

class ConnexioDB {
private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;

    static ConnexioDB* _ins;  // Punter estàtic a la instància única
    ConnexioDB();             // Constructor privat

    // Mètode privat per carregar la configuració des d'un fitxer
    std::map<std::string, std::string> loadConfig(const std::string& filename);

public:
    static ConnexioDB& getInstance();  // Mètode estàtic que retorna una referència a la instància única

    ~ConnexioDB();  // Destructor

    sql::ResultSet* consultaSQL(const std::string& sql);  // Mètode per a consultes SQL
    void executarSQL(const std::string& sql);            // Mètode per executar comandes SQL
};

#endif
