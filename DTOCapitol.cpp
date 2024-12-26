#include "DTOCapitol.h"

DTOCapitol::DTOCapitol(){

}

DTOCapitol::DTOCapitol(string titolC, string dataEstrenaC, string visualitzatC){
    _titol = titolC;
    _dataEstrena = dataEstrenaC;
    _dataVisualitzat = visualitzatC;
}

//GETTERS
string DTOCapitol::obteTitol(){
    return _titol;
}

string DTOCapitol::obteDataEstrena(){
     return _dataEstrena;
}

string DTOCapitol::obteDataVisualitzat(){
     return _dataVisualitzat;
}

//SETTERS
void DTOCapitol::setTitol(string titol){
    _titol = titol;
}

void DTOCapitol::setDataEstrena(string dataEstrena){
    _dataEstrena = dataEstrena;
}

void DTOCapitol::setDataVisualitzat(string dataVisualitzat){
    _dataVisualitzat = dataVisualitzat;
}

DTOCapitol& operator=(const DTOCapitol& obj){
    if (this != &obj) {
        _titol = obj._titol;
        _dataEstrena = obj._dataEstrena;
        _dataVisualitzat = obj._dataVisualitzat;
    }
    return *this;
}

