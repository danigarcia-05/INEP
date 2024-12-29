#include "PassarelaCapitol.h"

// Constructor por defecto
PassarelaCapitol::PassarelaCapitol()
    : _titolSerie(""), _numTemporada(0), _numero(0), _titol(""), _dataEstrena(""), _qualificacio(""), _duracio(0), _modalitat("") {}

// Constructor con parámetros
PassarelaCapitol::PassarelaCapitol(string titolSerie, int numT, int numC, string titol, string dataEstrena, string qualificacio, int duracio, string modalitat)
    : _titolSerie(titolSerie), _numTemporada(numT), _numero(numC), _titol(titol), _dataEstrena(dataEstrena), _qualificacio(qualificacio), _duracio(duracio), _modalitat(modalitat) {}

// GETTERS
string PassarelaCapitol::obteTitolSerie() const{
    return _titolSerie;
}

int PassarelaCapitol::obteNumTemporada() const{
    return _numTemporada;
}

int PassarelaCapitol::obteNumero() const{
    return _numero;
}

string PassarelaCapitol::obteTitol() const{
    return _titol;
}

string PassarelaCapitol::obteDataEstrena() const{
    return _dataEstrena;
}

string PassarelaCapitol::obteQualificacio() const{
    return _qualificacio;
}

int PassarelaCapitol::obteDuracio() const{
    return _duracio;
}

string PassarelaCapitol::obteModalitat() const{
    return _modalitat;
}



// SETTERS
void PassarelaCapitol::setTitolSerie(string titolSerie) {
    _titolSerie = titolSerie;
}

void PassarelaCapitol::setNumTemporada(int numTemporada) {
    _numTemporada = numTemporada;
}

void PassarelaCapitol::setNumero(int numero) {
    _numero = numero;
}

void PassarelaCapitol::setTitol(string titol) {
    _titol = titol;
}

void PassarelaCapitol::setDataEstrena(string dataEstrena) {
    _dataEstrena = dataEstrena;
}

void PassarelaCapitol::setQualificacio(string qualificacio) {
    _qualificacio = qualificacio;
}

void PassarelaCapitol::setDuracio(int duracio) {
    _duracio = duracio;
}

void PassarelaCapitol::setModalitat(string modalitat) {
    _modalitat = modalitat;
}

// Sobrecarga del operador de asignación
PassarelaCapitol& PassarelaCapitol::operator=(const PassarelaCapitol& obj) {
    if (this != &obj) {
        _titolSerie = obj._titolSerie;
        _numTemporada = obj._numTemporada;
        _numero = obj._numero;
        _titol = obj._titol;
        _dataEstrena = obj._dataEstrena;
        _qualificacio = obj._qualificacio;
        _duracio = obj._duracio;
        _modalitat = obj._modalitat;
    }
    return *this;
}

void PassarelaCapitol::insereix() {
    ConnexioDB &con = ConnexioDB::getInstance();
    string query = "INSERT INTO visualitzacio_capitol (titol_serie, numero_temporada, numero, titol, data_estrena, qualificacio, modalitat) VALUES('" +
    _titolSerie + "', " + to_string(_numTemporada) + ", " + to_string(_numero) + ", '" + _titol + "', '" + _dataEstrena + "', '" + _qualificacio + "', '" + _modalitat + "')";
    
    con.executarSQL(query);
}

void PassarelaCapitol::modifica() {
    ConnexioDB& con = ConnexioDB::getInstance();

    // Establim la sentència SQL.
    string query = "UPDATE visualitzacio_capitol SET data_estrena = '" + _dataEstrena + "', qualificacio = '" + _qualificacio + "', titol = '" + _titol + "' WHERE titol_serie = '" + _titolSerie + "' AND numero_temporada = " + to_string(_numTemporada) + " AND numero = " + to_string(_numero) + " AND modalitat = " + _modalitat + ";";

    // Executem la modificació d'usuari a la base de dades.
    con.executarSQL(query);
}

void PassarelaCapitol::esborra() {
    ConnexioDB &con = ConnexioDB::getInstance();

    // Establim la sentència SQL.
    string query = "DELETE FROM visualitzacio_capitol WHERE titol_serie = '" + _titolSerie + "' AND numero_temporada = " + to_string(_numTemporada) + " AND numero = " + to_string(_numero) + ";";

    // Executem la modificació d'usuari a la base de dades.
    con.executarSQL(query);
}

