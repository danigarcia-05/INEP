using namespace std;
#include <iostream>
#include <string>
#include <sstream>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <mysql_connection.h>
#include <mysql_driver.h>


struct usuari {
	string sobrenom;
	string nom;
	string correu;
};

void registrarUsuari() {
	sql::mysql::MySQL_Driver* driver = NULL;
	sql::Connection* con = NULL;
	sql::Statement* stmt = NULL;
	try {
		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect("ubiwan.epsevg.upc.edu:3306", "inep13", "agheeGak0Ofe4m");
		con->setSchema("inep13");
		stmt = con->createStatement();
		// Sentència SQL per obtenir totes les files de la taula usuari.
		// S’ha de posar el nom de la taula tal i com el teniu a la base
		// de dades respectant minúscules i majúscules
		usuari n;
		cout << "Registra el teu usuari:" << endl;
		cin >> n.sobrenom >> n.nom >> n.correu;
		string sql = "INSERT INTO Usuari (sobrenom, nom, correu_electronic) VALUES('" + n.sobrenom + "', '" + n.nom + "', '" + n.correu + "')";
		stmt->execute(sql);
		con->close();
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
		// si hi ha un error es tanca la connexió (si esta oberta)
		if (con != NULL) con->close();
	}
}

void consultarUsuari() {
	sql::mysql::MySQL_Driver* driver = NULL;
	sql::Connection* con = NULL;
	sql::Statement* stmt = NULL;
	try {
		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect("ubiwan.epsevg.upc.edu:3306", "inep13", "agheeGak0Ofe4m");
		con->setSchema("inep13");
		stmt = con->createStatement();
		// Sentència SQL per obtenir totes les files de la taula usuari.
		// S’ha de posar el nom de la taula tal i com el teniu a la base
		// de dades respectant minúscules i majúscules
		usuari n;
		cout << "Entra un sobrenom:" << endl;
		cin >> n.sobrenom;
		string sql = "SELECT * FROM Usuari WHERE sobrenom='" + n.sobrenom + "'";
		sql::ResultSet* res = stmt->executeQuery(sql);
		// Bucle per recórrer les dades retornades mostrant les dades de cada fila
		while (res->next()) {
			// a la funció getString es fa servir el nom de la columna de la taula
			cout << "Sobrenom: " << res->getString("sobrenom") << endl;
			cout << "Nom: " << res->getString("nom") << endl;
			cout << "Correu: " << res->getString("correu_electronic") << endl;
		}
		con->close();
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
		// si hi ha un error es tanca la connexió (si esta oberta)
		if (con != NULL) con->close();
	}
}

void modificarUsuari() {
	sql::mysql::MySQL_Driver* driver = NULL;
	sql::Connection* con = NULL;
	sql::Statement* stmt = NULL;
	try {
		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect("ubiwan.epsevg.upc.edu:3306", "inep13", "agheeGak0Ofe4m");
		con->setSchema("inep13");
		stmt = con->createStatement();
		// Sentència SQL per obtenir totes les files de la taula usuari.
		// S’ha de posar el nom de la taula tal i com el teniu a la base
		// de dades respectant minúscules i majúscules
		usuari n;
		cout << "Entra un sobrenom:" << endl;
		cin >> n.sobrenom;
		cout << "Entra el nou usuari i correu:" << endl;
		cin >> n.nom >> n.correu;
		string sql = "UPDATE Usuari SET nom = '" + n.nom + "', correu_electronic = '" + n.correu + "' WHERE sobrenom = '" + n.sobrenom + "';";
		stmt->execute(sql);
		con->close();
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
		// si hi ha un error es tanca la connexió (si esta oberta)
		if (con != NULL) con->close();
	}
}

void borrarUsuari() {
	sql::mysql::MySQL_Driver* driver = NULL;
	sql::Connection* con = NULL;
	sql::Statement* stmt = NULL;
	try {
		driver = sql::mysql::get_mysql_driver_instance();
		con = driver->connect("ubiwan.epsevg.upc.edu:3306", "inep13", "agheeGak0Ofe4m");
		con->setSchema("inep13");
		stmt = con->createStatement();
		// Sentència SQL per obtenir totes les files de la taula usuari.
		// S’ha de posar el nom de la taula tal i com el teniu a la base
		// de dades respectant minúscules i majúscules
		usuari n;
		cout << "Entra el sobrenom de l'usuari a esborrar" << endl;
		cin >> n.sobrenom;
		string sql = "DELETE FROM Usuari WHERE sobrenom = '" + n.sobrenom + "'";

		stmt->execute(sql);
		con->close();
	}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
		// si hi ha un error es tanca la connexió (si esta oberta)
		if (con != NULL) con->close();
	}
}

void gestioPelicules() {
	cout << "Gestió pel·lícules" << endl << endl;
}

void gestioSeries() {
	cout << "Gestió sèries" << endl << endl;
}

void consultesEdat() {
	cout << "Consulta per qualificació d'edat" << endl << endl;
}

void ultimesNovetats() {
	cout << "Últimes novetats" << endl << endl;
}

void proximesEstrenes() {
	cout << "Pròximes estrenes" << endl << endl;
}

void OPCIO1 (){
	cout << "1. Resgistre usuari" << endl;
	cout << "2. Consulta usuari " << endl;
	cout << "3. Modifica usuari" << endl;
	cout << "4. Borrar usuari" << endl;
	cout << "5. Tornar" << endl;
	int opcio2;
	cin >> opcio2;
	if (opcio2 == 1) registrarUsuari();
	if (opcio2 == 2) consultarUsuari();
	if (opcio2 == 3) modificarUsuari();
	if (opcio2 == 4) borrarUsuari();
}

void OPCIO2() {
	cout << "1. Gestió pel·lícules" << endl;
	cout << "2. Gestió sèries" << endl;
	cout << "3. Tornar" << endl;
	int opcio2;
	cin >> opcio2;
	if (opcio2 == 1) gestioPelicules();
	if (opcio2 == 2) gestioSeries();
}

void OPCIO3() {
	cout << "1. Consulta per qualificació d'edat" << endl;
	cout << "2. Últimes novetats" << endl;
	cout << "3. Pròximes estrenes" << endl;
	cout << "4. Tornar" << endl;
	int opcio2;
	cin >> opcio2;
	if (opcio2 == 1) consultesEdat();
	if (opcio2 == 2) ultimesNovetats();
	if (opcio2 == 3) proximesEstrenes();
}

int main () {
	int opcio;
	bool acaba = false;
	while (not acaba) {
		cout << "1. Gestió usuaris" << endl;
		cout << "2. Gestió continguts" << endl;
		cout << "3. Consultes" << endl;
		cout << "4. Sortir" << endl;
		cin >> opcio;
		if (opcio == 1) OPCIO1();
		else if (opcio == 2) OPCIO2();
		else if (opcio == 3) OPCIO3();
		else if (opcio == 4) acaba = true;
	}
}