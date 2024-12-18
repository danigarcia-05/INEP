#pragma once
#ifndef TXINFOVISUALITZACIONS_HPP
#define TXINFOVISUALITZACIONS_HPP

class TxInfoVisualitzacions {
private:
    //Acabar de mirar el resultat!! No se nom :/
    struct resultat{
        int x;
        int y;
    };

public:
    TxInfoVisualitzacions();

    void crear();
    void executar();
    int obteResultat() const;
};

#endif
