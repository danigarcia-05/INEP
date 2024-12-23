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

void PassarelaVisualitzaPel::insereix()
{
    ConnexioDB& con = ConnexioDB::getInstance();
    string query = "INSERT INTO visualitzacio_pelicula (sobrenom_usuari, titol_pelicula, data, num_visualitzacions) VALUES('" +
        _sobrenom + "', '" + _titolPelicula + "', '" + _data + "', '" + to_string(_numVisualitzacions) + "')";
    con.executarSQL(query);
}

void PassarelaVisualitzaPel::modifica()
{
    _numVisualitzacions += 1;
    _data = utils::dataActual();
    ConnexioDB& con = ConnexioDB::getInstance();

    // Establim la sentència SQL.
    string query = "UPDATE visualitzacio_pelicula SET data = '" +
         _data + "', num_visualitzacions'" + "', num_visualitzacions'" + to_string(_numVisualitzacions) + "', '" + "WHERE sobrenom_usuari = '" + _sobrenom + "' AND titol_pelicula = '" + _titolPelicula + "';";

    // Executem la modificació d' usuari a la base de dades.
    con.executarSQL(query);
}

void PassarelaVisualitzaPel::esborra()
{
    ConnexioDB& con = ConnexioDB::getInstance();

    // Establim la sentència SQL.
    string query = "DELETE FROM visualitzacio_pelicula WHERE sobrenom_usuari = '" + _sobrenom + "'";

    // Executem la modificació d' usuari a la base de dades.
    con.executarSQL(query);
}
