#ifndef FLEUR_H
#define FLEUR_H

#include "plante.h"
#include "fleur.h"
#include <string>
using namespace std;

class fleur: public plante{

    private:
    int _valeur;
    int jourDebutFleur;

    public:
        fleur(string nom, int sante,int maturite);
        void actualiserPlante();
        int getValeur();


};

#endif