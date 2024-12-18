#include "CapaDePresentacio.h"


CapaDePresentacio* CapaDePresentacio::getInstance(){
    if (ins == nullptr) {
        ins = new CapaDePresentacio();
    }
    return ins;
}

bool CapaDePresentacio::getInstanceUsuari(){
    bool res;
    if (insUsuari == nullptr) res = false;
    else res = true;
    return res;
}

CapaDePresentacio* CapaDePresentacio::ins = nullptr;
PassarelaUsuari* PassarelaUsuari::insUsuari = nullptr;

void CapaDePresentacio::processarIniciarSessio(){
    string sobrenomU, contrasenyaU;
    cout << "** Inici sessio **" << endl;
    cout << "Sobrenom: ";
    cin >> sobrenomU;
    cout << "Contrasenya: ";
    cin >> contrasenyaU;
    CapaDeDomini& domini = CapaDeDomini::getInstance();
    try {
        domini.iniciarSessio(sobrenomU, contrasenyaU);
        cout << "Sessio iniciada correctament!" << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

void CapaDePresentacio::processarRegistreUsuari(){
    string sobrenomU, nomU, correuU;
    cout << "** Registra usuari **" << endl;
    cout << "Sobrenom: ";
    cin >> sobrenomU;
    cout << "Nom: ";
    cin >> nomU;
    cout << "Correu electrònic: ";
    cin >> correuU;
    CapaDeDomini& domini = CapaDeDomini::getInstance();
    try {
        domini.registrarUsuari(sobrenomU, nomU, correuU)
        cout << "Usuari registrat correctament!" << endl;
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}


void CapaDePresentacio::processarConsultaUsuari(){
    cout << "Nom usuari:";
    cin >> nomU;
    try {
        DTOUsuari usu = cercaUsuari(nomU);
        cout << "Informació usuari: " << usu.obteNom();
        cout << ::endl;
        cout << "Nom: " << usu.obteNom() << ::endl;
        cout << "Correu: " << usu.obteCorreu() << ::endl;
    }
    catch (const exception& e) {
        out << "Error: " << e.what() << endl;
    }
}






















/*

void CapaDePresentacio::registrarUsuari() {
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

void CapaDePresentacio::consultarUsuari() {
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

void CapaDePresentacio::modificarUsuari() {
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

void CapaDePresentacio::borrarUsuari() {
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

void CapaDePresentacio::gestioPelicules() {
    cout << "gestioPelicules" << endl << endl;
}

void CapaDePresentacio::gestioSeries() {
    cout << "gestioSeries" << endl << endl;
}

void CapaDePresentacio::consultesEdat() {
    cout << "consultesEdat" << endl << endl;
}

void CapaDePresentacio::ultimesNovetats() {
    cout << "ultimesNovetats" << endl << endl;
}

void CapaDePresentacio::proximesEstrenes() {
    cout << "proximesEstrenes" << endl << endl;
}

*/