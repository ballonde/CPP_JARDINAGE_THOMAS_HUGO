#ifndef FLEUR_CPP
#define FLEUR_CPP

#include "fleur.h"
#include "plante.h"
#include "plante.cpp"
#include "botaniste.h"
#include <iostream>
#include <string>
using namespace std;

    fleur::fleur(string nom, int sante,int maturite):plante(nom, sante,maturite){
        _valeur=1;
        jourDebutFleur=0;
    }

    void fleur::actualiserPlante(){
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

        if (_maturite<=25){
            _etat="fleur";
        }

        if (_etat=="fleur"){
            _valeur=2;
            jourDebutFleur=_jours;
        }

        if (_etat=="fleur" && jourDebutFleur!=0){
            jourDebutFleur=jourDebutFleur+1;
            if(jourDebutFleur>10){
                _etat=="fanée";
            }
        }

        if (_etat=="fleur"){
            _valeur=2;
        }

        if (_etat=="fanée"){
            _valeur=-10;
        }

        if (_sante<=0){
            _etat="mort";
        }
        _jours=_jours+1;
    }

    int fleur::getValeur(){
        return _valeur;
    }

#endif