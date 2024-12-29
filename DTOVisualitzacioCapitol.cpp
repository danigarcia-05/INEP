#include "DTOVisualitzacioCapitol.h"

// Constructor por defecto
DTOVisualitzacioCapitol::DTOVisualitzacioCapitol()
    : _sobrenom(""), _titolSerie(""), _numTemporada(0), _numCapitol(0), _data(""), _numVisualitzacions(0) {
}

// Constructor parametrizado
DTOVisualitzacioCapitol::DTOVisualitzacioCapitol(string sobrenom, string titolS, int numTemporada, int numero, string data, int numVisualitzacions)
    : _sobrenom(sobrenom), _titolSerie(titolS), _numTemporada(numTemporada), _numCapitol(numero), _data(data), _numVisualitzacions(numVisualitzacions) {
}

// GETTERS
string DTOVisualitzacioCapitol::obteSobrenom() const{
    return _sobrenom;
}

string DTOVisualitzacioCapitol::obteTitolSerie() const{
    return _titolSerie;
}

int DTOVisualitzacioCapitol::obteNumTemporada() const{
    return _numTemporada;
}

int DTOVisualitzacioCapitol::obteNumCapitol() const{
    return _numCapitol;
}

string DTOVisualitzacioCapitol::obteData() const{
    return _data;
}

int DTOVisualitzacioCapitol::obteNumVisualitzacions() const{
    return _numVisualitzacions;
}

// SETTERS
void DTOVisualitzacioCapitol::setSobrenom(string sobrenom) {
    _sobrenom = sobrenom;
}

void DTOVisualitzacioCapitol::setTitolSerie(string titolS) {
    _titolSerie = titolS;
}

void DTOVisualitzacioCapitol::setNumTemporada(int numTemporada) {
    _numTemporada = numTemporada;
}

void DTOVisualitzacioCapitol::setNumCapitol(int numCapitol) {
    _numCapitol = numCapitol;
}

void DTOVisualitzacioCapitol::setData(string data) {
    _data = data;
}

void DTOVisualitzacioCapitol::setNumVisualitzacions(int numVisualitzacions) {
    _numVisualitzacions = numVisualitzacions;
}

// Operador d'asignació
DTOVisualitzacioCapitol& DTOVisualitzacioCapitol::operator=(const DTOVisualitzacioCapitol& obj) {
    if (this != &obj) {
        _sobrenom = obj._sobrenom;
        _titolSerie = obj._titolSerie;
        _numTemporada = obj._numTemporada;
        _numCapitol = obj._numCapitol;
        _data = obj._data;
        _numVisualitzacions = obj._numVisualitzacions;
    }
    return *this;
}