#pragma once
using namespace std;
#include <iostream>
#include <string>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>



class CapaDePresentacio {
private:
    static CapaDePresentacio* ins;

    CapaDePresentacio();

    struct Usuari {
        string sobrenom;
        string nom;
        string correu;
    };  

public:
    CapaDePresentacio* getins();

    void iniciarSessio();

    void registrarUsuari();
    void consultarUsuari();
    void modificarUsuari();
    void borrarUsuari();

    void gestioPelicules();
    void gestioSeries();
    void consultesEdat();

    void ultimesNovetats();
    void proximesEstrenes();
};

