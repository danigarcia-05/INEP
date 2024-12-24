#include "CercadoraPelicula.h"

CercadoraPelicula::CercadoraPelicula() {
}

PassarelaPelicula cercaPelicula(string titolP) {
	ConnexioDB& connexio = ConnexioDB::getInstance();
    PassarelaPelicula resultat;

	// Establim la sentència SQL.
	string sql = "SELECT * FROM pelicula WHERE titol='" + titolP + "'";
	sql::ResultSet* res = connexio.consultaSQL(sql);

	// Mirem si existeix un usuari amb el sobrenom.
	if (res->next()) {
        resultat.setTitol(res->getString("titol"));
        resultat.setDescripcio(res->getString("descripcio"));
        resultat.setQualificacio(res->getString("qualificacio"));
        resultat.setTipus(res->getString("tipus"));
        resultat.setDataEstrena(res->getString("data_estrena"));
        resultat.setDuracio(res->getString("duracio"));
	}
    else {
        //EXCEPCIÓN
    }
    return resultat;
}

vector<PassarelaPelicula> CercadoraPelicula::cercaPeliculesRelacionades(string titolP) {

    ConnexioDB& con = ConnexioDB::getInstance();
    vector<PassarelaPelicula> cjPelicules;

    string comanda = "SELECT * FROM relacionat WHERE titol_x='" + titolP + "'";
    sql::ResultSet* res = con.consultaSQL(comanda);

    // Mirem si existeix un usuari amb el sobrenom.
    while (res->next()) {
        PassarelaPelicula pelicula;
        pelicula.setTitol(res->getString("titol"));
        pelicula.setDescripcio(res->getString("descripcio"));
        pelicula.setQualificacio(res->getString("qualificacio"));
        pelicula.setTipus(res->getString("tipus"));
        pelicula.setDataEstrena(res->getString("data_estrena"));
        pelicula.setDuracio(res->getString("duracio"));
        cjPelicules.push_back(pelicula);
    }
    return cjPelicules;
}
