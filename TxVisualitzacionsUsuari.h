#ifndef TXVISUALITZACIONSUSUARI_H
#define TXVISUALITZACIONSUSUARI_H
#pragma once
#include "TxConsultaUsuari.h"
#include "TxConsultaVisualitzacioPelicula.h"
#include "TxConsultaPelicula.h"
#include "TxConsultaContingut.h"
#include "TxConsultaUsuari.h"
#include "TxConsultaVisualitzacioCapitol.h"
#include "PassarelaUsuari.h"
#include "PassarelaVisualitzaPel.h"
#include "PassarelaVisualitzaCapitol.h"
#include <vector>

class TxVisualitzacionsUsuari {
public:
    TxVisualitzacionsUsuari();

    void executar();
    vector<DTOVisualitzacioPelicula> obteVisualitzacionsPelicula() const;
    vector<DTOVisualitzacioCapitol> obteVisualitzacionsCapitol() const;

private:
    vector<DTOVisualitzacioPelicula> _peliculaDTO;
    vector<DTOVisualitzacioCapitol> _capitolDTO;
};

#endif
