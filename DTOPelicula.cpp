#include "DTOPelicula.h"

DTOPelicula::DTOPelicula() {}

DTOPelicula::DTOPelicula(string titolP, string descripcioP, string  qualificacioP, string dataP, int duracioP, string tipusP){
    _titol = titolP;
    _descripcio = descripcioP;
    _qualificacio = qualificacioP;
    _data = dataP;
    _duracio = duracioP;
    _tipus = tipusP;
}

//-------------
//GETTERS
//-------------
string DTOPelicula::obteTitol() {
    return _titol; 
}

string DTOPelicula::obteDescripcio() {
    return _descripcio; 
}

string DTOPelicula::obteQualificacio(){
    return _qualificacio; 
}

string DTOPelicula::obteDataP() {
    return _data;
}
    
int DTOPelicula::obteDuracio() {
    return _duracio;
}

string DTOPelicula::obteTipus() {
    return _tipus;
}

//-------------
//SETTERS
//-------------
void DTOPelicula::setTitol(string titol) {
    _titol=titol;
}

void DTOPelicula::setDescripcio(string descripcio) {
    _descripcio=descripcio;
}

void DTOPelicula::setQualificacio(string qualificacio) {
    _qualificacio=qualificacio;
}

void DTOPelicula::setDataP(string data) {
    _data=data;
}

void DTOPelicula::setDuracio(int duracio) {
    _duracio=duracio;
}

void DTOPelicula::setTipus(string tipus) {
    _tipus=tipus;
}

DTOPelicula& DTOPelicula::operator=(const DTOPelicula& obj) {
    if (this != &obj) {
        _titol = obj._titol;
        _descripcio = obj._descripcio;
        _qualificacio = obj._qualificacio;
        _data = obj._data;
        _duracio = obj._duracio;
        _tipus = obj._tipus;
    }
    return *this;
}