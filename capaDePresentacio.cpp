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
   
}

void CapaDePresentacio::processarProperesEstrenes(){
    cout << "** Properes estrenes **" << endl;
    cout << "Modalitat: ";
    string mod;
    PetitFlix& petitFlix = PetitFlix::getInstance();

    if(petitFlix.obteUsuari() == nullptr) cin >> mod;
    else mod = petitFlix.obteUsuari().obteModalitatS();
    cout << mod << endl << endl;

    TxProperesEstrenes txProperesEstrenes;
    txProperesEstrenes.executar(mod);
    vector<DTOContingut> vC = txProperesEstrenes.obteResultat();
    for () {
        if(tipus == "serie"){

        }
        else{

        }
    }
}

void CapaDePresentacio::processarPeliculesMesVistes() {
    cout << "** Pel·lícules més visualitzades **" << endl;
    
    TxConsultaMesVistes txConsultaMesVistes;
    txConsultaMesVistes.executar();
    vector<DTOPelicula> mesVistes = txConsultaMesVistes.obteResultat();

    TxConsultaVisualitzacioPelicula txConsultaVisualitzacioPelicula;

    TxConsultaUsuari txConsultaUsuari;
    txConsultaUsuari.executar();
    DTOUsuari usuari = txConsultaUsuari.obteResultat();

    for (int i = 0; i < mesVistes.size(); ++i) {
        txConsultaVisualitzacioPelicula.executarPelVis(mesVistes[i].obteTitol(), usuari.obteSobrenom());
        DTOVisualitzacioPelicula vp = txConsultaVisualitzacioPelicula.obteResultatSingle();
        cout << (i+1) << ".- " << mesVistes[i].obteTitol() << "; " << mesVistes[i].obteQualificacio() << "; " << mesVistes[i].obteDuracio() << " min. Visualitzacions: " << mesVistes[i].obteVisualitzacionsGlobals();
        if (vp.obteTitol() != "") cout << " [VISTA: " << vp.obteDataVP() << "]";
        cout << endl;
    }
    utils::enter();
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

    cout << "Informació pel·lícula ..." << endl;
    cout << "Nom pel·lícula: " << infoP.obteTitol() << endl;
    cout << "Descripció: " << infoP.obteDescripcio() << endl;
    cout << "Qualificació: " << infoP.obteQualificacio() << endl;
    cout << "Data estrena: " << infoP.obteDataP() << endl;
    cout << "Duració: " << infoP.obteDuracio() << endl;

    char op;
    cout << endl << "Vols continuar amb la visualitzacio? (S/N): ";
    cin >> op;
    utils::clearConsole();
    
    if (op == 'S') {
        try {
            string sobrenom = ctrlVisualitzaPelicula.consultaPeliculaUsuari(titolP);
            ctrlVisualitzaPelicula.modificaVisualitzacioPelicula(titolP, sobrenom);

            cout << "Visualització registrada: " << utils::convertitADDMMYYYY(utils::dataActual()) << " " << utils::horaActual() << endl << endl;
            cout<<"Pel·lícules relacionades:"<<endl;
            vector<string> pelRelacionades = ctrlVisualitzaPelicula.consultaRelacionades(titolP);
            for (int i=0; i < pelRelacionades.size(); ++i) {
                DTOPelicula p = ctrlVisualitzaPelicula.consultaPelicula(pelRelacionades[i]);
                cout<< "- " << p.obteTitol() << "; " << p.obteDescripcio() << "; " << p.obteQualificacio() << "; "<<p.obteDuracio() << " min; " << p.obteDataP() << endl;
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
    cout << "** Visualitzar Capitol **" << endl;
    cout << "Nom de la sèrie: ";
    string nomS;
    cin.ignore();
    getline(cin, nomS);
    utils::clearConsole();
    CtrlVisualitzaCapitol ctrlVisualitzaCapitol;
    int numTemp = ctrlVisualitzaCapitol.obteNumTemporades(nomS);
    cout << "La sèrie té " << numTemp << " temporades." << endl << endl;
    cout << "Escull temporada: ";
    int temporada; 
    cin >> temporada;
    if (temporada > numTemp) cout << "error" << endl; 
    utils::clearConsole();
    vector<DTOCapitol> capitols = ctrlVisualitzaCapitol.obteCapitolsTemp(nomS, temporada);
        
    TxConsultaVisualitzacioCapitol txConsultaVisualitzacioCapitol;
    
    TxConsultaUsuari txConsultaUsuari;
    txConsultaUsuari.executar();
    DTOUsuari usuari = txConsultaUsuari.obteResultat();

    cout << "Llista capítols:" << endl; 
    for (int i = capitols.size() - 1; i >= 0; --i) {
        cout << capitols[i].obteNumCap() << ". " << capitols[i].obteTitolC() << "; " << capitols[i].obteDataEstrena() << "; ";
       
        txConsultaVisualitzacioCapitol.executar(usuari.obteSobrenom(), nomS, capitols[i].obteNumTemp(), capitols[i].obteNumCap());
        DTOVisualitzacioCapitol vCapitol = txConsultaVisualitzacioCapitol.obteResultat();

        if (vCapitol.obteTitolSerie() == "") cout << "no visualitzat" << endl;
        else cout << "visualitzat el " << utils::convertitADDMMYYYY(vCapitol.obteData()) << endl;
    }

    cout << endl << "Número de capítol a visualitzar: ";
    int capitol;
    cin >> capitol;
    utils::clearConsole();

    cout << "Número de capítol a visualitzar: " << capitol << endl;
    cout << endl << "Vols continuar amb la visualització? (S/N): ";
    string op;
    cin >> op;
    utils::clearConsole();
    if(op == "S"){
        string sobrenomU = ctrlVisualitzaCapitol.consultaSerieUsuari(nomS, temporada, capitol);
        ctrlVisualitzaCapitol.visualitzaCapitol(sobrenomU, nomS, temporada, capitol);
        cout << "Visualització registrada: " << utils::convertitADDMMYYYY(utils::dataActual()) << " " << utils::horaActual() << endl;
        utils::enter();
    }
}

void CapaDePresentacio::processarConsultarVisualitzacions() {
    cout << "** Consulta visualitzacions **" << endl << endl;
    cout << "** Visualitzacions pel·lícules **" << endl;
    cout << "*********************************" << endl;

    TxConsultaUsuari txConsultaUsuari;
    txConsultaUsuari.executar();
    DTOUsuari usuari = txConsultaUsuari.obteResultat();
    string sobrenomU = usuari.obteSobrenom();

    TxConsultaVisualitzacioPelicula txConsultaVisualitzacioPelicula;
    txConsultaVisualitzacioPelicula.executarVP(sobrenomU);
    vector<DTOVisualitzacioPelicula> vPelicula = txConsultaVisualitzacioPelicula.obteResultat();

    TxConsultaPelicula txConsultaPelicula;
    
    for (int i = 0; i < vPelicula.size(); ++i) {
        txConsultaPelicula.executar(vPelicula[i].obteTitol());
        DTOPelicula p = txConsultaPelicula.obteResultat();
        cout << vPelicula[i].obteDataVP()<< ": " << p.obteTitol() << "; " << p.obteDescripcio() << "; " <<p.obteQualificacio() << "; nombre de visualitzacions: " << vPelicula[i].obteVisualitzacions() << endl;
    }

    cout << endl << "** Visualitzacions sèries **" << endl;
    cout << "****************************" << endl;

    TxConsultaContingut txConsultaContingut;
    TxConsultaVisualitzacioCapitol txConsultaVisualitzacioCapitol;
    txConsultaVisualitzacioCapitol.executarCV(sobrenomU);
    vector<DTOVisualitzacioCapitol> vCapitol = txConsultaVisualitzacioCapitol.obteCapitolsVisualitzats();
    for (int i = 0; i < vCapitol.size(); ++i) {
        txConsultaContingut.executar(vCapitol[i].obteTitolSerie());
        DTOContingut cont = txConsultaContingut.obteResultat();
        cout << vCapitol[i].obteData() << ": " << vCapitol[i].obteTitolSerie() << "; " << cont.obteQualificacio() << "; Temporada " << vCapitol[i].obteNumTemporada() << ", capítol: " << vCapitol[i].obteNumCapitol() << "; nombre de visualitzacions: " << vCapitol[i].obteNumVisualitzacions() << endl;
    }
    utils::enter();
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