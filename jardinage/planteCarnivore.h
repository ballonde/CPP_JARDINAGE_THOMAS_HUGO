#ifndef PLANTECARNIVORE_H
#define PLANTECARNIVORE_H

#include "plante.h"
#include "planteCarnivore.h"
#include <string>
using namespace std;

class planteCarnivore: public plante{

    private:
    bool _digereMouche;
    int _digestion;

    public:
        planteCarnivore(string nom, int sante,int maturite);
        void actualiserPlante();
        void inspecterPlante();


};

#endif