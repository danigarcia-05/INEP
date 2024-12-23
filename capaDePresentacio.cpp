#include "capaDePresentacio.h"


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
CapaDePresentacio::CapaDePresentacio() {

}

/*
*****************************************************
                   DESTRUCTORS
*****************************************************
*/


/*
*****************************************************
                   MODIFICADORS
*****************************************************
*/
void CapaDePresentacio::processarIniciarSessio(){
    string sobrenomU, contrasenyaU;
    cout << "** Inici sessió **" << endl;
    cout << "Sobrenom: ";
    cin >> sobrenomU;
    cout << "Contrasenya: ";
    utils::desactivarEco(contrasenyaU); 
    utils::activarEco(); 
    utils::clearConsole();
    TxIniciSessio txIniciSessio(sobrenomU, contrasenyaU);
    try {
        txIniciSessio.executar();
        cout << "Sessió iniciada correctament!" << endl;
        utils::enter();
    }
    catch (const exception& e) {
        cout << "Error: Hi ha hagut un error amb el sobrenom o la contrasenya"  << endl;
        utils::enter();
    }
}

void CapaDePresentacio::processarTancaSessio(){
    char tanca;
    cout << "** Tancar sessió **" << endl;
    cout << "Vols tancar la sessió (S/N): ";
    cin >> tanca;
    utils::clearConsole();
    if(tanca == 'S'){
        TxTancaSessio txTancaSessio;
        txTancaSessio.executar();
        cout << "Sessió tancada correctament!" << endl;
        utils::enter();
    }
}

void CapaDePresentacio::processarRegistreUsuari(){
    string nU, sU, cU, ceU, msU, dnU;
    cout << "** Registrar usuari **" << endl;
    cout << "Nom complet: ";
    cin.ignore(); //Revisar
    getline(cin, nU);
    cout << "Sobrenom: ";
    cin >> sU;
    cout << "Contrasenya: ";
    utils::desactivarEco(cU); 
    utils::activarEco(); 
    cout << endl << "Correu electrònic: ";
    cin >> ceU;
    
    cout << "Data naixement (DD/MM/AAAA): ";
    string data;
    cin >> data;
    string dia = string(1, data[0]) + string(1, data[1]);
    string mes = string(1, data[3]) + string(1, data[4]);
    string any = string(1, data[6]) + string(1, data[7]) + string(1, data[8]) + string(1, data[9]);
    dnU = any + "-" + mes + "-" + dia;

    cout << "Modalitats de subscripció disponibles ";
    cout << endl << " > 1. Completa ";
    cout << endl << " > 2. Cinèfil ";
    cout << endl << " > 3. Infantil ";
    cout << endl << "Escull modalitat: ";
    int mod;
    cin >> mod;
    switch (mod) {
    case 1:
        msU = "Completa";
        break;
    case 2:
        msU = "Cinèfil";
        break;
    case 3:
        msU = "Infantil";
        break;
    }
    utils::clearConsole();

    TxRegistraUsuari txRegistraUsuari(nU, sU, cU, ceU, dnU, msU);
    try {
        txRegistraUsuari.executar();
        cout << endl << "Usuari registrat correctament!" << endl;
        utils::enter();
    }   
    catch (sql::SQLException& e) {
        string errorMsg = e.what();
        if (e.getErrorCode() == 1062) { //error no es pot insertar per clau primaria o unique repetit
            if (errorMsg.find("sobrenom") != string::npos) {
                cout << "Ja existeix un usuari amb aquest sobrenom" << endl;
            } 
            else if (errorMsg.find("correu_electronic") != string::npos) {
                cout << "Ja existeix un usuari amb aquest correu electrònic" << endl;
            } 
        }
        if (e.getErrorCode() == 1452) { //el valor de la columna que està associada a la clau foràna no coincideix amb cap entrada de la taula pare
            cout << "Modalitat no existeix" << endl;
        }
        utils::enter();
    }  
}

//Cercadores pelis i series.
void CapaDePresentacio::processarConsultaUsuari() {
	TxConsultaUsuari txConsultaUsuari;
    txConsultaUsuari.executar();
    DTOUsuari resultat;
    resultat = txConsultaUsuari.obteResultat();

    utils::clearConsole();
    
    TxInfoVisualitzacions txInfoVisualitzacions;
    txInfoVisualitzacions.executar();
    pair<int, int> vis = txInfoVisualitzacions.obteResultat();
    cout << "** Consulta usuari **" << endl;
    cout << "Nom Complet: " << resultat.obteNom() << endl;
    cout << "Sobrenom: " << resultat.obteSobrenom() << endl;
    cout << "Correu electrònic: " << resultat.obteCorreu() << endl;
    cout << "Data naixement (DD/MM/AAAA): " << resultat.obteDataN() << endl; 
    cout << "Modalitat subscripció: " << resultat.obteModalitatS() << endl;
    cout << endl;
    cout << vis.first << " pel·lícules visualitzades" << endl;
    cout << vis.second << " capítols visualitzats" << endl << endl;
    
    utils::enter();
}

void CapaDePresentacio::processarModificaUsuari() {
    cout << "** Modifica usuari **" << endl;
    CtrlModificaUsuari ctrlModificaUsuari;      
    DTOUsuari infoU = ctrlModificaUsuari.consultaUsuari();

    cout << "Nom complet: " << infoU.obteNom() << endl;
    cout << "Sobrenom: " << infoU.obteSobrenom() << endl;
    cout << "Correu electrònic: " << infoU.obteCorreu() << endl;
    cout << "Data naixement (DD/MM/AAAA): " << infoU.obteDataN() << endl;
    cout << "Modalitat subscripció: " << infoU.obteModalitatS() << endl;

    utils::enter();

    cout << "Omplir la informació que es vol modificar ..." << endl;
    string nomU, contraU, correuU, subsU, neixU;

    cout << "Nom complet: ";
    getline(cin, nomU);

    cout << "Contrasenya: ";
    utils::desactivarEco(contraU);
    utils::activarEco();
    cout << endl;

    cout << "Correu electrònic: ";
    getline(cin, correuU);

    cout << "Data naixement (DD/MM/AAAA): ";
    getline(cin, neixU);

    cout << "Modalitat subscripció: ";
    getline(cin, subsU);

    utils::clearConsole();

    try {
        ctrlModificaUsuari.modificaUsuari(nomU, contraU, correuU, neixU, subsU);
        DTOUsuari infoUsu(ctrlModificaUsuari.consultaUsuari());
        cout << "** Dades usuari modificades **" << endl;
        cout << "Nom complet: " << infoUsu.obteNom() << endl;
        cout << "Sobrenom: " << infoUsu.obteSobrenom() << endl;
        cout << "Correu electrònic: " << infoUsu.obteCorreu() << endl;
        cout << "Data naixement (DD/MM/AAAA): " << infoUsu.obteDataN() << endl;
        cout << "Modalitat subscripció: " << infoUsu.obteModalitatS() << endl;
        utils::enter();
    }
    catch (sql::SQLException& e) {
        string errorMsg = e.what();
        if (e.getErrorCode() == 1062) { //error no es pot insertar per clau primaria o unique repetit
            if (errorMsg.find("correu_electronic") != string::npos) {
                cout << "El nou correu electrònic ja existeix" << endl; 
            }
        }
        utils::enter();
    }
}

void CapaDePresentacio::processarEsborraUsuari(){
    string contrasenyaU;
    cout << "** Esborrar usuari **" << endl;
    cout << "Per confirmar l'esborrat, s'ha d'entrar la contrasenya ... " << endl;
    cout << "Contrasenya: ";
    utils::desactivarEco(contrasenyaU); 
    utils::activarEco(); 
    
    utils::clearConsole();

    TxEsborraUsuari txEsborraUsuari(contrasenyaU);
    try {
        txEsborraUsuari.executar();
        cout << endl << "Usuari esborrat correctament!" << endl;
        utils::enter();
    }
    catch (const exception& e) {
       cout << "La contrasenya no és correcta, l'usuari no s'esborrat!"  << endl;
       utils::enter();
    }   
}

void CapaDePresentacio::processarUltimesNovetats(){
    cout << "HOla" << endl;
}

void CapaDePresentacio::processarProperesEstrenes(){
     cout << "HOla" << endl;
}

void CapaDePresentacio::processarPeliculesMesVistes(){
     cout << "HOla" << endl;
}

void CapaDePresentacio::processarVisualitzarPelicula() {

}
void CapaDePresentacio::processarVisualitzarCapitol() {

}
void CapaDePresentacio::processarConsultarVisualitzacions() {

}
void CapaDePresentacio::processarModificaContrasenya() {
    cout << "** Modifica contrasenya **" << endl;
    CtrlModificaUsuari ctrlModificaUsuari;
    DTOUsuari infoU = ctrlModificaUsuari.consultaUsuari();

    cout << "Entra la nova contrasenya ..." << endl;
    string contraU;

    cout << "Contrasenya: ";
    utils::desactivarEco(contraU);
    utils::activarEco();

    try {
        ctrlModificaUsuari.modificaContrasenya(contraU);
        DTOUsuari infoUsu(ctrlModificaUsuari.consultaUsuari());
        utils::enter();
    }
    catch (sql::SQLException& e) {
        string errorMsg = e.what();
        if (e.getErrorCode() == 1062) { //error no es pot insertar per clau primaria o unique repetit
            if (errorMsg.find("correu_electronic") != string::npos) {
                cout << "El nou correu electrònic ja existeix" << endl;
            }
        }
        utils::enter();
    }
}