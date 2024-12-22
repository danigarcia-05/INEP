#include "PassarelaVisualitzaPel.h"


PassarelaVisualitzaPel::PassarelaVisualitzaPel() 
    : _sobrenom(""), _titolPelicula(""), _numVisualitzacions(0) {}


PassarelaVisualitzaPel::PassarelaVisualitzaPel(string sobrenomU, string titolPeliculaU, string dataU, int numVisualitzacionsU)
    : _sobrenom(sobrenomU), _titolPelicula(titolPeliculaU), _data(dataU), _numVisualitzacions(numVisualitzacionsU) {}


//GETTERS
string PassarelaVisualitzaPel::obteSobrenom(){
    return _sobrenom;
}
string PassarelaVisualitzaPel::obteTitolPelicula() {
    return _titolPelicula;
}
string PassarelaVisualitzaPel::obteData() {
    return _data;
}
int PassarelaVisualitzaPel::obteNumVisualitzacions() {
    return _numVisualitzacions;
}

//SETTERS
void PassarelaVisualitzaPel::setSobrenom(string sobrenom) {
    _sobrenom = sobrenom;
}
void PassarelaVisualitzaPel::setTitolPelicula(string titolP) {
    _titolPelicula = titolP;
}
void PassarelaVisualitzaPel::setData(string data){
    _data = data;
}
void PassarelaVisualitzaPel::setNumVisualitzacions(int nVis) {
    _numVisualitzacions = nVis;
}

void PassarelaVisualitzaPel::insereix() {
    
}

void PassarelaVisualitzaPel::modifica() {
    
}

void PassarelaVisualitzaPel::esborra() {
    
}
