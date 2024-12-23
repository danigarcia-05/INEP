#ifndef UTILS_H
#define UTILS_H

#include <windows.h>
#include <string>
#include <iostream>
#include <limits>
#include <thread>  
#include <chrono> 
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

    inline void missatgeAnimacio(const std::string& msg, int entreLletres) {
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

    
};

#endif
