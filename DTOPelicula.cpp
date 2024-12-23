#include "DTOPelicula.h"

DTOUPelicula::DTOPelicula() {

}

DTOPelicula::DTOPelicula(string sobrenomU, string titolPelU, string  dataU, int numVisU) {
    _nom = nomU;
    _sobrenom = sobrenomU;
    _correuElectronic = correuElectronicU;
    _dataNaixement = dataNaixementU;
    _modalitat = modalitatU;
}

//-------------
//GETTERS
//-------------
string DTOPelicula::obteNom() {
    return _nom;
}

string DTOPelicula::obteSobrenom() {
    return _sobrenom;
}

string DTOPelicula::obteCorreu() {
    return _correuElectronic;
}

string DTOPelicula::obteDataN() {
    return _dataNaixement;
}

string DTOPelicula::obteModalitatS() {
    return _modalitat;
}

//-------------
//SETTERS
//-------------
void DTOPelicula::setNom(string nom) {
    _nom = nom;
}

void DTOPelicula::setSobrenom(string sobrenom) {
    _sobrenom = sobrenom;
}

void DTOPelicula::setCorreu(string correuElectronic) {
    _correuElectronic = correuElectronic;
}

void DTOPelicula::setDataN(string dataNaixement) {
    _dataNaixement = dataNaixement;
}

void DTOPelicula::setModalitatS(string modalitat) {
    _modalitat = modalitat;
}

DTOPelicula& DTOPelicula::operator=(const DTOPelicula& obj) {
    if (this != &obj) {
        _nom = obj._nom;
        _sobrenom = obj._sobrenom;
        _correuElectronic = obj._correuElectronic;
        _dataNaixement = obj._dataNaixement;
        _modalitat = obj._modalitat;
    }
    return *this;
}