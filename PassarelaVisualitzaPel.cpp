#include "PassarelaVisualitzaPel.h"


PassarelaVisualitzaPel::PassarelaVisualitzaPel() 
    : _sobrenom(""), _titolPelicula(""), _numVisualitzacions(0) {}


PassarelaVisualitzaPel::PassarelaVisualitzaPel(string sobrenomU, string titolPeliculaU, Data dataU, int numVisualitzacionsU)
    : _sobrenom(sobrenomU), _titolPelicula(titolPeliculaU), _data(dataU), _numVisualitzacions(numVisualitzacionsU) {}


string PassarelaVisualitzaPel::obteSobrenom() const {
    return _sobrenom;
}

void PassarelaVisualitzaPel::setSobrenom(const string& sobrenomU) {
    _sobrenom = sobrenomU;
}


string PassarelaVisualitzaPel::obteTitolPelicula() const {
    return _titolPelicula;
}

void PassarelaVisualitzaPel::setTitolPelicula(const string& titolPeliculaU) {
    _titolPelicula = titolPeliculaU;
}


Data PassarelaVisualitzaPel::obteData() const {
    return _data;
}

void PassarelaVisualitzaPel::setData(const Data& dataU) {
    _data = dataU;
}

// Getter y Setter para _numVisualitzacions
int PassarelaVisualitzaPel::obteNumVisualitzacions() const {
    return _numVisualitzacions;
}

void PassarelaVisualitzaPel::setNumVisualitzacions(int numVisualitzacionsU) {
    _numVisualitzacions = numVisualitzacionsU;
}


void PassarelaVisualitzaPel::insereix() {
    
}

void PassarelaVisualitzaPel::modifica() {
    
}

void PassarelaVisualitzaPel::esborra() {
    
}
