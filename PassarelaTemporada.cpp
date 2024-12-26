#include "PassarelaTemporada.h"

PassarelaTemporada::PassarelaTemporada(){
}

PassarelaTemporada::PassarelaTemporada(string titolS, int numTemporada){
    _titolS = titolS;
    _numTemporada = numTemporada;
}

//GETTERS
string PassarelaTemporada::obteTitolSerie(){
    return _titolS;
}

int PassarelaTemporada::obteNumTemporada(){
    return _numTemporada;
}

PassarelaTemporada& PassarelaTemporada::operator=(const PassarelaTemporada& obj){
    if (this != &obj) { 
        _titolS = obj._titolS;
        _numTemporada = obj._numTemporada;
    }
    return *this;  
}

//SETTERS
void PassarelaTemporada::setTitol(string titol){
    _titolS = titol;
}

void PassarelaTemporada::setNumTemporada(int numTemporada){
    _numTemporada = numTemporada;
}

void PassarelaTemporada::insereix()
{
    ConnexioDB &con = ConnexioDB::getInstance();

    string query = "INSERT INTO temporada (titol_serie, numero) VALUES ('" + titolS + "', " + std::to_string(numTemporada) + ");";
    con.executarSQL(query);
}

void PassarelaTemporada::esborra()
{
	ConnexioDB &con = ConnexioDB::getInstance();

	// Establim la sentència SQL.
	string query = "DELETE FROM temporada WHERE titol_serie = '" + titolS + "' AND numero = " + std::to_string(numTemporada) + ";";

	// Executem la modificació d' usuari a la base de dades.
	con.executarSQL(query);
}

