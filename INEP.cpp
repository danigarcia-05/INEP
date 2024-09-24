using namespace std;
#include <iostream>
#include <string>
#include <sstream>

void registrarUsuari() {
	cin.ignore();
	cout << "Escriu el teu sobrenom i nom complet" << endl;
	string s;
	getline(cin, s);  
	string sobrenom, nom, cog1, cog2;
	stringstream ss(s);
	if (ss >> sobrenom >> nom >> cog1 >> cog2) cout << "El registre de l’usuari " << nom << " " << cog1 << " " << cog2 << " (" << sobrenom << ") s’ha processat correctament" << endl << endl;
	else cout << "Error al registrar usuari" << endl<< endl;
}
void consultarUsuari() {
	cout << "El teu usuari és ..... ..... ..... ....." << endl << endl;
}
void modificarUsuari() {
	cin.ignore();
	cout << "Escriu el teu nou usuari (sobrenom i nom complet)" << endl;
	string s;
	getline(cin, s);
	string sobrenom, nom, cog1, cog2;
	stringstream ss(s);
	if (ss >> sobrenom >> nom >> cog1 >> cog2) cout << "El registre de l’usuari " << nom << " " << cog1 << " " << cog2 << " (" << sobrenom << ") s’ha processat correctament" << endl << endl;
	else cout << "Error al registrar usuari" << endl << endl;
}
void borrarUsuari() {
	cout << "El teu usuari s'ha esborrat correctament" << endl << endl;
}

void gestioPelicules() {
	cout << "Gestió pel·lícules" << endl << endl;
}
void gestioSeries() {
	cout << "Gestió sèries" << endl << endl;
}

void consultesEdat() {
	cout << "Consulta per qualificació d'edat" << endl << endl;
}
void ultimesNovetats() {
	cout << "Últimes novetats" << endl << endl;
}
void proximesEstrenes() {
	cout << "Pròximes estrenes" << endl << endl;
}

//______________________________________________________________
//______________________________________________________________

void OPCIO1 (){
	cout << "1. Resgistre usuari" << endl;
	cout << "2. Consulta usuari " << endl;
	cout << "3. Modifica usuari" << endl;
	cout << "4. Borrar usuari" << endl;
	cout << "5. Tornar" << endl;
	int opcio2;
	cin >> opcio2;
	if (opcio2 == 1) registrarUsuari();
	if (opcio2 == 2) consultarUsuari();
	if (opcio2 == 3) modificarUsuari();
	if (opcio2 == 4) borrarUsuari();
}

void OPCIO2() {
	cout << "1. Gestió pel·lícules" << endl;
	cout << "2. Gestió sèries" << endl;
	cout << "3. Tornar" << endl;
	int opcio2;
	cin >> opcio2;
	if (opcio2 == 1) gestioPelicules();
	if (opcio2 == 2) gestioSeries();
}

void OPCIO3() {
	cout << "1. Consulta per qualificació d'edat" << endl;
	cout << "2. Últimes novetats" << endl;
	cout << "3. Pròximes estrenes" << endl;
	cout << "4. Tornar" << endl;
	int opcio2;
	cin >> opcio2;
	if (opcio2 == 1) consultesEdat();
	if (opcio2 == 2) ultimesNovetats();
	if (opcio2 == 3) proximesEstrenes();
}

int main () {
	//Pablo Martín Martín
	int opcio;
	bool acaba = false;
	while (not acaba) {
		cout << "1. Gestió usuaris" << endl;
		cout << "2. Gestió continguts" << endl;
		cout << "3. Consultes" << endl;
		cout << "4. Sortir" << endl;
		cin >> opcio;
		if (opcio == 1) OPCIO1();
		else if (opcio == 2) OPCIO2();
		else if (opcio == 3) OPCIO3();
		else if (opcio == 4) acaba = true;
	}
}