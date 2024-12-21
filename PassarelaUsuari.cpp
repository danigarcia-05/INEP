#include "PassarelaUsuari.h"

/*
*****************************************************
                   CONSTRUCTORS
*****************************************************
*/
PassarelaUsuari::PassarelaUsuari() {

}

PassarelaUsuari::PassarelaUsuari(string sobrenomU, string nomU, string correuElectronicU)
{
    _sobrenom = sobrenomU;                 // sobrenom atribut privat de la classe
    _nom = nomU;                           // nom atribut privat de la classe
    _correuElectronic = correuElectronicU; // correuElectronic atribut
}

PassarelaUsuari::PassarelaUsuari(string nomU, string sobrenomU, string contrasenyaU, string correuElectronicU, 
                                                                    string dataNaixementU, string modalitatU){
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

string PassarelaUsuari::obteDataNaixament(){
    return _dataNaixament;
}

string PassarelaUsuari::obteModalitatSubscripcio(){
    return _modalitatSubscripcio;
}

/*
*****************************************************
                   SETTERS
*****************************************************
*/


void PassarelaUsuari::setSobrenom(string sobrenom) {
    _sobrenom=sobrenom;
}
void PassarelaUsuari::setNom(string nom) {
    _nom=nom;
}
void PassarelaUsuari::setContrasenya(string contrasenya) {
    _contrasenya=contrasenya;
}
void PassarelaUsuari::setCorreuElectronic(string correuElectornic) {
    _correuElectronic=correuElectornic;
}
void PassarelaUsuari::setDataNaixament(string dataNaixement) {
    _dataNaixament=dataNaixement;
}
void PassarelaUsuari::setModalitatSubscripcio(string modalitatSubscripcio) {
    _modalitatSubscripcio=modalitatSubscripcio;
}

PassarelaUsuari& PassarelaUsuari::operator=(const PassarelaUsuari& obj) {
    if (this != &obj) {  // Comprobación de autorasignación
        _sobrenom = obj._sobrenom;
        _nom = obj._nom;
        _contrasenya = obj._contrasenya;
        _correuElectronic = obj._correuElectronic;
        _dataNaixament = obj._dataNaixament;  // Asumimos que Data tiene su propio operador=
        _modalitatSubscripcio = obj._modalitatSubscripcio;
    }
    return *this;  // Devolver la referencia al objeto actual
}
/*
*****************************************************
                   MODIFICADORS
*****************************************************
*/
void PassarelaUsuari::insereix()
{
    ConnexioDB &con = ConnexioDB::getInstance();
    string query = "INSERT INTO usuari (sobrenom, nom, contrasenya, correu_electronic, data_naixement, subscripcio) VALUES('" +
        _sobrenom + "', '" + _nom + "', '" + _contrasenya + "','" + _correuElectronic + "', '" + _dataNaixament + "', '" + _modalitatSubscripcio + "')";
    con.executarSQL(query);
}

void PassarelaUsuari::modifica()
{
    ConnexioDB &con = ConnexioDB::getInstance();

	// Establim la sentència SQL.
	string query = "UPDATE Usuari SET nom = '" + _nom + "', correu_electronic = '" + _correuElectronic + "' WHERE sobrenom = '" + _sobrenom + "'";

	// Executem la modificació d' usuari a la base de dades.
	con.executarSQL(query);
	
}

void PassarelaUsuari::esborra()
{
	ConnexioDB &con = ConnexioDB::getInstance();

	// Establim la sentència SQL.
	string query = "DELETE FROM usuari WHERE sobrenom = '" + _sobrenom + "'";

	// Executem la modificació d' usuari a la base de dades.
	con.executarSQL(query);
}
