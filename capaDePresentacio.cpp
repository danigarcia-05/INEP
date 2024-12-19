#include "CapaDePresentacio.h"


/*
*****************************************************
                   CONSTRUCTORS
*****************************************************
*/
CapaDePresentacio& CapaDePresentacio::getInstance(){
    if (ins == nullptr) {
        ins = new CapaDePresentacio();
    }
    return *ins;
}

CapaDePresentacio* CapaDePresentacio::ins = nullptr;

/*
*****************************************************
                   DESTRUCTORS
*****************************************************
*/
TxIniciSessio::~TxIniciSessio(){
}

/*
*****************************************************
                   MODIFICADORS
*****************************************************
*/
void CapaDePresentacio::processarIniciarSessio(){
    string sobrenomU, contrasenyaU;
    cout << "** Inici sessio **" << endl;
    cout << "Sobrenom: ";
    cin >> sobrenomU;
    cout << "Contrasenya: ";
    cin >> contrasenyaU;
    TxIniciSessio txIniciSessio(sobrenomU, contrasenyaU);
    try {
        txIniciSessio.executar();
        cout << "Sessio iniciada correctament!" << endl;
    }
    catch (const exception& e) {
        cout << "Error: Hi ha hagut un error amb el sobrenom o la contrasenya"  << endl;
    }
}

void CapaDePresentacio::processarTancaSessio(){
    char tanca
    cout << "** Tancar sessio **" << endl;
    cout << "Vols tancar la sessio (S/N): ";
    cin >> tanca;
    if(tanca == 'S'){
        TxTancaSessio txTancaSessio();
        txTancaSessio.executar();
        cout << "Sessio tancada correctament!" << endl;
    }
    
}

void CapaDePresentacio::processarRegistreUsuari(){
    string nU, sU, cU, ceU, msU;
    Data dnU;
    cout << "** Inici sessio **" << endl;
    cout << "Nom complet: ";
    cin >> nU;
    cout << endl << "Sobrenom: ";
    cin >> sU;
    cout << endl <<  "Contrasenya: ";
    utils::desactivarEco();
    cin >> cU;
    utils::activarEco();
    cout << endl << "Correu Electrònic: ";
    cin >> ceU;
    cout << endl << "Data naixement (DD/MM/AAAA): ";
    cin >> dnU;
    cout << endl << "Modalitats de subscripció disponibles ";
    cout << endl << " > 1. Completa ";
    cout << endl << " > 2. Cinèfil ";
    cout << endl << " > 3. Infantil ";
    cout << endl << "Escull modalitat: ";
    cin >> msU;
    cout << endl;
    
    TxRegistraUsuari txRegistraUsuari(nU, sU, cU, ceU, dnU, msU);
    try {
        txRegistraUsuari.executar();
        cout << "Nou usuari registrat correctament!" << endl;
    }
    catch (const exception& e) {
        string error_msg = e.what();
        if(error_msg == "SobrenomExisteix") cout << "Ja existeix un usuari amb aquest sobrenom"  << endl;
        else if(error_msg == "CorreuExisteix") cout << "Ja existeix un usuari amb aquest correu electrònic"  << endl;
        else if(error_msg == "ModalitatNoExisteix") cout << "Modalitat no existeix"  << endl;
    }
}

//-------------------------------------------------------------------

void CapaDePresentacio::processarConsultaUsuari()
{
	try {
		ConnexioBD connexio;
        cout << "** Consulta usuari **" << endl

res = connexio.consultaSQL(sql);

		// Mirem si existeix un usuari amb el sobrenom.
		if (res->next()) {
		  	cout << "Sobrenom: " << res->getString("sobrenom") << endl;
			cout << "Nom: " << res->getString("nom") << endl;
			cout << "Correu: " << res->getString("correu_electronic") << endl;
			}
	catch (sql::SQLException& e) {
		std::cerr << "SQL Error: " << e.what() << std::endl;
	}
}

void CapaDePresentacio::processarModificaUsuari() {
	try {
		ConnexioBD connexio;

		// Obtener datos del usuario
		string sobrenom, nom, correu;
		cout << "Introdueix el sobrenom: ";
		cin >> sobrenom;
		cout << "Introdueix el nom: ";
		cin.ignore(); 
		getline(cin, nom);
		cout << "Introdueix el correu electrònic: ";
		cin >> correu;

		// Establim la sentència SQL.
		string sql = "UPDATE Usuari SET nom = '" + nom + "', correu_electronic = '" + correu + "' WHERE sobrenom = '" + sobrenom + "'";


		// Executem la modificació d' usuari a la base de dades.
		connexio.executarSQL(sql);
		cout << "Usuari modificat correctament." << endl;
	}
	catch (sql::SQLException& e) {
		cerr << "SQL Error: " << e.what() << endl;
	}
}

//-------------------------------------------------------------------

void CapaDePresentacio::processarEsborraUsuari(){
    string contrasenyaU;
    cout << "** Esborrar usuari **" << endl;
    cout << "Per confirmar l'esborrat, s'ha d'entrar la contrasenya ... ";
    cout << "Contrasenya: ";
    utils::desactivarEco();
    cin >> contrasenyaU;
    utils::activarEco();
    TxEsborraUsuari txEsborraUsuari(contrasenyaU);
    try {
        txEsborraUsuari.executar();
        cout << "Usuari esborrat correctament!" << endl;
    }
    catch (const exception& e) {
       cout << "La contrasenya no és correcta, l'usuari no s'esborrat!"  << endl;
    }
}
