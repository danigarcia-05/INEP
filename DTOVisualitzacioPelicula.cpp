#include "DTOVisualitzacioPelicula.h"

DTOVisualitzacioPelicula::DTOVisualitzacioPelicula() {}

DTOVisualitzacioPelicula::DTOVisualitzacioPelicula(string titolP, string sobrenomU, string dataVP, int visualitzacions){
    _titol = titolP;
    _sobrenom = sobrenomU;
    _dataVP = dataVP;
    _visualitzacions = visualitzacions;

}

//-------------
//GETTERS
//-------------
string DTOVisualitzacioPelicula::obteTitol() {
    return _titol; 
}

string DTOVisualitzacioPelicula::obteSobrenom() {
    return _sobrenom; 
}

string DTOVisualitzacioPelicula::obteDataVP(){
    return _dataVP; 
}

int DTOVisualitzacioPelicula::obteVisualitzacions() {
    return _visualitzacions;
}


//-------------
//SETTERS
//-------------
void DTOVisualitzacioPelicula::setTitol(string titol) {
    _titol=titol;
}

void DTOVisualitzacioPelicula::setSobrenom(string sobrenom) {
    _sobrenom=sobrenom;
}

void DTOVisualitzacioPelicula::setDataVP(string dataVP) {
    _dataVP=dataVP;
}

void DTOVisualitzacioPelicula::setVisualitzacions(int visualitzacions) {
    _visualitzacions=visualitzacions;
}


DTOVisualitzacioPelicula& DTOVisualitzacioPelicula::operator=(const DTOVisualitzacioPelicula& obj) {
    if (this != &obj) {
        _titol = obj._titol;
        _sobrenom = obj._sobrenom;
        _dataVP = obj._dataVP;
        _visualitzacions = obj._visualitzacions;
    }
    return *this;
}