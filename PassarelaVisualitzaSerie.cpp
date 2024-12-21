#include "PassarelaVisualitzaSerie.h"


PassarelaVisualitzaSerie::PassarelaVisualitzaSerie()
    : _sobrenom(""), _titolSerie(""), _numVisualitzacions(0), _numTemporada(0), _numCapitol(0), _data("") {}


PassarelaVisualitzaSerie::PassarelaVisualitzaSerie(string sobrenomU, string titolSerieU, int numVisualitzacionsU, int numTemporadaU, int numCapitolU, string dataU)
    : _sobrenom(sobrenomU), _titolSerie(titolSerieU), _numVisualitzacions(numVisualitzacionsU), _numTemporada(numTemporadaU), _numCapitol(numCapitolU), _data(dataU) {}


string PassarelaVisualitzaSerie::obteSobrenom() const {
    return _sobrenom;
}

void PassarelaVisualitzaSerie::setSobrenom(const string& sobrenomU) {
    _sobrenom = sobrenomU;
}


string PassarelaVisualitzaSerie::obteTitolSerie() const {
    return _titolSerie;
}

void PassarelaVisualitzaSerie::setTitolSerie(const string& titolSerieU) {
    _titolSerie = titolSerieU;
}


int PassarelaVisualitzaSerie::obteNumVisualitzacions() const {
    return _numVisualitzacions;
}

void PassarelaVisualitzaSerie::setNumVisualitzacions(int numVisualitzacionsU) {
    _numVisualitzacions = numVisualitzacionsU;
}


int PassarelaVisualitzaSerie::obteNumTemporada() const {
    return _numTemporada;
}

void PassarelaVisualitzaSerie::setNumTemporada(int numTemporadaU) {
    _numTemporada = numTemporadaU;
}


int PassarelaVisualitzaSerie::obteNumCapitol() const {
    return _numCapitol;
}

void PassarelaVisualitzaSerie::setNumCapitol(int numCapitolU) {
    _numCapitol = numCapitolU;
}


string PassarelaVisualitzaSerie::obteData() const {
    return _data;
}

void PassarelaVisualitzaSerie::setData(const string& dataU) {
    _data = dataU;
}


void PassarelaVisualitzaSerie::insereix() {
    
}

void PassarelaVisualitzaSerie::modifica() {
    
}

void PassarelaVisualitzaSerie::esborra() {

}

