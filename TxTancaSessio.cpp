#include "TxTancaSessio.h"
#include "PetitFlix.h"

TxTancaSessio::TxTancaSessio(){
    
}

//Destructor
TxTancaSessio::~TxTancaSessio(){
}

void TxTancaSessio::executar(){
   PetitFlix& petitFlix = PetitFlix::getInstance();
   petitFlix.tancaSessio();
}