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
    cout << endl << "Sobrenom: ";
    cin >> sU;
    cout << endl <<  "Contrasenya: ";
    utils::desactivarEco();
    cin >> cU;
    utils::activarEco();
    cout << endl << "Correu Electrònic: ";
    cin >> ceU;
    cout << endl << "Data naixement (DD/MM/AAAA): ";
    string data;
    cin>>data;
    
    string dia = data[0]+data[1];
    string mes = data[3]+data[4];
    string any = data[6]+data[7]+data[8]+data[9];
    
    dnU = utils::convertirData(dia, mes, any);
    cout << endl << "Modalitats de subscripció disponibles ";
    cout << endl << " > 1. Completa ";
    cout << endl << " > 2. Cinèfil ";
    cout << endl << " > 3. Infantil ";
    cout << endl << "Escull modalitat: ";
    cin >> msU;

    switch (msU) {
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
        cout << "Usuari registrat correctament!" << endl;
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

void CapaDePresentacio::processarConsultaUsuari()
{
	TxConsultaUsuari txConsultaUsuari;
    txConsultaUsuari.executar();
    DTOUsuari resultat;
    resultat = txConsultaUsuari.obteResultat();
    TxInfoVisualitzacions txInfoVisualitzacions;
    txInfoVisualitzacions.executar();

    pair<int, int> vis = txInfoVisualitzacions.obteResultat();;

    cout << "** Consulta usuari **" << endl;
    cout << "Nom Complet: " << resultat.obteNom() << endl;
    cout << "Sobrenom: " << resultat.obteSobrenom() << endl;
    cout << "Correu electronic: " << resultat.obteCorreu() << endl;
    cout << "Data naixement (DD/MM/AAAA): " << resultat.obteDataN() << endl; 
    cout << "Modalitat subscripció: " << resultat.obteModalitatS() << endl;
    cout << endl;
    cout << vis.first << " pel·licules visualitzades" << endl;
    cout << vis.second << "  capitols visualitzats" << endl;
}

void CapaDePresentacio::processarModificaUsuari() {
        cout << "** Modifica usuari **" << endl;
        CtrlModifica ctrlModificaUsuari; //No pilla constructora
        DTOUsuari infoU = ctrlModificaUsuari.consultaUsuari();
        cout<<"Nom complet: "<<infoU.obteNom()<<endl;
        cout<<"Sobrenom: "<<infoU.obteSobrenom()<<endl;
        cout<<"Correu electronic: "<<infoU.obteCorreu()<<endl;
        cout<<"Data naixement (DD/MM/AAAA): " << infoU.obteDataN()<<endl; 
        cout<<"Modalitat subscripcio: "<<infoU.obteSubscripcio()<<endl;

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

        /*cout << "Data naixement (DD/MM/AAAA): ";
        getline(cin, neixU);
        cout<<neixU<<endl;*/

        //
        //s'ha de fer(modalitat subscripcio ha de ser vàlid)
        //
        cout << "Modalitat subscripcio: ";
        getline(cin, subsU);
        cout<<subS<<endl;

        //CtrlModificaUsuari.modificaUsuari(nomU, contraU, correuU, neixU, subsU); 
        //
        //excepció s'ha de fer(CorreuExisteix)
        //
        DTOUsuari infoU(ctrlModificaUsuari.consultaUsuari());
        cout<<"Nom complet: "<<infoU.obteNom()<<endl;
        cout<<"Sobrenom: "<<infoU.obteSobrenom()<<endl;
        cout<<"Correu electronic: "<<infoU.obteCorreu()<<endl;
        cout<<"Data naixement (DD/MM/AAAA): "<<infoU.obteDataN()<<endl; 
        cout<<"Modalitat subscripcio: "<<infoU.obteSubscripcio()<<endl;
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

void CapaDePresentacio::processarUltimesNovetats(){
    cout << "HOla" << endl;
}

void CapaDePresentacio::processarProperesEstrenes(){
     cout << "HOla" << endl;
}

void CapaDePresentacio::processarPeliculesMesVistes(){
     cout << "HOla" << endl;
}