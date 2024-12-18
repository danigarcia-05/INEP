#include "capaDeDomini.h"
#include "PassarelaUsuari.h"

CapaDeDomini* CapaDeDomini::getInstance(){
    if (ins == nullptr) {
        ins = new CapaDeDomini();
    }
    return ins;
}

CapaDeDomini* CapaDeDomini::ins = nullptr;

void CapaDeDomini::registrarUsuari(string sobrenomU, string nomU, string correuU){
    PassarelaUsuari usuari(sobrenomU, nomU, correuU);
    usuari.inserta();
}

DTOUsuari CapaDeDomini::consultaUsuari(string sobrenom) {
    CercadoraUsuari cerca;
    PassarelaUsuari usu = cerca.cercaPerSobrenom(sobrenom);
    return DTOUsuari(usu);
}
