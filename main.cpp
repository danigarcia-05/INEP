#include "capaDePresentacio.h"
using namespace std;
#include <locale>

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

void gestioUsuaris() {
    int op;
    wcout << "------------------" << endl;
    wcout << " Gestionar usuari" << endl;
    wcout << "------------------" << endl;
    wcout << "1. Consulta usuari" << endl;
    wcout << "2. Modifica usuari" << endl;
    wcout << "3. Modifica contrasenya" << endl;
    wcout << "4. Esborra usuari" << endl;
    wcout << "5. Tornar" << endl;
    wcout << "Escriu opció: ";
    cin >> op;

    switch (op) {
        case 1: presentacio.consultaUsuari();break;
        case 2: presentacio.modificaUsuari();break;
        case 3: presentacio.esborraUsuari();break;
    }
}

void gestioContinguts() {
    int op;
    wcout << "------------------" << endl;
    wcout << " Visualitzar" << endl;
    wcout << "------------------" << endl;
    wcout << "1. Visualitzar pel·lícula" << endl;
    wcout << "2. Visualitzar capítol" << endl;
    wcout << "3. Consultar visualitzacions" << endl;
    wcout << "4. Tornar" << endl;
    wcout << "Escriu opció: ";
    cin >> op;


    switch (op) {
        case 1: presentacio.gestioPelicules();break;
        case 2: presentacio.gestioSeries();break;
    }
}

void consultes() {
    int op;
    wcout << "------------------" << endl;
    wcout << " Consultes" << endl;
    wcout << "------------------" << endl;
    wcout << "1. Properes estrenes" << endl;
    wcout << "2. Últimes novetats" << endl;
    wcout << "3. Pel·lícules més vistes" << endl;
    wcout << "4. Tornar" << endl;
    wcout << "Escriu opció: ";
    cin >> op;

    switch (op) {
        case 1: presentacio.consultesEdat();break;
        case 2: presentacio.ultimesNovetats();break;
        case 3: presentacio.proximesEstrenes();break;
    }
}

int main() {
    int op;
    bool acaba = false;
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    while (not acaba) {
        cout << "1. Gestió usuaris" << endl;
        cout << "2. Gestió continguts" << endl;
        cout << "3. Consultes" << endl;
        cout << "4. Sortir" << endl;
        cin >> op;
        if (op == 1) gestioUsuaris();
        else if (op == 2) gestioContinguts();
        else if (op == 3) consultes();
        else if (op == 4) acaba = true;
    }
}



    int op;
    bool acaba=false;
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    while (not acaba) {
        wcout << "*********************" << endl;
        wcout << " Menu Principal" << endl;
        wcout << "*********************" << endl;
        wcout << "1. Iniciar sessió" << endl;
        wcout << "2. Registrar usuari" << endl;
        wcout << "3. Consultes" << endl;
        wcout << "4. Sortir" << endl;
        wcout << "Escriu opcio: ";
    
        cin >> op;
        switch (op) {
            case 1: presentacio.gestioUsuaris();break;
            case 2: presentacio.gestioContinguts();break;
            case 3: presentacio.consultes();break;
            case 4: acaba=true; 
        }
    }    
}



    wcout << "*********************" << endl;
    wcout << " Menu Principal" << endl;
    wcout << "*********************" << endl;
    wcout << "1. Gestió usuaris" << endl;
    wcout << "2. Visualitzar" << endl;
    wcout << "3. Consultes" << endl;
    wcout << "4. Tancar sessió" << endl;
    wcout << "5. Sortir" << endl;
    wcout << "Escriu opcio: ";