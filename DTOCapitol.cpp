#include "DTOCapitol.h"

// Constructor por defecto
DTOCapitol::DTOCapitol() 
    : _titolSerie(""), _numTemporada(0), _numero(0), _titol(""), _dataEstrena(""), _qualificacio(""), _duracioC(0), _modalitat("") {}

// Constructor parametrizado
DTOCapitol::DTOCapitol(string titolS, int numTemporada, int numero, string titol, string dataEstrena, string qualificacio, int duracioC, string modalitat) 
    : _titolSerie(titolS), _numTemporada(numTemporada), _numero(numero), _titol(titol), _dataEstrena(dataEstrena), _qualificacio(qualificacio), _duracioC(duracioC), _modalitat(modalitat) {}

// GETTERS
string DTOCapitol::obteTitolS() const{
    return _titolSerie;
}

int DTOCapitol::obteNumTemp() const{
    return _numTemporada;
}

int DTOCapitol::obteNumCap() const{
    return _numero;
}

string DTOCapitol::obteTitolC() const{
    return _titol;
}

string DTOCapitol::obteDataEstrena() const{
    return _dataEstrena;
}

string DTOCapitol::obteQualificacio() const{
    return _qualificacio;
}

int DTOCapitol::obteDuracioC() const{
    return _duracioC;
}

string DTOCapitol::obteModalitat() const{
    return _modalitat;
}

// SETTERS
void DTOCapitol::setTitolS(string titolS) {
    _titolSerie = titolS;
}

void DTOCapitol::setNumTemp(int numTemp) {
    _numTemporada = numTemp;
}

void DTOCapitol::setNumCap(int numCap) {
    _numero = numCap;
}

void DTOCapitol::setTitolC(string titolC) {
    _titol = titolC;
}

void DTOCapitol::setDataEstrena(string dataEstrena) {
    _dataEstrena = dataEstrena;
}

void DTOCapitol::setQualificacio(string qualificacio) {
    _qualificacio = qualificacio;
}

void DTOCapitol::setDuracioC(int duracioC) {
    _duracioC = duracioC;
}

void DTOCapitol::setModalitat(string modalitat) {
    _modalitat = modalitat;
}

// Operador de asignación
DTOCapitol& DTOCapitol::operator=(const DTOCapitol& obj) {
    if (this != &obj) {
        _titolSerie = obj._titolSerie;
        _numTemporada = obj._numTemporada;
        _numero = obj._numero;
        _titol = obj._titol;
        _dataEstrena = obj._dataEstrena;
        _qualificacio = obj._qualificacio;
        _duracioC = obj._duracioC;
        _modalitat = obj._modalitat;
    }
    return *this;
}
