#include "DTOUsuari.h"

DTOUsuari::DTOUsuari() {

}

DTOUsuari::DTOUsuari(string nomU, string sobrenomU, string  correuElectronicU, ???  dataNaixementU, string  modalitatU){
    _nom = nomU;
    _sobrenom = sobrenomU;
    _correuElectronic = correuElectronicU;
    _dataNaixement = dataNaixementU;
    _modalitat = modalitatU;
}

string DTOUsuari::obteNom() {
    return _nom; 
}

string DTOUsuari::obteSobrenom() {
    return _sobrenom; 
}

string DTOUsuari::obteCorreu(){
    return _correuElectronic; 
}

string DTOUsuari::obteDataN() {
    return __dataNaixement;
}
    
string DTOUsuari::obteModalitatS() {
    return __modalitat;
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