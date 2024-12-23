#include "CapaDePresentacio.h"
#include "utils.h"


void gestioUsuaris() {
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    string op;
    cout << "------------------" << endl;
    cout << " Gestionar usuari" << endl;
    cout << "------------------" << endl;
    cout << "1. Consulta usuari" << endl;
    cout << "2. Modifica usuari" << endl;
    cout << "3. Modifica contrasenya" << endl;
    cout << "4. Esborra usuari" << endl;
    cout << "5. Tornar" << endl;
    cout << "Escriu opció: ";
    cin >> op;
    cout << endl;
    utils::clearConsole();
    if (op == "1") presentacio.processarConsultaUsuari(); 
    else if (op == "2") presentacio.processarModificaUsuari(); 
    else if (op == "3") presentacio.processarModificaContrasenya(); 
    else if (op == "4") presentacio.processarEsborraUsuari();
    else if (op != "5") {
        cout << "Error: Opció no vàlida" << endl;
        utils::enter();
        gestioUsuaris();       
    }
}

void gestioContinguts() {
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    string op;
    cout << "------------------" << endl;
    cout << " Visualitzar" << endl;
    cout << "------------------" << endl;
    cout << "1. Visualitzar pel·lícula" << endl;
    cout << "2. Visualitzar capítol" << endl;
    cout << "3. Consultar visualitzacions" << endl;
    cout << "4. Tornar" << endl;
    cout << "Escriu opció: ";
    cin >> op;
    cout << endl;
    if(op == "1") presentacio.processarVisualitzarPelicula(); 
    else if(op == "2") presentacio.processarVisualitzarCapitol();
    else if(op == "3") presentacio.processarConsultarVisualitzacions();
    else if(op != "4"){
        cout << "Opció no vàlida" << endl;
        utils::enter();
        gestioContinguts();
    } 
}

void consultes() {
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    string op;
    cout << "------------------" << endl;
    cout << " Consultes" << endl;
    cout << "------------------" << endl;
    cout << "1. Properes estrenes" << endl;
    cout << "2. Últimes novetats" << endl;
    cout << "3. Pel·lícules més vistes" << endl;
    cout << "4. Tornar" << endl;
    cout << "Escriu opció: ";
    cin >> op;
    cout << endl;

    if(op == "1") presentacio.processarProperesEstrenes(); 
    else if(op == "2") presentacio.processarUltimesNovetats();
    else if(op == "3") presentacio.processarPeliculesMesVistes();
    else if(op != "4"){
        cout << "Opció no vàlida" << endl;
        utils::enter();
        consultes();
    } 
}

int main() {
    std::locale::global(std::locale("ca_ES.utf8"));
    std::cout.imbue(std::locale()); // Aplicar la configuración a std::cout
    std::cout.imbue(std::locale()); // Aplicar la configuración a std::cout
    
    utils::ensenyaLogo();

    PetitFlix& petitFlix = PetitFlix::getInstance();
    string op;
    bool acaba = false;
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    while (acaba == false) {
        if(petitFlix.obteUsuari() == nullptr){
            cout << "*********************" << endl;
            cout << " Menu Principal" << endl;
            cout << "*********************" << endl;
            cout << "1. Iniciar sessió" << endl;
            cout << "2. Registrar usuari" << endl;
            cout << "3. Consultes" << endl;
            cout << "4. Sortir" << endl;
            cout << "Escriu opció: ";
            cin >> op;
            utils::clearConsole();
            if(op == "1") presentacio.processarIniciarSessio(); 
            else if(op == "2") presentacio.processarRegistreUsuari();
            else if(op == "3") consultes();
            else if(op == "4") acaba = true;
            else{
               cout << "Opció no vàlida" << endl; 
               utils::enter();
            } 
        }
        else{
            cout << "*********************" << endl;
            cout << " Menú Principal" << endl;
            cout << "*********************" << endl;
            cout << "1. Gestió usuaris" << endl;
            cout << "2. Visualitzar" << endl;
            cout << "3. Consultes" << endl;
            cout << "4. Tancar sessió" << endl;
            cout << "5. Sortir" << endl;
            cout << "Escriu opció: ";
            cin >> op;
            utils::clearConsole();
            if (op == "1") gestioUsuaris();
            else if (op == "2") gestioContinguts();
            else if (op == "3") consultes();
            else if (op == "4") presentacio.processarTancaSessio();
            else if (op == "5") acaba = true;
            else{
               cout << "Opció no vàlida" << endl; 
               utils::enter();
            } 
        }
    }
    utils::ensenyaLogo();   
}



    