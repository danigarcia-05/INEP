#ifndef TXESBORRAUSUARI_HPP
#define TXESBORRAUSUARI_HPP
#pragma once

#include <string>

class TxEsborraUsuari {
private:
    string _contraU; 

public:
    
    TxEsborraUsuari(string contraU);

    void executar();
};

#endif
