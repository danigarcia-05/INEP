#include "PassarelaVisualitzaSerie.h"


PassarelaVisualitzaSerie::PassarelaVisualitzaSerie()
    : _sobrenom(""), _titolSerie(""), _numVisualitzacions(0), _numTemporada(0), _numCapitol(0), _data("") {}


PassarelaVisualitzaSerie::PassarelaVisualitzaSerie(string sobrenomU, string titolSerieU, int numVisualitzacionsU, int numTemporadaU, int numCapitolU, string dataU)
    : _sobrenom(sobrenomU), _titolSerie(titolSerieU), _numVisualitzacions(numVisualitzacionsU), _numTemporada(numTemporadaU), _numCapitol(numCapitolU), _data(dataU) {}


//GETTERS
string PassarelaVisualitzaSerie::obteSobrenom(){
    return _sobrenom;
}
string PassarelaVisualitzaSerie::obteTitolSerie(){
    return _titolSerie;
}
int PassarelaVisualitzaSerie::obteNumVisualitzacions(){
    return _numVisualitzacions;
}
int PassarelaVisualitzaSerie::numTemporada(){
    return _numTemporada;
}
int PassarelaVisualitzaSerie::numCapitol(){
    return _numCapitol;
}
string PassarelaVisualitzaSerie::obteData(){
    return _data;
}


//SETTERS
void PassarelaVisualitzaSerie::setSobrenom(string sobrenom){
    _sobrenom = sobrenom;
}
void PassarelaVisualitzaSerie::setTitolSerie(string titolS){
    _titolSerie = titolS;
}
void PassarelaVisualitzaSerie::setNumVisualitzacions(int nVis){
    _numVisualitzacions = nVis;
}
void PassarelaVisualitzaSerie::setNumTemporada(int temp){
    _numTemporada = temp;
}
void PassarelaVisualitzaSerie::setNumCapitol(int cap){
    _numCapitol = cap;
}
void PassarelaVisualitzaSerie::setData(string data){
    _data = data;
}


void PassarelaVisualitzaSerie::insereix() {
    
}

void PassarelaVisualitzaSerie::modifica() {
    
}

void PassarelaVisualitzaSerie::esborra() {

}

