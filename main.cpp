#include "capaDePresentacio.h"
using namespace std;
#include <locale>

void gestioUsuaris() {
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
    switch (op) {
        case 1: presentacio.consultarUsuari();break;
        case 2: presentacio.modificaUsuari();break;
        case 3: presentacio.esborraUsuari();break;
    }
}

void gestioContinguts() {
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
    switch (op) {
        case 1: presentacio.   ();break;
        case 2: presentacio.gestioSeries();break;
    }
}

void consultes() {
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
    switch (op) {
        case 1: presentacio.consultesEdat();break;
        case 2: presentacio.ultimesNovetats();break;
        case 3: presentacio.proximesEstrenes();break;
    }
}

int main() {
    int op;
    bool acaba=false;
    bool sessioIniciada = false;
    CapaDePresentacio& presentacio = CapaDePresentacio::getInstance();
    while (not acaba) {
        if(not sessioIniciada){
            wcout << "*********************" << endl;
            wcout << " Menu Principal" << endl;
            wcout << "*********************" << endl;
            wcout << "1. Iniciar sessió" << endl;
            wcout << "2. Registrar usuari" << endl;
            wcout << "3. Consultes" << endl;
            wcout << "4. Sortir" << endl;
            wcout << "Escriu opcio: ";
            cin >> op;
            switch (op) {
                case 1: presentacio.processarIniciarSessio();break;
                case 2: presentacio.processarRegistreUsuari();break;
                case 3: consultes();break;
                case 4: acaba=true; 
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
            switch (op) {
                case 1: gestioUsuaris();break;
                case 2: gestioContinguts();break;
                case 3: consultes();break;
                case 4: sessioIniciada=false; 
                case 5: acaba=true; 
                //default: wcout << "Opció no vàlida" << endl; CONSIDERAR
            }
        }
        // system("cls");
    }    
}



    