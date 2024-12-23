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


void PassarelaVisualitzaSerie::insereix()
{
    ConnexioDB& con = ConnexioDB::getInstance();
    string query = "INSERT INTO visualitzacio_capitol (sobrenom_usuari, titol_serie, num_temporada, num_capitol, data, num_visualitzacions) VALUES('" +
        _sobrenom + "', '" + _titolSerie + "', '" + to_string(_numTemporada) + "', '" + to_string(_numCapitol) +"', '" + _data + "', '" + to_string(_numVisualitzacions) + "')";
    con.executarSQL(query);
}

void PassarelaVisualitzaSerie::modifica()
{
    _numVisualitzacions += 1;
    _data = utils::dataActual();
    ConnexioDB& con = ConnexioDB::getInstance();

    // Establim la sentència SQL.
    string query = "UPDATE visualitzacio_capitol SET data = '" +
        _data + "', num_visualitzacions'" + to_string(_numVisualitzacions) + "', '" + "WHERE sobrenom_usuari = '" + _sobrenom + "' AND titol_serie = '" + _titolSerie + "' AND num_temporada = '" + to_string(_numTemporada) +"' AND num_capitol = '" + to_string(_numCapitol) +"';";

    // Executem la modificació d' usuari a la base de dades.
    con.executarSQL(query);
}

void PassarelaVisualitzaSerie::esborra()
{
    ConnexioDB& con = ConnexioDB::getInstance();

    // Establim la sentència SQL.
    string query = "DELETE FROM visualitzacio_pelicula WHERE sobrenom_usuari = '" + _sobrenom + "' AND titol_serie = '" + _titolSerie + "' AND num_temporada = '" + to_string(_numTemporada) + "' AND num_capitol = '" + to_string(_numCapitol) + "';";

    // Executem la modificació d' usuari a la base de dades.
    con.executarSQL(query);
}


