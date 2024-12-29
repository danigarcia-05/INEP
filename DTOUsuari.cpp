#include "DTOUsuari.h"


DTOUsuari::DTOUsuari() {

}

DTOUsuari::DTOUsuari(string nomU, string sobrenomU, string  correuElectronicU, string dataNaixementU, string  modalitatU){
    _nom = nomU;
    _sobrenom = sobrenomU;
    _correuElectronic = correuElectronicU;
    _dataNaixement = dataNaixementU;
    _modalitat = modalitatU;
}

//-------------
//GETTERS
//-------------
string DTOUsuari::obteNom() const{
    return _nom; 
}

string DTOUsuari::obteSobrenom() const{
    return _sobrenom; 
}

string DTOUsuari::obteCorreu() const{
    return _correuElectronic; 
}

string DTOUsuari::obteDataN() const{
    return _dataNaixement;
}
    
string DTOUsuari::obteModalitatS() const{
    return _modalitat;
}

//-------------
//SETTERS
//-------------
void DTOUsuari::setNom(string nom) {
    _nom=nom;
}

void DTOUsuari::setSobrenom(string sobrenom) {
    _sobrenom=sobrenom;
}

void DTOUsuari::setCorreu(string correuElectronic) {
    _correuElectronic=correuElectronic;
}

void DTOUsuari::setDataN(string dataNaixement) {
    _dataNaixement=dataNaixement;
}

void DTOUsuari::setModalitatS(string modalitat) {
    _modalitat=modalitat;
}

DTOUsuari& DTOUsuari::operator=(const DTOUsuari& obj) {
    if (this != &obj) {
        _nom = obj._nom;
        _sobrenom = obj._sobrenom;
        _correuElectronic = obj._correuElectronic;
        _dataNaixement = obj._dataNaixement;
        _modalitat = obj._modalitat;
    }
    return *this;
}