#include <stdexcept>
#include <iostream>
using namespace std;
#include "TxIniciSessio.h"
#include "CercadoraUsuari.h"
#include "PassarelaUsuari.h"
#include "PetitFlix.h"

TxIniciSessio::TxIniciSessio(string sU, string cU)
{
    _sobrenomU = sU;
    _contrasenyaU = cU;
}
//Destructor
TxIniciSessio::~TxIniciSessio(){
}

void TxIniciSessio::executar()
{
    CercadoraUsuari cercadora;
    PassarelaUsuari u = cercadora.cercaUsuari(_sobrenomU);
    string contrasenya = u.obteContrasenya();

    //HAY QUE MIRAR COMO SE MANEJAN LOS ERRORES
    if (contrasenya != _contrasenyaU)
        throw runtime_error("ErrorContrasenya");

    PetitFlix& petitFlix = PetitFlix::getInstance();
    petitFlix.iniciaSessio(u);
}