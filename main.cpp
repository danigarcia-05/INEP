#include "CapaDePresentacio.h"
#include "PetitFlix.h"
#include "connexioDB.h"
using namespace std;
#include <locale>

void gestioUsuaris() {
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    int op;
    wcout << "------------------" << endl;
    wcout << " Gestionar usuari" << endl;
    wcout << "------------------" << endl;
    wcout << "1. Consulta usuari" << endl;
    wcout << "2. Modifica usuari" << endl;
    wcout << "3. Modifica contrasenya" << endl;
    wcout << "4. Esborra usuari" << endl;
    wcout << "5. Tornar" << endl;
    wcout << "Escriu opció: ";
    cin >> op;
    cout << endl;
    switch (op) {
        case 1: presentacio.processarConsultaUsuari(); 
            break;
        case 2: presentacio.processarModificaUsuari(); 
            break;
        case 3: presentacio.processarModificaContrasenya(); 
            break;
        case 4: presentacio.processarBorrarUsuari(); 
            break;
        case 5: break;
        default: wcout << "Error: Opció no vàlida" << endl;
            gestioUsuaris();
            break;   
    }
}

void gestioContinguts() {
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    int op;
    wcout << "------------------" << endl;
    wcout << " Visualitzar" << endl;
    wcout << "------------------" << endl;
    wcout << "1. Visualitzar pel·lícula" << endl;
    wcout << "2. Visualitzar capítol" << endl;
    wcout << "3. Consultar visualitzacions" << endl;
    wcout << "4. Tornar" << endl;
    wcout << "Escriu opció: ";
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
        default: wcout << "Error: Opció no vàlida" << endl;
            gestioContinguts();
            break;    
    }
}

void consultes() {
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    int op;
    wcout << "------------------" << endl;
    wcout << " Consultes" << endl;
    wcout << "------------------" << endl;
    wcout << "1. Properes estrenes" << endl;
    wcout << "2. Últimes novetats" << endl;
    wcout << "3. Pel·lícules més vistes" << endl;
    wcout << "4. Tornar" << endl;
    wcout << "Escriu opció: ";
    cin >> op;
    cout << endl;
    switch (op) {
        case 1: presentacio.processarProperesEstrenes();break;
        case 2: presentacio.processarUltimesNovetats();break;
        case 3: presentacio.processarPeliculesMesVistes();break;
        case 4: break;
        default: wcout << "Error: Opció no vàlida" << endl;
            consultes();
            break;    
    }
}

int main() {
    PetitFlix& petitFlix = PetitFlix::getInstance();
    int op;
    bool acaba = false;
    bool sessioIniciada = false;
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    while (acaba == false) {
        if(petitFlix.obteUsuari() == nullptr){
            wcout << "*********************" << endl;
            wcout << " Menu Principal" << endl;
            wcout << "*********************" << endl;
            wcout << "1. Iniciar sessió" << endl;
            wcout << "2. Registrar usuari" << endl;
            wcout << "3. Consultes" << endl;
            wcout << "4. Sortir" << endl;
            wcout << "Escriu opcio: ";
            cin >> op;
            cout << endl;
            switch (op) {
                case 1: presentacio.processarIniciarSessio();
                    break;
                case 2: presentacio.processarRegistreUsuari();
                    break;
                case 3: consultes();
                    break;
                case 4: acaba = true; 
                default: wcout << "Error: Opció no vàlida" << endl;
                    break;  
            }
        }
        else{
            wcout << "*********************" << endl;
            wcout << " Menu Principal" << endl;
            wcout << "*********************" << endl;
            wcout << "1. Gestió usuaris" << endl;
            wcout << "2. Visualitzar" << endl;
            wcout << "3. Consultes" << endl;
            wcout << "4. Tancar sessió" << endl;
            wcout << "5. Sortir" << endl;
            wcout << "Escriu opcio: ";
            cin >> op;
            cout << endl;
            switch (op) {
                case 1: gestioUsuaris();break;
                case 2: gestioContinguts();break;
                case 3: consultes();break;
                case 4: presentacio.processarTancaSessio(); 
                case 5: acaba = true; 
                default: wcout << "Error: Opció no vàlida" << endl;
                    break;  
            }
        }
        // system("cls");
    }    
}



    