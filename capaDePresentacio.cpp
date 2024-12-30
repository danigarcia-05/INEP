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
    std::locale::global(std::locale("ca_ES.utf8"));
    std::cin.imbue(std::locale());
    std::cout.imbue(std::locale());
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
        string errorMessage = e.what();
        if (errorMessage == "UsuariNoExisteix" or errorMessage == "ErrorContrasenya") {
            cout << "Error: Hi ha hagut un error amb el sobrenom o la contrasenya."  << endl;
        }
        else if (errorMessage == "ArxiuNoExisteix") {
            cout << "Error: No s'ha trobat l'arxiu de credencials necessari per obtenir permís d'accés a la base de dades." << endl;
        }
        else cout << "Error" << endl;
        utils::enter();
    }
}

void CapaDePresentacio::processarTancaSessio(){
    string tanca;
    do {
        cout << "** Tancar sessió **" << endl;
        cout << endl << "Vols tancar la sessió (S/N): ";
        getline(cin, tanca);
        utils::clearConsole();
    } while (tanca != "S" and tanca != "N");

    utils::clearConsole();
    if (tanca == "S") {
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
    while (nU == "") {
        getline(cin, nU);   
    }        
    cout << "Sobrenom: ";
    cin >> sU;
    cout << "Contrasenya: ";
    while (cU == "") {
        utils::desactivarEco(cU); 
        if (cU == "") cout << endl;
    }    
    utils::activarEco(); 
    cout << endl << "Correu electrònic: ";
    cin >> ceU;
    
    cout << "Data naixement (DD/MM/AAAA): ";
    cin >> dnU;
    
    cout << "Modalitats de subscripció disponibles: ";
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
    
    if (not utils::esFormatDataValid(dnU) or utils::dataMesGran(dnU, utils::convertitADDMMYYYY(utils::dataActual()))){
        cout << "Error: La data introduïda no és vàlida." << endl;
        utils::enter();
        return;
    } 

    TxRegistraUsuari txRegistraUsuari(nU, sU, cU, ceU, dnU, msU);
    try {
        txRegistraUsuari.executar();
        cout << endl << "Usuari registrat correctament!" << endl;
        utils::enter();
    }  
    catch (const exception& e) {
        string errorMessage = e.what();
        if (errorMessage.find("Duplicate entry") != string::npos) {
            if (errorMessage.find("PRIMARY") != string::npos) {
                cout << "Error: Ja existeix un usuari amb aquest sobrenom." << endl;
            }
            else if (errorMessage.find("correu_electronic") != string::npos) {
                cout << "Error: Ja existeix un usuari amb aquest correu electrònic." << endl;
            }
        }
        else if (errorMessage.find("foreign key constraint fails") != string::npos) {
            cout << "Error: La modalitat escollida no existeix." << endl;
        }
        else if (errorMessage == "ArxiuNoExisteix") {
            cout << "Error: No s'ha trobat l'arxiu de credencials necessari per obtenir permís d'accés a la base de dades." << endl;
        }
        else cout << "Error" << endl;
        utils::enter();
    }
}

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

    cout << "-- Omplir només la informació que es vol modificar --" << endl;
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

    cout << "Modalitats de subscripció disponibles: ";
    cout << endl << " > 1. Completa ";
    cout << endl << " > 2. Cinèfil ";
    cout << endl << " > 3. Infantil ";
    cout << endl << "Escull número de modalitat: ";
   
    string mod;
    getline(cin, mod);
    if (mod == "1") subsU = "Completa";
    else if (mod == "2") subsU = "Cinèfil";
    else if (mod == "3") subsU = "Infantil";
    else if (mod != "") subsU = mod;
    
    utils::clearConsole();

    if (neixU != "" and (not utils::esFormatDataValid(neixU) or utils::dataMesGran(neixU, utils::convertitADDMMYYYY(utils::dataActual())))) {
        cout << "Error: La data introduïda no és vàlida." << endl;
        utils::enter();
        return;
    }

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
    catch (const exception& e) {
        string errorMessage = e.what();
        if (errorMessage.find("Duplicate entry") != string::npos) {
            if (errorMessage.find("correu_electronic") != string::npos) {
                cout << "Error: Ja existeix un usuari amb aquest correu electrònic." << endl;
            }
        }
        else if (errorMessage.find("foreign key constraint fails") != string::npos) {
            cout << "Error: La modalitat escollida no existeix." << endl;
        }
        else if (errorMessage == "ArxiuNoExisteix") {
            cout << "Error: No s'ha trobat l'arxiu de credencials necessari per obtenir permís d'accés a la base de dades." << endl;
        }
        else cout << "Error" << endl;
        utils::enter();
    }
}

void CapaDePresentacio::processarEsborraUsuari(){
    string contrasenyaU;
    cout << "** Esborrar usuari **" << endl;
    cout << "-- Per esborrar l'usuari, entra la contrasenya --" << endl;
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
        string errorMessage = e.what();
        if (errorMessage == "ErrorContrasenya") cout << "La contrasenya no és correcta, l'usuari no ha estat esborrat." << endl;
        else if (errorMessage == "ArxiuNoExisteix") {
            cout << "Error: No s'ha trobat l'arxiu de credencials necessari per obtenir permís d'accés a la base de dades." << endl;
        }
        else cout << "Error" << endl;
        utils::enter();
    }   
}

void CapaDePresentacio::processarUltimesNovetats(){
    cout << "** Novetats **" << endl;
    string mod;
   
    PetitFlix& petitFlix = PetitFlix::getInstance();
    if (petitFlix.obteUsuari() == nullptr) {
        cout << "Modalitats de subscripció disponibles: ";
        cout << endl << " > 1. Completa ";
        cout << endl << " > 2. Cinèfil ";
        cout << endl << " > 3. Infantil ";
        cout << endl << "Escull número de modalitat: ";
        cin >> mod;
        if (mod == "1") mod = "Completa";
        else if (mod == "2") mod = "Cinèfil";
        else if (mod == "3") mod = "Infantil";
    }
    else mod = petitFlix.obteUsuari()->obteModalitatSubscripcio();

    utils::clearConsole();
    cout << "** Novetats **" << endl;
    cout << "Modalitat de l'usuari: " << mod << endl;

    try {
        TxConsultaNovetats txConsultaNovetats;
        txConsultaNovetats.executar(mod);
        cout << endl;

        cout << "** Novetats pel·lícules **" << endl;
        cout << "**************************" << endl;
    
        vector<DTOPelicula> cjPelicules = txConsultaNovetats.obtePelicules();
        if (cjPelicules.size() == 0) cout << "No hi ha novetats en pel·lícules de la modalitat escollida." << endl;
        for (int i=0; i<cjPelicules.size(); ++i){
            cout<<i+1<<".- "<<cjPelicules[i].obteDataP()<<": "<<cjPelicules[i].obteTitol()<<"; "<<cjPelicules[i].obteQualificacio()<<"; "<<cjPelicules[i].obteDuracio()<<" min." << endl;
        }
        cout<<endl<<"** Novetats sèries **"<<endl;
        cout<<"*********************"<<endl;
        vector<DTOCapitol> cjCapitols = txConsultaNovetats.obteCapitols();
        if (cjCapitols.size() == 0) cout << "No hi ha novetats en capítols de la modalitat escollida." << endl;
        for (int i=0; i<cjCapitols.size(); ++i){
            cout<<i+1<<".- "<<cjCapitols[i].obteDataEstrena()<<": "<<cjCapitols[i].obteTitolS()<<"; Temporada "<<cjCapitols[i].obteNumTemp()<<", capitol "<<cjCapitols[i].obteNumCap()<<"; "<< cjCapitols[i].obteDuracioC() <<" min."<<endl;
        }
        utils::enter();
    }
    catch (const exception& e) {
        utils::clearConsole();
        string errorMessage = e.what();
        if (errorMessage == "ModalitatNoExisteix") {
            cout << "Error: La modalitat escollida no existeix." << endl;
        }
        else if (errorMessage == "ArxiuNoExisteix") {
            cout << "Error: No s'ha trobat l'arxiu de credencials necessari per obtenir permís d'accés a la base de dades." << endl;
        }
        else cout << "Error" << endl;
        utils::enter();
    }
   
}

void CapaDePresentacio::processarProperesEstrenes(){
    cout << "** Properes estrenes **" << endl;
    string mod;
    
    PetitFlix& petitFlix = PetitFlix::getInstance();
    if (petitFlix.obteUsuari() == nullptr) {
        cout << "Modalitats de subscripció disponibles: ";
        cout << endl << " > 1. Completa ";
        cout << endl << " > 2. Cinèfil ";
        cout << endl << " > 3. Infantil ";
        cout << endl << "Escull número de modalitat: ";
        cin >> mod;
        if (mod == "1") mod = "Completa";
        else if (mod == "2") mod = "Cinèfil";
        else if (mod == "3") mod = "Infantil";
    }
    else  mod = petitFlix.obteUsuari()->obteModalitatSubscripcio();
    
    utils::clearConsole();
    cout << "** Properes estrenes **" << endl;
    cout << "Modalitat de l'usuari: " << mod << endl;

    try {
        TxProperesEstrenes txProperesEstrenes;
        txProperesEstrenes.executar(mod);
        cout << endl;
        vector<DTONovetat> cjNovetats = txProperesEstrenes.obteResultat();

        for (int i = 0; i < cjNovetats.size(); ++i) {
            string tipus = cjNovetats[i].obteTipus();
            cout << i + 1 << ".- " << cjNovetats[i].obteData() << " [";
            if (tipus == "Serie") cout << "Sèrie";
            else cout << "Pel·lícula";
            cout << "]: " << cjNovetats[i].ObteTitol() << "; " << cjNovetats[i].obteQualificacio() << "; ";
            if (tipus == "Serie") cout << "Temporada ";
            cout << cjNovetats[i].obteDetalls();
            if (tipus == "Pelicula") cout << " min";
            cout << "." << endl;
        }
        utils::enter();
    }
    catch (const exception& e) {
        utils::clearConsole();
        string errorMessage = e.what();
        if (errorMessage == "ModalitatNoExisteix") {
            cout << "Error: La modalitat escollida no existeix." << endl;
        }
        else if (errorMessage == "ArxiuNoExisteix") {
            cout << "Error: No s'ha trobat l'arxiu de credencials necessari per obtenir permís d'accés a la base de dades." << endl;
        }
        else cout << "Error" << endl;
        utils::enter();
    }
}

void CapaDePresentacio::processarPeliculesMesVistes() {
    cout << "** Pel·lícules més visualitzades **" << endl;
    try { 
        TxConsultaMesVistes txConsultaMesVistes;
        txConsultaMesVistes.executar();
        vector<DTOPelicula> mesVistes = txConsultaMesVistes.obteResultat();
        TxConsultaVisualitzacioPelicula txConsultaVisualitzacioPelicula;

        TxConsultaUsuari txConsultaUsuari;
        bool iniciatSessio = txConsultaUsuari.executar();
        DTOUsuari usuari;
        if(iniciatSessio) usuari = txConsultaUsuari.obteResultat();
        for (int i = 0; i < mesVistes.size(); ++i) {
            cout << endl;
            cout << (i + 1) << ".- " << mesVistes[i].obteTitol() << "; " << mesVistes[i].obteQualificacio() << "; " << mesVistes[i].obteDuracio() << " min. Visualitzacions: " << mesVistes[i].obteVisualitzacionsGlobals();
            if (iniciatSessio) {
                txConsultaVisualitzacioPelicula.executarPelVis(mesVistes[i].obteTitol(), usuari.obteSobrenom());
                DTOVisualitzacioPelicula vp = txConsultaVisualitzacioPelicula.obteResultatSingle();
                if (vp.obteTitol() != "") cout << " [VISTA: " << vp.obteDataVP() << "]";
            }
        }
        cout << endl;
        utils::enter();
    }
    catch (const exception& e) {
        string errorMessage = e.what();
        if (errorMessage == "SenseVisualitzacions") {
            cout << "Error: Encara no hi han pel·lícules més vistes al sistema" << endl;
        }
        else if (errorMessage == "ArxiuNoExisteix") {
            cout << "Error: No s'ha trobat l'arxiu de credencials necessari per obtenir permís d'accés a la base de dades." << endl;
        }
        utils::enter();
    }   
}

void CapaDePresentacio::processarVisualitzarPelicula() {
    cout << "** Visualitzar Pel·lícula **" << endl;
    cout << "Nom pel·lícula: ";
    cin.ignore();
    string titolP;
    getline(cin, titolP);
    utils::clearConsole();
    try {
        CtrlVisualitzaPelicula ctrlVisualitzaPelicula;
        DTOPelicula infoP = ctrlVisualitzaPelicula.consultaPelicula(titolP);

        string op;
        do {
            cout << "-- Informació pel·lícula --" << endl;
            cout << "Nom pel·lícula: " << infoP.obteTitol() << endl;
            cout << "Descripció: " << infoP.obteDescripcio() << endl;
            cout << "Qualificació: " << infoP.obteQualificacio() << endl;
            cout << "Data estrena: " << infoP.obteDataP() << endl;
            cout << "Duració: " << infoP.obteDuracio() << endl;

            cout << endl << "Vols continuar amb la visualitzacio? (S/N): ";
            getline(cin, op);
            utils::clearConsole();
        } 
        while (op != "S" and op != "N");
    
        utils::clearConsole();
        if (op == "S") {
            ctrlVisualitzaPelicula.consultaPeliculaUsuari(titolP);
            ctrlVisualitzaPelicula.modificaVisualitzacioPelicula(titolP);

            cout << "Visualització registrada: " << utils::convertitADDMMYYYY(utils::dataActual()) << " " << utils::horaActual() << endl << endl;
            cout<<"Pel·lícules relacionades:"<<endl;
            ctrlVisualitzaPelicula.consultaRelacionades(titolP);
            vector<DTOPelicula> pelRelacionades = ctrlVisualitzaPelicula.obteResultat();
            if (pelRelacionades.size() == 0) cout << "Aquesta pel·lícula no té altres relacionades." << endl;
            for (int i=0; i < pelRelacionades.size(); ++i) {
                cout<< "- " << pelRelacionades[i].obteTitol() << "; " << pelRelacionades[i].obteDescripcio() << "; " << pelRelacionades[i].obteQualificacio() << "; " << pelRelacionades[i].obteDuracio() << " min; " << pelRelacionades[i].obteDataP() << endl;
            }
            utils::enter();
        }
    }
    catch (const exception& e) {
        string errorMessage = e.what();
        if (errorMessage == "PeliculaNoExisteix") {
            cout << "Error: La pel·lícula cercada no existeix." << endl;
        }
        else if (errorMessage == "PeliculaNoEstrenada") {
            cout << "Error: La pel·lícula cercada no ha sigut estrenada." << endl;
        }
        else if (errorMessage == "PeliculaNoApropiada") {
            cout << "Error: La pel·lícula cercada no és apropiada per l'edat de l'usuari." << endl;
        }
        else if (errorMessage == "ModalitatIncorrecta") {
            cout << "Error: La pel·lícula cercada no entra en aquesta modalitat de subscripció." << endl;
        }
        else if (errorMessage == "ArxiuNoExisteix") {
            cout << "Error: No s'ha trobat l'arxiu de credencials necessari per obtenir permís d'accés a la base de dades." << endl;
        }
        else cout << "Error" << endl;
        utils::enter();
    }
}

void CapaDePresentacio::processarVisualitzarCapitol() {
    cout << "** Visualitzar Capitol **" << endl;
    cout << "Nom de la sèrie: ";
    string nomS;
    cin.ignore();
    getline(cin, nomS);
    utils::clearConsole();
    try {
        CtrlVisualitzaCapitol ctrlVisualitzaCapitol;
        int numTemp = ctrlVisualitzaCapitol.obteNumTemporades(nomS);
        cout << "La sèrie té " << numTemp << " temporades." << endl << endl;
        cout << "Escull temporada: ";
        int temporada; 
        cin >> temporada;
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

            if (vCapitol.obteTitolSerie().empty())
                cout << "no visualitzat" << endl;
            else
                cout << "visualitzat el " << utils::convertitADDMMYYYY(vCapitol.obteData()) << endl;
        }

        cout << endl << "Número de capítol a visualitzar: ";
        int capitol;
        cin >> capitol;
        utils::clearConsole();

        string op;
        do {
            cout << "Número de capítol a visualitzar: " << capitol << endl;
            cout << endl << "Vols continuar amb la visualització? (S/N): ";
            cin >> op;
            utils::clearConsole();
        } while (op != "S" and op != "N");
     
        if (op == "S") {  
            ctrlVisualitzaCapitol.consultaSerieUsuari(nomS, temporada, capitol);
            ctrlVisualitzaCapitol.visualitzaCapitol(nomS, temporada, capitol); 
            cout << "Visualització registrada: " << utils::convertitADDMMYYYY(utils::dataActual()) << " " << utils::horaActual() << endl;
            utils::enter();
        }
    } 
    catch (const exception& e) {
        string errorMessage = e.what();
        if (errorMessage == "SerieNoExisteix") {
            cout << "Error: La sèrie cercada no existeix." << endl;
        }
        else if (errorMessage == "SerieNoApropiada") {
            cout << "Error: La sèrie no és apropiada per l'edat de l'usuari." << endl;
        }
        else if (errorMessage == "TemporadaNoExisteix") {
            cout << "Error: La temporada seleccionada no existeix." << endl;
        }
        else if (errorMessage == "CapitolNoExisteix") {
            cout << "Error: El capitol cercat no existeix." << endl;
        }
        else if (errorMessage == "CapitolNoEstrenat") {
            cout << "Error: El capitol cercat no ha sigut estrenat." << endl;
        }
        else if (errorMessage == "ModalitatIncorrecta") {
            cout << "Error: El capitol cercat no entra en aquesta modalitat de subscripció." << endl;
        }
        else if (errorMessage == "ArxiuNoExisteix") {
            cout << "Error: No s'ha trobat l'arxiu de credencials necessari per obtenir permís d'accés a la base de dades." << endl;
        }
        else cout << "Error" << endl;
        utils::enter();
    } 
}

void CapaDePresentacio::processarConsultarVisualitzacions() {
    try {
        TxVisualitzacionsUsuari txVisualitzacionsUsuari;
        txVisualitzacionsUsuari.executar();
        
        vector<DTOVisualitzacioPelicula> vPelicula = txVisualitzacionsUsuari.obteVisualitzacionsPelicula();
        vector<DTOVisualitzacioCapitol> vCapitol = txVisualitzacionsUsuari.obteVisualitzacionsCapitol();

        TxConsultaPelicula txConsultaPelicula;
        TxConsultaContingut txConsultaContingut;

        cout << "** Consulta visualitzacions **" << endl << endl;
        cout << "** Visualitzacions pel·lícules **" << endl;
        cout << "*********************************" << endl;
        for (int i = 0; i < vPelicula.size(); ++i) {
            txConsultaPelicula.executar(vPelicula[i].obteTitol());
            DTOPelicula p = txConsultaPelicula.obteResultat();
            cout << vPelicula[i].obteDataVP() << ": " << p.obteTitol() << "; " << p.obteDescripcio() << "; " << p.obteQualificacio() << "; nombre de visualitzacions: " << vPelicula[i].obteVisualitzacions() << endl;
        }

        cout << endl << "** Visualitzacions sèries **" << endl;
        cout << "****************************" << endl;
        for (int i = 0; i < vCapitol.size(); ++i) {
            txConsultaContingut.executar(vCapitol[i].obteTitolSerie());
            DTOContingut cont = txConsultaContingut.obteResultat();
            cout << vCapitol[i].obteData() << ": " << vCapitol[i].obteTitolSerie() << "; " << cont.obteQualificacio() << "; Temporada " << vCapitol[i].obteNumTemporada() << ", capítol: " << vCapitol[i].obteNumCapitol() << "; nombre de visualitzacions: " << vCapitol[i].obteNumVisualitzacions() << endl;
        }
        utils::enter();
    }
    catch (const exception& e) {
        string errorMessage = e.what();
        if (errorMessage == "SenseVisualitzacions") {
            cout << "Error: Encara no s'ha visualitzat cap contingut." << endl;
        }
        else if (errorMessage == "ArxiuNoExisteix") {
            cout << "Error: No s'ha trobat l'arxiu de credencials necessari per obtenir permís d'accés a la base de dades." << endl;
        }
        else cout << "Error" << endl;
        utils::enter();
    }
}

void CapaDePresentacio::processarModificaContrasenya() {
    cout << "** Modifica contrasenya **" << endl;
    CtrlModificaUsuari ctrlModificaUsuari;
    DTOUsuari infoU = ctrlModificaUsuari.consultaUsuari();

    cout << "-- Entra la nova contrasenya --" << endl;
    string contraU;

    cout << "Contrasenya: ";
    utils::desactivarEco(contraU);
    utils::activarEco();

    bool modificada = ctrlModificaUsuari.modificaContrasenya(contraU);
    utils::clearConsole();
    if(modificada) cout << "Contrasenya modificada correctament!" << endl;
    else cout << "La contrasenya no ha sigut modificada." << endl;
    utils::enter();
}