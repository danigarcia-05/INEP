#include "CapaDePresentacio.h"
#include "utils.h"

void gestioUsuaris() {
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    int op;
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
    utils::clearConsole();
    switch (op) {
        case 1: presentacio.processarConsultaUsuari(); 
            break;
        case 2: presentacio.processarModificaUsuari(); 
            break;
        case 3: presentacio.processarModificaContrasenya(); 
            break;
        case 4: presentacio.processarEsborraUsuari(); 
            break;
        case 5: break;
        default: cout << "Error: Opció no vàlida" << endl;
            gestioUsuaris();
            break;   
    }
}

void gestioContinguts() {
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    int op;
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
    switch (op) {
        case 1: presentacio.processarVisualitzarPelicula();
            break;
        case 2: presentacio.processarVisualitzarCapitol();
            break;
        case 3: presentacio.processarConsultarVisualitzacions();
            break;
        case 4: break;
        default: cout << "Error: Opció no vàlida" << endl;
            gestioContinguts();
            break;    
    }
}

void consultes() {
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    int op;
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
    switch (op) {
        case 1: presentacio.processarProperesEstrenes();break;
        case 2: presentacio.processarUltimesNovetats();break;
        case 3: presentacio.processarPeliculesMesVistes();break;
        case 4: break;
        default: cout << "Error: Opció no vàlida" << endl;
            consultes();
            break;    
    }
}

int main() {
    std::locale::global(std::locale("ca_ES.utf8"));
    std::cout.imbue(std::locale()); // Aplicar la configuración a std::cout
    std::cout.imbue(std::locale()); // Aplicar la configuración a std::cout
    PetitFlix& petitFlix = PetitFlix::getInstance();
    int op;
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
            switch (op) {
                case 1: presentacio.processarIniciarSessio(); 
                    break;
                case 2: presentacio.processarRegistreUsuari();
                    break;
                case 3:  consultes();
                    break;
                case 4:  acaba = true;  break;
                default: cout << "Error: Opció no vàlida" << endl;
                    break;  
            }
        }
        else{
            cout << "*********************" << endl;
            cout << " Menu Principal" << endl;
            cout << "*********************" << endl;
            cout << "1. Gestió usuaris" << endl;
            cout << "2. Visualitzar" << endl;
            cout << "3. Consultes" << endl;
            cout << "4. Tancar sessió" << endl;
            cout << "5. Sortir" << endl;
            cout << "Escriu opció: ";
            cin >> op;
            utils::clearConsole();
            switch (op) {
                case 1: gestioUsuaris();break;
                case 2: gestioContinguts();break;
                case 3: consultes();break;
                case 4: presentacio.processarTancaSessio(); break;
                case 5: acaba = true;  break;
                default: cout << "Error: Opció no vàlida" << endl;
                    break;  
            }
        }
    }    
}



    