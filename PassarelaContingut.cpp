#include "PassarelaContingut.h"


    PassarelaContingut::PassarelaContingut(){

    }

    PassarelaContingut::PassarelaContingut(string titol, string descripcio, string qualificacio, string tipus){
        _titol = titol;
        _descripcio = descripcio;
        _qualificacio = qualificacio;
        _tipus = tipus;
    }

    //GETTERS
    string PassarelaContingut::obteTitol(){
        return _titol;
    }
    string PassarelaContingut::obteDescripcio(){
        return _descripcio;
    }
    string PassarelaContingut::obteQualificacio(){
        return _qualificacio;
    }
    string PassarelaContingut::obteTipus(){
        return _tipus;
    }

    PassarelaContingut& PassarelaContingut::operator=(const PassarelaContingut& obj){
        if (this != &obj) {  // Comprobación de autorasignación
            _titol = obj._titol;
            _descripcio = obj._descripcio;
            _qualificacio = obj._qualificacio;
            _tipus = obj._tipus;
        }
        return *this;  // Devolver la referencia al objeto actual
    }

    //SETTERS
    void PassarelaContingut::setTitol(string titol){
        _titol = titol;
    }
    void PassarelaContingut::setDescripcio(string descripcio){
        _descripcio = descripcio;
    }
    void PassarelaContingut::setQualificacio(string qualificacio){
        _qualificacio = qualificacio;
    }
    void PassarelaContingut::setTipus(string tipus){
        _tipus = tipus;
    }

    void PassarelaContingut::insereix()
    {
        ConnexioDB &con = ConnexioDB::getInstance();
        string query = "INSERT INTO contingut (titol, descripcio, qualificacio, tipus) VALUES('" +
            _titol + "', '" + _descripcio + "', '" + _qualificacio + "','" + _tipus + "')";
        con.executarSQL(query);
    }

    void PassarelaContingut::modifica()
    {
        ConnexioDB& con = ConnexioDB::getInstance();

        // Establim la sentència SQL.
        string query = "UPDATE contingut SET tipus = '" + _tipus + "', descripcio = '" + _descripcio + "', qualificacio = '" + _qualificacio + "' WHERE titol = '" + _titol + "';";

        // Executem la modificació d' usuari a la base de dades.
        con.executarSQL(query);
    }

    void PassarelaContingut::esborra()
    {
        ConnexioDB &con = ConnexioDB::getInstance();

        // Establim la sentència SQL.
        string query = "DELETE FROM contingut WHERE titol = '" + _titol + "'";

        // Executem la modificació d' usuari a la base de dades.
        con.executarSQL(query);
    }

