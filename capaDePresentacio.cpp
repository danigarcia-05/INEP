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



void CapaDePresentacio::processarConsultaUsuari()
{
	TxConsultaUsuari txConsultaUsuari();
    txConsultaUsuari.executar();
    DTOUsuari resultat;
    resultat txConsultaUsuari.obteResultat();
    TxInfoVisualitzacions txInfoVisualitzacions();
    txInfoVisualitzacions.executar();

    struct Visualitzacions
    {
        int numVisualitzacioP;
        int numVisualitzacioS;
    };

    Visualitzacions vis = txInfoVisualitzacions.obteResultat();

    cout << "** Consulta usuari **" << endl;
    cout << "Nom Complet: " << resultat.obteNom() << endl;
    cout << "Sobrenom: " << resultat.obteSobrenom() << endl;
    cout << "Correu electronic: " << resultat.obteCorreu() << endl;
    cout << "Data naixement (DD/MM/AAAA): " << resultat.obteDataN() << endl;
    cout << "Modalitat subscripció: " << resultat.obteModalitatS() << endl;
    cout << endl;
    cout << vis.numVisualitzacioP << " pel·licules visualitzades" << endl;
    cout << vis.numVisualitzacioS << "  capitols visualitzats" << endl;
}

//-------------------------------------------------------------------

void CapaDePresentacio::processarModificaUsuari() {
		
        ConnexioBD connexio;
        cout << "** Modifica usuari **" << endl;
        CtrlModificaUsuari CtrlModificaUsuari();
        infoU = CtrlModificaUsuari.consultaUsuari();
        cout<<"Nom complet: "<<infoU.obteNom()<<endl;
        cout<<"Sobrenom: "<<infoU.obteSobrenom()<<endl;
        cout<<"Correu electronic: "<<infoU.obteCorreu()<<endl;
        cout<<"Data naixement (DD/MM/AAAA): "<<infoU.obteDataN()<<endl;
        cout<<"Modalitat subscripcio: "<<infoU.obteSubscripcio()<<endl;

        cout<<"Omplir la informació que es vol modificar ..."
        string nomU, contraU, correuU, subsU;
        
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
        getline(cin, neixU);
        cout<<neixU<<endl;

        //
        //s'ha de fer(modalitat subscripcio ha de ser vàlid)
        //
        cout << "Modalitat subscripcio: ";
        getline(cin, subsU);
        cout<<subS<<endl;

        CtrlModificaUsuari.modificaUsuari(nomU, contraU, correuU, neixU, subsU);
        //
        //excepció s'ha de fer(CorreuExisteix)
        //
        infoU = CtrlModificaUsuari.consultaUsuari();
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
