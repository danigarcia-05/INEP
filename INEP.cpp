using namespace std;
#include <iostream>
#include <string>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>

//Hola

class ConnexioBD {
private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    
public:
    ConnexioBD() : driver(nullptr), con(nullptr), stmt(nullptr) {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("ubiwan.epsevg.upc.edu:3306", "inep13", "agheeGak0Ofe4m");
        con->setSchema("inep13");
        stmt = con->createStatement();
    }

    ~ConnexioBD() {
        con->close();
    }

    sql::ResultSet* consultaSQL(const string& sql) {
        if (stmt != nullptr) return stmt->executeQuery(sql);
    }

    void executarSQL(const string& sql) {
        if (stmt != nullptr) stmt->execute(sql);
    }
};

struct Usuari {
    string sobrenom;
    string nom;
    string correu;
};

void registrarUsuari() {
    try {
        ConnexioBD db;
        Usuari n;
        cout << "Registra el teu usuari:" << endl;
        cin >> n.sobrenom >> n.nom >> n.correu;
        string sql = "INSERT INTO Usuari (sobrenom, nom, correu_electronic) VALUES ('" + n.sobrenom + "', '" + n.nom + "', '" + n.correu + "')";
        db.executarSQL(sql);
        cout << "L'usuari amb sobrenom " << n.sobrenom << " s'ha registrat correctament." << endl;
    }
    catch (sql::SQLException& e) {
        cerr << "Error en registrar Usuari " << e.what() << endl;
    }
}

void consultarUsuari() {
    try {
        ConnexioBD db;
        Usuari n;
        cout << "Entra el sobrenom de l'usuari a consultar:" << endl;
        cin >> n.sobrenom;
        string sql = "SELECT * FROM Usuari WHERE sobrenom='" + n.sobrenom + "'";
        sql::ResultSet* res = db.consultaSQL(sql);
        if (res->next()) {
            cout << "Sobrenom: " << res->getString("sobrenom") << endl;
            cout << "Nom: " << res->getString("nom") << endl;
            cout << "Correu: " << res->getString("correu_electronic") << endl;
        }
        else cout << "ERROR: No s' ha trobat cap usuari amb el sobrenom " << n.sobrenom << '.' << endl;
    }
    catch (sql::SQLException& e) {
        cerr << "Error en consultar Usuari " << e.what() << endl;
    }
}

void modificarUsuari() {
    try {
        ConnexioBD db;
        Usuari n;
        cout << "Entra el sobrenom de l'usuari a modificar:" << endl;
        cin >> n.sobrenom;
        cout << "Entra el nou nom i correu:" << endl;
        cin >> n.nom >> n.correu;
        string sql = "UPDATE Usuari SET nom = '" + n.nom + "', correu_electronic = '" + n.correu + "' WHERE sobrenom = '" + n.sobrenom + "'";
        db.executarSQL(sql);
        cout << "Usuari modificat correctament." << endl;
    }
    catch (sql::SQLException& e) {
        cerr << "Error en modificar Usuari " << e.what() << endl;
    }
}

void borrarUsuari() {
    try {
        ConnexioBD db;
        Usuari n;
        cout << "Entra el sobrenom de l'usuari a esborrar:" << endl;
        cin >> n.sobrenom;
        string sql = "DELETE FROM Usuari WHERE sobrenom = '" + n.sobrenom + "'";
        db.executarSQL(sql);
        cout << "Usuari eliminat correctament." << endl;
    }
    catch (sql::SQLException& e) {
        cerr << "Error en esborrar Usuari " << e.what() << endl;
    }
}

void gestioPelicules() {
    cout << "gestioPelicules" << endl << endl;
}

void gestioSeries() {
    cout << "gestioSeries" << endl << endl;
}

void consultesEdat() {
    cout << "consultesEdat" << endl << endl;
}

void ultimesNovetats() {
    cout << "ultimesNovetats" << endl << endl;
}

void proximesEstrenes() {
    cout << "proximesEstrenes" << endl << endl;
}

void OPCIO1() {
    cout << "1. Registre usuari" << endl;
    cout << "2. Consulta usuari " << endl;
    cout << "3. Modifica usuari" << endl;
    cout << "4. Borra usuari" << endl;
    cout << "5. Tornar" << endl;
    int opcio2;
    cin >> opcio2;
    if (opcio2 == 1) registrarUsuari();
    else if (opcio2 == 2) consultarUsuari();
    else if (opcio2 == 3) modificarUsuari();
    else if (opcio2 == 4) borrarUsuari();
}

void OPCIO2() {
    cout << "1. Gestió pel·lícules" << endl;
    cout << "2. Gestió sèries" << endl;
    cout << "3. Tornar" << endl;
    int opcio2;
    cin >> opcio2;
    if (opcio2 == 1) gestioPelicules();
    else if (opcio2 == 2) gestioSeries();
}

void OPCIO3() {
    cout << "1. Consulta per qualificació d'edat" << endl;
    cout << "2. Últimes novetats" << endl;
    cout << "3. Pròximes estrenes" << endl;
    cout << "4. Tornar" << endl;
    int opcio2;
    cin >> opcio2;
    if (opcio2 == 1) consultesEdat();
    else if (opcio2 == 2) ultimesNovetats();
    else if (opcio2 == 3) proximesEstrenes();
}

int main() {
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
