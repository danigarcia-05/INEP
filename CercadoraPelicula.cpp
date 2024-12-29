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
        resultat.setVisualitzacionsGlobals(res->getInt("visualitzacions_globals"));
        resultat.setModalitat(res->getString("modalitat"));
	}
    else {
        throw runtime_error("PeliculaNoExisteix");
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
        pelicula.setVisualitzacionsGlobals(res->getInt("visualitzacions_globals"));
        pelicula.setModalitat(res->getString("modalitat"));
        cjPelicules.push_back(pelicula);
    }
    return cjPelicules;
}

vector<PassarelaPelicula> CercadoraPelicula::cercaPeliculesMesVistes() {

    ConnexioDB& con = ConnexioDB::getInstance();
    vector<PassarelaPelicula> cjPelicules;

   
    string comanda = "SELECT * FROM pelicula ORDER BY visualitzacions_globals DESC LIMIT 5";
    sql::ResultSet* res = con.consultaSQL(comanda);

    while (res->next()) {
        PassarelaPelicula pelicula;
        pelicula.setTitol(res->getString("titol"));
        pelicula.setDataEstrena(res->getString("data_estrena"));
        pelicula.setDuracio(res->getInt("duracio"));
        pelicula.setVisualitzacionsGlobals(res->getInt("visualitzacions_globals"));
        pelicula.setModalitat(res->getString("modalitat"));
        cjPelicules.push_back(pelicula);
    }

    return cjPelicules;
}

vector<PassarelaPelicula> CercadoraPelicula::cercaNovesEstrenes(string mod) {
    ConnexioDB& con = ConnexioDB::getInstance();
  
    string comanda;
    if (mod == "Infantil") {
        comanda = "SELECT * FROM pelicula WHERE data_estrena <= NOW() AND modalitat = '" + mod + "' " +
            "ORDER BY data_estrena DESC LIMIT 5;";
    }
    else {
        comanda = "SELECT * FROM pelicula WHERE data_estrena <= NOW() ORDER BY data_estrena DESC LIMIT 5;";
    }

    sql::ResultSet* res = con.consultaSQL(comanda);

    vector<PassarelaPelicula> pelicules;
    while (res->next()) {  
        PassarelaPelicula pelicula;
        pelicula.setTitol(res->getString("titol"));
        pelicula.setDataEstrena(res->getString("data_estrena"));
        pelicula.setDuracio(res->getInt("duracio"));
        pelicula.setVisualitzacionsGlobals(res->getInt("visualitzacions_globals"));
        pelicula.setModalitat(res->getString("modalitat"));
        pelicules.push_back(pelicula);
    }

    return pelicules;
}

vector<PassarelaPelicula> CercadoraPelicula::cercaProperesEstrenes(string mod) {
    ConnexioDB& con = ConnexioDB::getInstance();

    string comanda;
    if (mod == "Infantil") {
        comanda = "SELECT * FROM pelicula WHERE data_estrena > NOW() AND modalitat = '" + mod + "' " +
            "ORDER BY data_estrena ASC LIMIT 5;";
    }
    else {
        comanda = "SELECT * FROM pelicula WHERE data_estrena > NOW() ORDER BY data_estrena ASC LIMIT 5;";
    }
    sql::ResultSet* res = con.consultaSQL(comanda);

    vector<PassarelaPelicula> pelicules;
    while (res->next()) {  // Asegurarse de que se encontró un resultado
        PassarelaPelicula pelicula;
        pelicula.setTitol(res->getString("titol"));
        pelicula.setDataEstrena(res->getString("data_estrena"));
        pelicula.setDuracio(res->getInt("duracio"));
        pelicula.setVisualitzacionsGlobals(res->getInt("visualitzacions_globals"));
        pelicula.setModalitat(res->getString("modalitat"));
        pelicules.push_back(pelicula);
    }
    return pelicules;
}




