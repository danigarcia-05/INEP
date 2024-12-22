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
    cout << "** Inici sessio **" << endl;
    cout << "Sobrenom: ";
    cin >> sobrenomU;
    //utils::desactivarEco();
    cout << "Contrasenya: ";
    utils::desactivarEco(contrasenyaU); 
    utils::activarEco(); 

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
    char tanca;
    cout << "** Tancar sessio **" << endl;
    cout << "Vols tancar la sessio (S/N): ";
    cin >> tanca;
    if(tanca == 'S'){
        TxTancaSessio txTancaSessio;
        txTancaSessio.executar();
        cout << "Sessio tancada correctament!" << endl;
    }
}

void CapaDePresentacio::processarRegistreUsuari(){
    string nU, sU, cU, ceU, msU, dnU;
    cout << "** Registrar usuari **" << endl;
    cout << "Nom complet: ";
    cin.ignore(); //Revisar
    getline(cin, nU);
    cout  << "Sobrenom: ";
    cin >> sU;
    cout  <<  "Contrasenya: ";
    utils::desactivarEco(cU); 
    utils::activarEco(); 
    cout << endl << "Correu Electrònic: ";
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

    TxRegistraUsuari txRegistraUsuari(nU, sU, cU, ceU, dnU, msU);
    try {
        txRegistraUsuari.executar();
        cout << endl << "Usuari registrat correctament!" << endl;
    }   
    catch (sql::SQLException& e) {
        string errorMsg = e.what();
        if (e.getErrorCode() == 1062) { //error no es pot insertar per clau primaria o unique repetit
            if (errorMsg.find("sobrenom") != string::npos) {
                cout << "Ja existeix un usuari amb aquest sobrnom" << endl;
            } 
            else if (errorMsg.find("correu_electronic") != string::npos) {
                cout << "Ja existeix un usuari amb aquest correu electrònic" << endl;
            } 
        }
        if (e.getErrorCode() == 1452) { //el valor de la columna que està associada a la clau foràna no coincideix amb cap entrada de la taula pare
            cout << "Modalitat no existeix" << endl;
        }
    }    
}

//Cercadores pelis i series.
void CapaDePresentacio::processarConsultaUsuari() {
	TxConsultaUsuari txConsultaUsuari;
    txConsultaUsuari.executar();
    DTOUsuari resultat;
    resultat = txConsultaUsuari.obteResultat();

    TxInfoVisualitzacions txInfoVisualitzacions;
    txInfoVisualitzacions.executar();
    pair<int, int> vis = txInfoVisualitzacions.obteResultat();
    cout << "** Consulta usuari **" << endl;
    cout << "Nom Complet: " << resultat.obteNom() << endl;
    cout << "Sobrenom: " << resultat.obteSobrenom() << endl;
    cout << "Correu electronic: " << resultat.obteCorreu() << endl;
    cout << "Data naixement (DD/MM/AAAA): " << resultat.obteDataN() << endl; 
    cout << "Modalitat subscripció: " << resultat.obteModalitatS() << endl;
    cout << endl;
    cout << vis.first << " pel·licules visualitzades" << endl;
    cout << vis.second << " capitols visualitzats" << endl;
}

void CapaDePresentacio::processarModificaUsuari() {
        cout << "** Modifica usuari **" << endl;
        CtrlModificaUsuari ctrlModificaUsuari; //No pilla constructora       
        DTOUsuari infoU = ctrlModificaUsuari.consultaUsuari();

        cout<<"Nom complet: "<<infoU.obteNom()<<endl;
        cout<<"Sobrenom: "<<infoU.obteSobrenom()<<endl;
        cout<<"Correu electronic: "<<infoU.obteCorreu()<<endl;
        cout<<"Data naixement (DD/MM/AAAA): " << infoU.obteDataN()<<endl; 
        cout << "Modalitat subscripcio: " << infoU.obteModalitatS() << endl;

        cout << "Omplir la informació que es vol modificar ...";
        string nomU, contraU, correuU, subsU, neixU;
        
        cout << "Nom complet: ";
        getline(cin, nomU); 
        cout<<nomU<<endl;

        cout << "Contrasenya: ";
        getline(cin, contraU);
        cout<<contraU<<endl;

        cout << "Correu electronic: ";
        getline(cin, correuU);
        cout<<correuU<<endl;

        cout << "Data naixement (DD/MM/AAAA): ";
        cin >> neixU;
        cout<<neixU<<endl;

        cout << "Modalitat subscripcio: ";
        getline(cin, subsU);
        cout<<subsU<<endl;

        try {
            ctrlModificaUsuari.modificaUsuari(nomU, contraU, correuU, neixU, subsU);
            
            infoU = ctrlModificaUsuari.consultaUsuari();
            cout << "** Dades usuari modificades **" << endl;
            cout << "Nom complet: " << infoU.obteNom() << endl;
            cout << "Sobrenom: " << infoU.obteSobrenom() << endl;
            cout << "Correu electronic: " << infoU.obteCorreu() << endl;
            cout << "Data naixement (DD/MM/AAAA): " << infoU.obteDataN() << endl;
            cout << "Modalitat subscripcio: " << infoU.obteModalitatS() << endl;
        }
        catch(sql::SQLException& e){
            string errorMsg = e.what();
            if (e.getErrorCode() == 1062) { //error no es pot insertar per clau primaria o unique repetit
                if (errorMsg.find("correu_electronic") != string::npos) {
                    cout << "El nou correu electrònic ja existeix" << endl;
                }
            }
        }
            
        
}

//-------------------------------------------------------------------

void CapaDePresentacio::processarEsborraUsuari(){
    string contrasenyaU;
    cout << "** Esborrar usuari **" << endl;
    cout << "Per confirmar l'esborrat, s'ha d'entrar la contrasenya ... " << endl;
    cout << "Contrasenya: ";
    utils::desactivarEco(contrasenyaU); 
    utils::activarEco(); 
    TxEsborraUsuari txEsborraUsuari(contrasenyaU);
    try {
        txEsborraUsuari.executar();
        cout << endl << "Usuari esborrat correctament!" << endl;
    }
    catch (const exception& e) {
       cout << "La contrasenya no és correcta, l'usuari no s'esborrat!"  << endl;
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

}