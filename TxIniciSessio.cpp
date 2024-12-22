#include "TxIniciSessio.h"


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

    if (contrasenya != _contrasenyaU) throw runtime_error("ErrorContrasenya");

    PetitFlix& petitFlix = PetitFlix::getInstance();
    petitFlix.iniciaSessio(u);
}