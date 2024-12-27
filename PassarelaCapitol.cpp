#include "PassarelaCapitol.h"

PassarelaCapitol::PassarelaCapitol() {
    _titolSerie = "";
    _numTemporada = 0;
    _numero = 0;
    _titol = "";
    _dataEstrena = "";
    _qualificacio = "";
}

PassarelaCapitol::PassarelaCapitol(string titolSerie, int numT, int numC, string titol, string dataEstrena, string qualificacio) {
    _titolSerie = titolSerie;
    _numTemporada = numT;
    _numero = numC;
    _titol = titol;
    _dataEstrena = dataEstrena;
    _qualificacio = qualificacio;
}
// GETTERS
string PassarelaCapitol::obteTitolSerie() {
    return _titolSerie;
}

int PassarelaCapitol::obteNumTemporada() {
    return _numTemporada;
}

int PassarelaCapitol::obteNumero() {
    return _numero;
}

string PassarelaCapitol::obteTitol() {
    return _titol;
}

string PassarelaCapitol::obteDataEstrena() {
    return _dataEstrena;
}

string PassarelaCapitol::obteQualificacio() {
    return _qualificacio;
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

// Operador de asignación
PassarelaCapitol& PassarelaCapitol::operator=(const PassarelaCapitol& obj) {
    if (this != &obj) {
        _titolSerie = obj._titolSerie;
        _numTemporada = obj._numTemporada;
        _numero = obj._numero;
        _titol = obj._titol;
        _dataEstrena = obj._dataEstrena;
        _qualificacio = obj._qualificacio;
    }
    return *this;
}

void PassarelaCapitol::insereix() {
    ConnexioDB &con = ConnexioDB::getInstance();
    string query = "INSERT INTO visualitzacio_capitol (titol_serie, numero_temporada, numero, titol, data_estrena, qualificacio) VALUES('" +
        _titolSerie + "', " + to_string(_numTemporada) + ", " + to_string(_numero) + ", '" + _titol + "', '" + _dataEstrena + "', '" + _qualificacio + "')";
    con.executarSQL(query);
}

void PassarelaCapitol::modifica() {
    ConnexioDB& con = ConnexioDB::getInstance();

    // Establim la sentència SQL.
    string query = "UPDATE visualitzacio_capitol SET data_estrena = '" + _dataEstrena + "', qualificacio = '" + _qualificacio + "', titol = '" + _titol + "' WHERE titol_serie = '" + _titolSerie + "' AND numero_temporada = " + to_string(_numTemporada) + " AND numero = " + to_string(_numero) + ";";

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

