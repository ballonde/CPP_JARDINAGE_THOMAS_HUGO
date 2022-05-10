#ifndef PLANTECARNIVORECARNIVORE_CPP

#include "plante.h"
#include "planteCarnivore.h"
#include <iostream>
#include <string>
using namespace std;

    planteCarnivore::planteCarnivore(string nom, int sante,int maturite):plante(nom, sante,maturite){
        _digestion=0;
        _digereMouche=false;
    }

    void planteCarnivore::inspecterPlante(){
        cout<<"Espèce:"<<_nom<<endl;
        cout<<"Hydratation:"<<_hydratation<<endl;
        cout<<"Santé:"<<_sante<<endl;
        cout<<"Maturité:"<<_maturite<<endl;
        cout<<"Manger:"<<_digereMouche<<endl;
    }
    void planteCarnivore::actualiserPlante(){
        if (_taille>50){
            _sante=_sante-10;
        }
        if (_hydratation>70){
            _sante=_sante-10;
        }
        if (_sante<20){
            _maturite=_maturite-1;
        }
        if (_sante>80){
            _maturite=_maturite+1;
        }
        if (_engrais==true){
            _maturite=_maturite+1;
        }
        _maturite=_maturite+1;

        if (_maturite<=15){
            _etat="mature";
        }
        if(_digereMouche==true){
            _digestion=_digestion+1;
        }

        if(_digestion>=7){
            _digestion=0;
            _digereMouche=false;
        }

        if (_sante<=0){
            _etat="mort";
        }
        _jours=_jours+1;
    }

#endif