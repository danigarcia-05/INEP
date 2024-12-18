#include "capaDeDomini.h"
#include "PassarelaUsuari.h"
#include "CercadoraUsuari.h"

CapaDeDomini* CapaDeDomini::getInstance(){
    if (ins == nullptr) {
        ins = new CapaDeDomini();
    }
    return ins;
}

CapaDeDomini* CapaDeDomini::ins = nullptr;

bool CapaDeDomini::iniciarSessio(string sobrenomU, string contrasenyaU){
    CercadoraUsuari cerca;
    PassarelaUsuari usu = cerca.cercaPerSobrenom(sobrenomU);
    if (usu.sobrenom=="") cout<<"Error en iniciar sessio"<<endl;
    else {
        if (usu.contrasenya==contrasenyaU) cout<<"Sessio iniciada correctament!"<<endl;
        else cout<<"Error en iniciar sessio"<<endl;
    }    
}


void CapaDeDomini::registrarUsuari(string sobrenomU, string nomU, string correuU){
    PassarelaUsuari usuari(sobrenomU, nomU, correuU);
    usuari.inserta();
}

DTOUsuari CapaDeDomini::consultaUsuari(string sobrenom) {
    CercadoraUsuari cerca;
    PassarelaUsuari usu = cerca.cercaPerSobrenom(sobrenom);
    return DTOUsuari(usu);
}
