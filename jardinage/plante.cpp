#ifndef PLANTE_CPP
#define PLANTE_CPP

#include "plante.h"
#include "botaniste.h"
#include <iostream>
#include <string>
using namespace std;

    plante::plante(string nom, int sante,int maturite){
        _nom=nom;
        _sante=sante;
        _maturite=maturite;
        _hydratation=50;
        _engrais=false;
        _taille=0;
        _etat="pousse";
        _jours=0;
    }

    void plante::taillePlante(){
        _taille=_taille+10;
   }

    void plante::engraisPlante(int nbEngrais){
        if (nbEngrais>0){
            if (_engrais==false){
                _engrais=true;
            }else{
                cout<<"La plante à déja recus de l'engrais"<<endl; 
            }
        }else{
            cout<<"Vous n'avez pas assez d'engrais."<<endl; 
        }
   }

    void plante::arroserPlante(){
       _hydratation=_hydratation+10;
   }

    void plante::inspecterPlante(){
        cout<<"Espèce:"<<_nom<<endl;
        cout<<"Hydratation:"<<_hydratation<<endl;
        cout<<"Santé:"<<_sante<<endl;
        cout<<"Maturité:"<<_maturite<<endl;
    }
    void plante::actualiserPlante(){
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

        if (_sante<=0){
            _etat="mort";
        }
        _jours=_jours+1;
    }

    string plante::getEtatPlante(){
        return _etat;
    }

#endif