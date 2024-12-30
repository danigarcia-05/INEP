#include "DTONovetat.h"

// Constructores
DTONovetat::DTONovetat() : _data(""), _tipus(""), _titol(""), _qualificacio(""), _detalls(0) {}

DTONovetat::DTONovetat(string data, string tipus, string titol, string qualificacio, int detalls)
    : _data(data), _tipus(tipus), _titol(titol), _qualificacio(qualificacio), _detalls(detalls) {
}

DTONovetat::~DTONovetat() {

}

// Métodos getter
string DTONovetat::obteData() const {
    return _data;
}

string DTONovetat::obteTipus() const {
    return _tipus;
}

string DTONovetat::ObteTitol() const {
    return _titol;
}

string DTONovetat::obteQualificacio() const {
    return _qualificacio;
}

int DTONovetat::obteDetalls() const {
    return _detalls;
}

// Métodos setter
void DTONovetat::setData(string data) {
    _data = data;
}

void DTONovetat::setTiups(string tipus) {
    _tipus = tipus;
}

void DTONovetat::setTitol(string titol) {
    _titol = titol;
}

void DTONovetat::setQualificacio(string qualificacio) {
    _qualificacio = qualificacio;
}

void DTONovetat::setDetalls(int detalls) {
    _detalls = detalls;
}