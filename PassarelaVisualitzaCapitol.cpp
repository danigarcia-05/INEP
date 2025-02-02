#include "PassarelaVisualitzaCapitol.h"


PassarelaVisualitzaCapitol::PassarelaVisualitzaCapitol()
    : _sobrenom(""), _titolSerie(""), _numVisualitzacions(0), _numTemporada(0), _numCapitol(0), _data("") {}


PassarelaVisualitzaCapitol::PassarelaVisualitzaCapitol(string sobrenomU, string titolSerieU, int numVisualitzacionsU, int numTemporadaU, int numCapitolU, string dataU)
    : _sobrenom(sobrenomU), _titolSerie(titolSerieU), _numVisualitzacions(numVisualitzacionsU), _numTemporada(numTemporadaU), _numCapitol(numCapitolU), _data(dataU) {}


//GETTERS
string PassarelaVisualitzaCapitol::obteSobrenom() const{
    return _sobrenom;
}
string PassarelaVisualitzaCapitol::obteTitolSerie() const{
    return _titolSerie;
}
int PassarelaVisualitzaCapitol::obteNumVisualitzacions() const{
    return _numVisualitzacions;
}
int PassarelaVisualitzaCapitol::obteNumTemporada() const{
    return _numTemporada;
}
int PassarelaVisualitzaCapitol::obteNumCapitol() const{
    return _numCapitol;
}
string PassarelaVisualitzaCapitol::obteData() const{
    return _data;
}


//SETTERS
void PassarelaVisualitzaCapitol::setSobrenom(string sobrenom){
    _sobrenom = sobrenom;
}
void PassarelaVisualitzaCapitol::setTitolSerie(string titolS){
    _titolSerie = titolS;
}
void PassarelaVisualitzaCapitol::setNumVisualitzacions(int nVis){
    _numVisualitzacions = nVis;
}
void PassarelaVisualitzaCapitol::setNumTemporada(int temp){
    _numTemporada = temp;
}
void PassarelaVisualitzaCapitol::setNumCapitol(int cap){
    _numCapitol = cap;
}
void PassarelaVisualitzaCapitol::setData(string data){
    _data = data;
}


void PassarelaVisualitzaCapitol::insereix()
{
    ConnexioDB& con = ConnexioDB::getInstance();
    string query = "INSERT INTO visualitzacio_capitol (sobrenom_usuari, titol_serie, num_temporada, num_capitol, data, num_visualitzacions) VALUES('" +
        _sobrenom + "', '" + _titolSerie + "', '" + to_string(_numTemporada) + "', '" + to_string(_numCapitol) +"', '" + _data + "', '" + to_string(_numVisualitzacions) + "')";
    con.executarSQL(query);
}

void PassarelaVisualitzaCapitol::modifica()
{
    ConnexioDB& con = ConnexioDB::getInstance();

    // Establim la sent�ncia SQL.
    string query = "UPDATE visualitzacio_capitol SET data = '" + _data +
        "', num_visualitzacions = " + to_string(_numVisualitzacions) +
        " WHERE sobrenom_usuari = '" + _sobrenom +
        "' AND titol_serie = '" + _titolSerie +
        "' AND num_temporada = " + to_string(_numTemporada) +
        " AND num_capitol = " + to_string(_numCapitol) + ";";

    // Executem la modificaci� d'usuari a la base de dades.
    con.executarSQL(query);
}

void PassarelaVisualitzaCapitol::esborra()
{
    ConnexioDB& con = ConnexioDB::getInstance();

    // Establim la sent�ncia SQL.
    string query = "DELETE FROM visualitzacio_pelicula WHERE sobrenom_usuari = '" + _sobrenom + "' AND titol_serie = '" + _titolSerie + "' AND num_temporada = '" + to_string(_numTemporada) + "' AND num_capitol = '" + to_string(_numCapitol) + "';";

    // Executem la modificaci� d' usuari a la base de dades.
    con.executarSQL(query);
}

PassarelaVisualitzaCapitol::~PassarelaVisualitzaCapitol() {}
