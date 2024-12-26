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
    cout << endl << "Vols tancar la sessió (S/N): ";
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
    cin >> dnU;
    dnU = utils::convertToDatetime(dnU);

    cout << "Modalitats de subscripció disponibles ";
    cout << endl << " > 1. Completa ";
    cout << endl << " > 2. Cinèfil ";
    cout << endl << " > 3. Infantil ";
    cout << endl << "Escull número de modalitat: ";
    string mod;
    cin >> mod;
    if(mod == "1") msU = "Completa";
    else if (mod == "2") msU = "Cinèfil";
    else if (mod == "3") msU = "Infantil";
    utils::clearConsole();

    TxRegistraUsuari txRegistraUsuari(nU, sU, cU, ceU, dnU, msU);
    try {
        txRegistraUsuari.executar();
        cout << endl << "Usuari registrat correctament!" << endl;
        utils::enter();
    }  
    catch (sql::SQLException& e) { //No funciona
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
    cout << "Data naixement (DD/MM/AAAA): " << utils::convertitADDMMYYYY(infoU.obteDataN()) << endl;
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
    neixU = utils::convertToDatetime(neixU);

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
        string data = infoUsu.obteDataN();
        utils::convertitADDMMYYYY(data);
        cout << "Data naixement (DD/MM/AAAA): " << data << endl;
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
   
}

void CapaDePresentacio::processarProperesEstrenes(){
     
}

void CapaDePresentacio::processarPeliculesMesVistes(){
     
}

void CapaDePresentacio::processarVisualitzarPelicula() {
    cout << "** Visualitzar Pel·lícula **" << endl;
    cout << "Nom pel·lícula: ";
    cin.ignore();
    string titolP;
    getline(cin, titolP);
    utils::clearConsole();
    CtrlVisualitzaPelicula ctrlVisualitzaPelicula;
    DTOPelicula infoP = ctrlVisualitzaPelicula.consultaPelicula(titolP);

    cout << "Nom pel·lícula: " << infoP.obteTitol() << endl;
    cout << "Descripció: " << infoP.obteDescripcio() << endl;
    cout << "Qualificació: " << infoP.obteQualificacio() << endl;
    string data = utils::convertitADDMMYYYY(infoP.obteDataP());
    cout << "Data estrena: " << data << endl;
    cout << "Duració: " << infoP.obteDuracio() << endl;

    char op;
    cout << endl << "Vols continuar amb la visualitzacio? (S/N): ";
    cin >> op;
    utils::clearConsole();
    
    if (op == 'S') {
        try {
            ctrlVisualitzaPelicula.consultaPeliculaUsuari(titolP);
            ctrlVisualitzaPelicula.modificaVisualitzacioPelicula(titolP);

            cout << "Visualització registrada: " << utils::dataActual() << endl;

            cout<<"Pel·lícules relacionades:"<<endl;
            vector<string> pelRelacionades = ctrlVisualitzaPelicula.consultaRelacionades(titolP);
            for (int i=0; i < pelRelacionades.size(); ++i) {
                DTOPelicula p = ctrlVisualitzaPelicula.consultaPelicula(pelRelacionades[i]);
                cout<< "- " << p.obteTitol() << "; " << p.obteDescripcio() << "; " << p.obteQualificacio() << "; "<<p.obteDuracio() << " min ; " << utils::convertitADDMMYYYY(p.obteDataP()) << endl;
            }
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
}

void CapaDePresentacio::processarVisualitzarCapitol() {
    cout << "** Visualitzar capitol **" << endl;
    cout << "Nom de la sèrie: ";
    string nomS;
    getline(cin, nomS);
    utils::clearConsole();

    
}
void CapaDePresentacio::processarConsultarVisualitzacions() {

}

//NO ACABAT
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
        utils::clearConsole();
        cout << "Contrasenya modificada correctament!" << endl;
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