#include "CercadoraVisualitzaPel.h"

CercadoraVisualitzaPel::CercadoraVisualitzaPel(){}

vector<PassarelaVisualitzaPel> CercadoraVisualitzaPel::cercaVisualitzaPel(string sobrenomU){
	
	ConnexioDB& con = ConnexioDB::getInstance();
        vector<PassarelaVisualitzaPel> cjVisualitzaPel;

		string comanda = "SELECT * FROM visualitzacio_pelicula WHERE sobrenom_usuari='" + sobrenomU + "'";
        sql::ResultSet* res = con.consultaSQL(comanda);

		// Mirem si existeix un usuari amb el sobrenom.
        while (res->next()) {
            PassarelaVisualitzaPel pvp;
            pvp.setSobrenom(res->getString("sobrenom_usuari"));
            pvp.setTitolPelicula(res->getString("titol_pelicula"));
            pvp.setNumVisualitzacions(res->getInt("num_visualitzacions"));
            pvp.setData(res->getString("data"));
            cjVisualitzaPel.push_back(pvp);
        }
	return cjVisualitzaPel;
}