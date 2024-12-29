#include "PassarelaContingut.h"


    PassarelaContingut::PassarelaContingut(){

    }

    PassarelaContingut::PassarelaContingut(string titol, string descripcio, string qualificacio, string tipus, string subscripcio){
        _titol = titol;
        _descripcio = descripcio;
        _qualificacio = qualificacio;
        _tipus = tipus;
        _subscripcio = subscripcio;
    }

    //GETTERS
    string PassarelaContingut::obteTitol() const{
        return _titol;
    }
    string PassarelaContingut::obteDescripcio() const{
        return _descripcio;
    }
    string PassarelaContingut::obteQualificacio() const{
        return _qualificacio;
    }
    string PassarelaContingut::obteTipus() const{
        return _tipus;
    }
    string PassarelaContingut::obteSubscripcio() const{
        return _subscripcio;
    }

    PassarelaContingut& PassarelaContingut::operator=(const PassarelaContingut& obj){
        if (this != &obj) {  // Comprobación de autorasignación
            _titol = obj._titol;
            _descripcio = obj._descripcio;
            _qualificacio = obj._qualificacio;
            _tipus = obj._tipus;
            _subscripcio = obj._subscripcio;
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
    void PassarelaContingut::setSubscripcio(string subscripcio){
        _subscripcio = subscripcio;
    }

    void PassarelaContingut::insereix()
    {
        ConnexioDB &con = ConnexioDB::getInstance();
        string query = "INSERT INTO contingut (titol, descripcio, qualificacio, tipus, modalitat) VALUES('" +
            _titol + "', '" + _descripcio + "', '" + _qualificacio + "','" + _tipus + "','" + _subscripcio + "')";
        con.executarSQL(query);
    }

    void PassarelaContingut::modifica()
    {
        ConnexioDB& con = ConnexioDB::getInstance();

        // Establim la sentència SQL.
        string query = "UPDATE contingut SET tipus = '" + _tipus + "', descripcio = '" + _descripcio + "', qualificacio = '" + _qualificacio + "', modalitat = '" + _subscripcio + "' WHERE titol = '" + _titol + "';";

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

