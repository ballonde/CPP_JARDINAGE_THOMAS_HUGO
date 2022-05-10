#ifndef BOTANISTE_H
#define BOTANISTE_H

#include "plante.h"
#include <vector>
#include <string>
using namespace std;

class botaniste {

    private:
    vector<plante> _plantePossede;
    int _argent;

    int _nbEngrais;



    public:
        botaniste(vector<plante> plantePossede,int argent);
        void dormir();
        void acheterPlante();
        void vendrePlante(int nbCasePlante);
        void acheterEngrais();
        int getNbEngrais();
        int getArgent();
        vector<plante> getListePlante();
        plante getListePlanteElement(int i);


};

#endif