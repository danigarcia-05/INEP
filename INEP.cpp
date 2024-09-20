using namespace std;
#include <iostream>

void OPCIO1 (){
	cout << "1. Resgistre usuari" << endl;
	cout << "2. Consulta usuari " << endl;
	cout << "3. Modifica usuari" << endl;
	cout << "4. Borrar usuari" << endl;
	cout << "5. Tornar" << endl;
	string sobrenom, nom, cog1, cog2;
	int opcio2;
	cin >> opcio2;
	if (opcio2 == 1) {
		cout << "Escriu el teu sobrenom i nom complet" << endl;
		cin >> sobrenom >> nom >> cog1 >> cog2;
		cout << "El registre de l’usuari " << nom << " " << cog1 << " " << cog2 << " (" << sobrenom << ") s’ha processat correctament" << endl << endl;
	}
	if (opcio2 == 2) {
		cout << "El teu usuari és "<< endl << endl;
	}
	if (opcio2 == 3) {
		cout << "Escriu el teu nou usuari" << endl;
		cin >> sobrenom >> nom >> cog1 >> cog2;
		cout << endl;
	}
	if (opcio2 == 4) {
		cout << "El teu usuari s'ha esborrat correctament" << endl << endl;
	}
}

void OPCIO2() {
	cout << "1. Gestió pel·lícules" << endl;
	cout << "2. Gestió sèries" << endl;
	cout << "3. Tornar" << endl;
	int opcio2;
	cin >> opcio2;
	if (opcio2 == 1) {
		cout << "Gestió pel·lícules" << endl << endl;
	}
	if (opcio2 == 2) {
		cout << "Gestió sèries" << endl << endl;
	}
}

void OPCIO3() {
	cout << "1. Consulta per qualificació d'edat" << endl;
	cout << "2. Últimes novetats" << endl;
	cout << "3. Pròximes estrenes" << endl;
	cout << "4. Tornar" << endl;
	int opcio2;
	cin >> opcio2;
	if (opcio2 == 1) {
		cout << "Consulta per qualificació d'edat" << endl << endl;
	}
	if (opcio2 == 2) {
		cout << "Últimes novetats" << endl << endl;
	}
	if (opcio2 == 3) {
		cout << "Pròximes estrenes" << endl << endl;
	}
}


int main () {
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