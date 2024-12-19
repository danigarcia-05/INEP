#ifndef CONNEXIODB_HPP
#define CONNEXIODB_HPP
#pragma once
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
    
    static ConnexioBD* ins;
    ConnexioBD() : driver(nullptr), con(nullptr), stmt(nullptr);
public:
    ConnexioBD* getInstance();

    ~ConnexioBD();

    sql::ResultSet* consultar(const string& sql);

    void executar(const string& sql);
};

#endif 
