#include "PassarelaPelicula.h"

/*
*****************************************************
                   CONSTRUCTORS
*****************************************************
*/
PassarelaPelicula::PassarelaPelicula() {

}

PassarelaPelicula::PassarelaPelicula(string titol, string descripcio, string qualificacio, string dataEstrena, string tipus, int duracio)
{
    _titol = titol;
    _descripcio = descripcio;
    _qualificacio = qualificacio;
    _dataEstrena = dataEstrena;
    _tipus = tipus;
    _duracio = duracio;
}

/*
*****************************************************
                    CONSULTORS
*****************************************************
*/
string PassarelaPelicula::obteTitol() {
    return _titol;
}
string PassarelaPelicula::obteDescripcio() {
    return _descripcio;
}
string PassarelaPelicula::obteQualificacio() {
    return _qualificacio;
}
string PassarelaPelicula::obteDataEstrena() {
    return _dataEstrena;
}
string PassarelaPelicula::obteTipus() {
    return _tipus;
}
int PassarelaPelicula::obteDuracio() {
    return _duracio;
}


PassarelaPelicula& PassarelaPelicula::operator=(const PassarelaPelicula& obj) {
    if (this != &obj) {  // Comprobación de autorasignación
        _titol = obj._titol;
        _descripcio = obj._descripcio;
        _qualificacio = obj._qualificacio;
        _dataEstrena = obj._dataEstrena;
        _tipus = obj._tipus;  // Asumimos que Data tiene su propio operador=
        _duracio = obj._duracio;
    }
    return *this;  // Devolver la referencia al objeto actual
}

/*
*****************************************************
                   SETTERS
*****************************************************
*/
void PassarelaPelicula::setTitol(string titol) {
     _titol = titol;
}
void PassarelaPelicula::setDescripcio(string descripcio) {
    _descripcio = descripcio;
}
void PassarelaPelicula::setQualificacio(string qualificacio) {
    _qualificacio = qualificacio;
}
void PassarelaPelicula::setDataEstrena(string dataEstrena) {
     _dataEstrena = dataEstrena;
}
void PassarelaPelicula::setTipus(string tipus) {
      _tipus = tipus;
}
void PassarelaPelicula::setDuracio(int duracio) {
    _duracio = duracio;
}

/*
*****************************************************
                   MODIFICADORS
*****************************************************
*/
void PassarelaPelicula::insereix()
{
    ConnexioDB &con = ConnexioDB::getInstance();
    string query = "INSERT INTO pelicula (titol, data_estrena, duracio, descripcio, qualificacio, tipus) VALUES('" +
        _titol + "', '" + _dataEstrena + "', '" + to_string(_duracio) + "','" + _descripcio + "', '" + _qualificacio + "', '" + _tipus + "')";
    con.executarSQL(query);
}

void PassarelaPelicula::modifica()
{
    ConnexioDB& con = ConnexioDB::getInstance();

    // Establim la sentència SQL.
    string query = "UPDATE pelicula SET tipus = '" + _tipus + "', data_estrena = '" + _dataEstrena + "', duracio = '" + to_string(_duracio) + "', descripcio = '" + _descripcio + "', qualificacio = '" + _qualificacio + "' WHERE titol = '" + _titol + "';";

    // Executem la modificació d' usuari a la base de dades.
    con.executarSQL(query);
}

void PassarelaPelicula::esborra()
{
	ConnexioDB &con = ConnexioDB::getInstance();

	// Establim la sentència SQL.
	string query = "DELETE FROM pelicula WHERE titol = '" + _titol + "'";

	// Executem la modificació d' usuari a la base de dades.
	con.executarSQL(query);
}
