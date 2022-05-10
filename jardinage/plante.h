#ifndef PLANTE_H
#define PLANTE_H

#include <string>
using namespace std;

class plante {

    protected:
    string _nom;
    int _hydratation;
    int _sante;

    int _maturite;
    int _taille;
    bool _engrais;

    int _jours;

    string _etat;



    public:
        plante(string nom, int sante,int maturite);
        void taillePlante();
        void engraisPlante(int nbEngrais);
        void arroserPlante();
        void inspecterPlante();
        void actualiserPlante();

        string getEtatPlante();


};

#endif