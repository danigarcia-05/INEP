#include "PassarelaPelicula.h"

/*
*****************************************************
                   CONSTRUCTORS
*****************************************************
*/
PassarelaPelicula::PassarelaPelicula() : _titol(""), _dataEstrena(""), _duracio(0) {

}

PassarelaPelicula::PassarelaPelicula(string titol, string dataEstrena, int duracio, int visualitzacionsGlobals)
{
    _titol = titol;
    _dataEstrena = dataEstrena;
    _duracio = duracio;
    _visualitzacionsGlobals = visualitzacionsGlobals;  
}

/*
*****************************************************
                    CONSULTORS
*****************************************************
*/
string PassarelaPelicula::obteTitol() {
    return _titol;
}
string PassarelaPelicula::obteDataEstrena() {
    return _dataEstrena;
}
int PassarelaPelicula::obteDuracio() {
    return _duracio;
}
int PassarelaPelicula::obteVisualitzacionsGlobals() {
    return _visualitzacionsGlobals;
}


PassarelaPelicula& PassarelaPelicula::operator=(const PassarelaPelicula& obj) {
    if (this != &obj) {  // Comprobación de autorasignación
        _titol = obj._titol;
        _dataEstrena = obj._dataEstrena;
        _duracio = obj._duracio;
        _visualitzacionsGlobals = obj._visualitzacionsGlobals;
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
void PassarelaPelicula::setDataEstrena(string dataEstrena) {
     _dataEstrena = dataEstrena;
}
void PassarelaPelicula::setDuracio(int duracio) {
    _duracio = duracio;
}
void PassarelaPelicula::setVisualitzacionsGlobals(int visualitzacionsGlobals) {
    _visualitzacionsGlobals = visualitzacionsGlobals;
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
        _titol + "', '" + _dataEstrena + "', '" + to_string(_duracio) + "', '" + to_string(_visualitzacionsGlobals) + "')";
    con.executarSQL(query);
}

void PassarelaPelicula::modifica()
{
    ConnexioDB& con = ConnexioDB::getInstance();

    // Establim la sentència SQL.
    string query = "UPDATE pelicula SET data_estrena = '" + _dataEstrena + "', duracio = '" + to_string(_duracio) + "', visualitzacions_globals = '" + to_string(_visualitzacionsGlobals) + "' WHERE titol = '" + _titol + "';";

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
