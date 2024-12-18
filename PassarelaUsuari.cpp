#include "PassarelaUsuari.h"
#include "connexioDB.h"
using namespace std;
#include <string>

PassarelaUsuari::PassarelaUsuari(string sobrenomU, string nomU, string correuElectronicU) {
    sobrenom = sobrenomU; // sobrenom atribut privat de la classe
    nom = nomU; // nom atribut privat de la classe
    correuElectronic = correuElectronicU; // correuElectronic atribut
}

void PassarelaUsuari::insereix(){
    ConnexioBD& con = ConnexioBD::getInstance();
    string query = "INSERT INTO usuari (sobrenom, nom, correu_electronic) VALUES('" +
    sobrenom + "', '" + nom + "', '" + correu_electronic + "')";
    con.executar(query);
}

