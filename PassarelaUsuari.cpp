#include "PassarelaUsuari.h"

/*
*****************************************************
                   CONSTRUCTORS
*****************************************************
*/
PassarelaUsuari::PassarelaUsuari(string sobrenomU, string nomU, string correuElectronicU)
{
    _sobrenom = sobrenomU;                 // sobrenom atribut privat de la classe
    _nom = nomU;                           // nom atribut privat de la classe
    _correuElectronic = correuElectronicU; // correuElectronic atribut
}

PassarelaUsuari::PassarelaUsuari(string nomU, string sobrenomU, string contraseinyaU, string correuElectronicU, 
                                                                    string dataNaixementU, subscripcio modalitatU){
    _nom = nomU;
    _sobrenom = sobrenomU;
    _contrasenya = contrasenyaU;
	_correuElectronic = correuElectronicU;
	_dataNaixament = dataNaixementU;
	_modalitatSubscripcio = modalitatU;
}

/*
*****************************************************
                    CONSULTORS
*****************************************************
*/
string PassarelaUsuari::obteSobrenom(){
    return _sobrenom;
}
string PassarelaUsuari::obteNom(){
    return _nom;
}

string PassarelaUsuari::obteContrasenya(){
    return _contrasenya;

}
string PassarelaUsuari::obteCorreuElectronic(){
    return _correuElectronic;
}

Data PassarelaUsuari::obteDataNaixament(){
    return _dataNaixament;
}

string PassarelaUsuari::obteModalitatSubscripcio(){
    return _modalitatSubscripcio;
}

/*
*****************************************************
                   MODIFICADORS
*****************************************************
*/
void PassarelaUsuari::insereix()
{
    ConnexioBD &con = ConnexioBD::getInstance();
    string query = "INSERT INTO usuari (sobrenom, nom, contrasenya, correu_electronic, data_naixement, subscripcio) VALUES('" +
                   _sobrenom + "', '" + _nom + "', '" + _contrasenya + "','" + _correuElectronic + "', '" + _dataNaixament + "', '" + _modalitatSubscripcio + "')";
    con.executar(query);
}

void PassarelaUsuari::modifica()
{
    ConnexioBD &con = ConnexioBD::getInstance();

	// Establim la sentència SQL.
	string sql = "UPDATE Usuari SET nom = '" + _nom + "', correu_electronic = '" + _correu + "' WHERE sobrenom = '" + _sobrenom + "'";

	// Executem la modificació d' usuari a la base de dades.
	con.executar(sql);
	
}

void PassarelaUsuari::esborra()
{
	ConnexioBD &con = ConnexioBD::getInstance();

	// Establim la sentència SQL.
	string sql = "DELETE FROM usuari WHERE sobrenom = '" + _sobrenom + "'";

	// Executem la modificació d' usuari a la base de dades.
	con.executar(sql);
}
