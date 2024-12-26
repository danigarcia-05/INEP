#include "CercadoraPelicula.h"

CercadoraPelicula::CercadoraPelicula() {
}

PassarelaPelicula CercadoraPelicula::cercaPelicula(string titolP) {
	ConnexioDB& connexio = ConnexioDB::getInstance();
    PassarelaPelicula resultat;

	// Establim la sentència SQL.
	string sql = "SELECT * FROM pelicula WHERE titol ='" + titolP + "'";
	sql::ResultSet* res = connexio.consultaSQL(sql);

	// Mirem si existeix un usuari amb el sobrenom.ac
	if (res->next()) {
        resultat.setTitol(res->getString("titol"));
        resultat.setDataEstrena(res->getString("data_estrena"));
        resultat.setDuracio(res->getInt("duracio"));
	}
    else {
        cout << "Error" << endl;
    }
    return resultat;
}

vector<PassarelaPelicula> CercadoraPelicula::cercaPeliculesRelacionades(string titolP) {

    ConnexioDB& con = ConnexioDB::getInstance();
    vector<PassarelaPelicula> cjPelicules;

    string comanda = "SELECT * FROM relacionat WHERE titol_x = '" + titolP + "'";
    sql::ResultSet* res = con.consultaSQL(comanda);

    // Mirem si existeix un usuari amb el sobrenom.
    while (res->next()) {
        PassarelaPelicula pelicula;
        pelicula.setTitol(res->getString("titol"));
        pelicula.setDataEstrena(res->getString("data_estrena"));
        pelicula.setDuracio(res->getInt("duracio"));
        cjPelicules.push_back(pelicula);
    }
    return cjPelicules;
}
