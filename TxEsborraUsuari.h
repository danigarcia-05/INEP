#ifndef TXESBORRAUSUARI_HPP
#define TXESBORRAUSUARI_HPP
#pragma once

#include <string>

class TxEsborraUsuari {
private:
    string contrau; 

public:
    
    TxEsborraUsuari();

    void crear(const string& contrau);
    void executar();
};

#endif
