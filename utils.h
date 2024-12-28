#ifndef UTILS_H
#define UTILS_H

#include <windows.h>
#include <string>
#include <iostream>
#include <limits>
#include <thread>  
#include <chrono>
#include <iomanip>  
#include <sstream>  
#include <ctime>
using namespace std;

namespace utils {

    // Reactiva el eco de la consola
    inline void activarEco() {
        HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
        DWORD originalMode;
        GetConsoleMode(hStdin, &originalMode);
        SetConsoleMode(hStdin, originalMode);
    }

    // Desactiva el eco y permite leer una entrada con asteriscos
    inline void desactivarEco(string& input) {
        HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
        DWORD originalMode;
        GetConsoleMode(hStdin, &originalMode);
        SetConsoleMode(hStdin, originalMode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

        input.clear();
        INPUT_RECORD record;
        DWORD events;
        while (true) {
            ReadConsoleInput(hStdin, &record, 1, &events);
            if (record.EventType == KEY_EVENT && record.Event.KeyEvent.bKeyDown) {
                char c = record.Event.KeyEvent.uChar.AsciiChar;
                if (c == '\r') { // Enter finaliza
                    //cout << endl;
                    break;
                }
                if (c == '\b' && !input.empty()) { // Backspace
                    input.pop_back();
                    cout << "\b \b"; // Borra el último asterisco
                }
                else if (isprint(c)) { // Caracter imprimible
                    input += c;
                    cout << '*'; // Muestra un asterisco
                }
            }
        }

        SetConsoleMode(hStdin, originalMode); // Restaura el modo original
    }

    //Esborra terminal
    inline void clearConsole() {
        system("cls"); // Windows command to clear the console
    }

    inline void espera(int miliseg) {
        this_thread::sleep_for(chrono::milliseconds(miliseg));
    }

    inline void missatgeAnimacio(const string& msg, int entreLletres) {
        for (char c : msg) {
            cout << c << flush; 
            espera(entreLletres);
        }
    }

    inline void enter() {
        cout << endl;
        missatgeAnimacio("Presiona ENTER per continuar... ", 25);
        cin.ignore(); 
        cin.get();
        clearConsole();
    }

    inline void ensenyaLogo() {
        clearConsole();
        missatgeAnimacio(" /$$$$$$$    /$$$$$$$$", 10);
        cout << endl;
        missatgeAnimacio("| $$__  $$  | $$_____/", 10);
        cout << endl;
        missatgeAnimacio("| $$  | $$  | $$", 10);
        cout << endl;
        missatgeAnimacio("| $$$$$$$/  | $$$$$", 10);
        cout << endl;
        missatgeAnimacio("| $$____/   | $$__/", 10);
        cout << endl;
        missatgeAnimacio("| $$        | $$", 10);
        cout << endl;
        missatgeAnimacio("| $$        | $$", 10);
        cout << endl;
        missatgeAnimacio("|__/        |__/", 10);
        espera(1500);
        clearConsole();
    }

    inline string dataActual() {
        // Obtener la fecha y hora actual
        time_t now = time(nullptr);
        tm* localTime = localtime(&now);

        // Formatear la fecha y hora en un string
        char buffer[20]; // YYYY-MM-DD HH:MM:SS = 19 caracteres + 1 para '\0'
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);

        return string(buffer);
    }

    inline string convertToDatetime(const string& data) {
        string year = data.substr(6, 4);  // Extrae el año
        string month = data.substr(3, 2); // Extrae el mes
        string day = data.substr(0, 2);   // Extrae el día

        return year + "-" + month + "-" + day;  // Devuelve en formato YYYY-MM-DD
    }

    inline string convertitADDMMYYYY(const string& data) {
        string year = data.substr(0, 4);  // "YYYY"
        string month = data.substr(5, 2); // "MM"
        string day = data.substr(8, 2);   // "DD"

        // Construir el formato "DD/MM/YYYY"
        return day + "/" + month + "/" + year;
    }

    inline string horaActual() {
        // Obtener la hora actual
        time_t tiempoActual = time(nullptr);
        tm* tiempoLocal = localtime(&tiempoActual);

        // Formatear la hora como HH:MM
        ostringstream horaStream;
        horaStream << setw(2) << setfill('0') << tiempoLocal->tm_hour << ":"
                   << setw(2) << setfill('0') << tiempoLocal->tm_min;
        return horaStream.str();
    }

    inline string dataAmbHora(const string& data) {
        // Verificar que el formato de entrada tenga al menos 19 caracteres
        if (data.size() < 19) {
            return "Formato inválido";
        }

        // Extraer las partes relevantes
        string any = data.substr(0, 4);
        string mes = data.substr(5, 2);
        string dia = data.substr(8, 2);
        string hora = data.substr(11, 5); // HH:MM

        // Formar el nuevo formato
        string resultado = dia + "/" + mes + "/" + any + " " + hora;

        return resultado;
    }

#pragma region Compara Dates
    inline string convertirAFormatoComparacion(string fecha) {
        string dia = fecha.substr(0, 2);   // "DD"
        string mes = fecha.substr(3, 2); // "MM"
        string any = fecha.substr(6, 4);  // "YYYY"

        return any + mes + dia;
    } 

    inline bool dataMesGran(string fecha1, string fecha2) {
        string data1 = convertirAFormatoComparacion(fecha1);
        string data2 = convertirAFormatoComparacion(fecha2);

        return data1 > data2;
    }

    inline bool dataMesPetit(string fecha1, string fecha2) {
        string data1 = convertirAFormatoComparacion(fecha1);
        string data2 = convertirAFormatoComparacion(fecha2);

        return data1 < data2;
    }

    inline bool dataIgual(string fecha1, string fecha2) {
        string data1 = convertirAFormatoComparacion(fecha1);
        string data2 = convertirAFormatoComparacion(fecha2);

        return data1 == data2;
    }
#pragma endregion

    inline bool esFormatDataValid2(string data) {
        // Verificar longitud exacta
        if (data.size() != 10) return false;

        // Verificar les barres
        if (data[2] != '/' || data[5] != '/') return false;

        // Verificar els altres caràcters siguin digits
        for (int i = 0; i < data.size(); ++i) {
            if (i != 2 && i != 5 && !isdigit(data[i])) {
                return false;
            }
        }
        return true;
    }

    inline bool esAnyDeTraspas(int any) {
        return (any % 4 == 0 && any % 100 != 0) || (any % 400 == 0);
    }

    inline bool esFormatDataValid(string data) {
        if (!esFormatDataValid2(data)) return false;

        // Extraer día, mes y año de la cadena
        int dia = stoi(data.substr(0, 2));
        int mes = stoi(data.substr(3, 2));
        int any = stoi(data.substr(6, 4));

        // Validar mes
        if (mes < 1 || mes > 12) return false;

        // Validar día según el mes
        int diesEnMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // Ajustar febrero para años bisiestos
        if (mes == 2 && esAnyDeTraspas(any)) {
            diesEnMes[1] = 29;
        }

        // Verificar día dentro del rango válido
        if (dia < 1 || dia > diesEnMes[mes - 1]) return false;

        return true; // La fecha es válida si pasa todas las comprobaciones
    }    
};
#endif