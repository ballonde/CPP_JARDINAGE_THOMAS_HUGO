#ifndef BOTANISTE_CPP
#define BOTANISTE_CPP

#include "botaniste.h"
#include "plante.h"
#include "fleur.h"
#include "planteCarnivore.h"
#include <iostream>
#include <string>
using namespace std;


    botaniste::botaniste(vector<plante> plantePossede,int argent){
        _plantePossede=plantePossede;
        _argent=argent;
        _nbEngrais=0;
    }

    void botaniste::dormir(){
        for (auto &vec : _plantePossede) {
            for (int i = 0; i < _plantePossede.size(); ++i) {
                vec.actualiserPlante();
            }
        }
    }

    void botaniste::acheterPlante(){
        int choix;
        cout<<"Quelle plante acheter? Plante 10(1) Fleur 20(2) Plante Carnivore 30(3) ou annuler (0)"<<endl;
        cin>>choix;
        if (choix==1 && _argent>=10){
            _argent=_argent-10;
            plante * plante1 = new plante("Fougère",100,5);
            _plantePossede.push_back(*plante1);
            cout<<"Vous avez acheté une plante!"<<endl;
        }
        if (choix==2 && _argent>=20){
            _argent=_argent-20;
            fleur * plante1 = new fleur("lila",40,20);
            _plantePossede.push_back(*plante1);
            cout<<"Vous avez acheté une plante!"<<endl;
        }
        if (choix==3&& _argent>=30){
            _argent=_argent-30;
            planteCarnivore * plante1 = new planteCarnivore("Pyranah",30,5);
            _plantePossede.push_back(*plante1);
            cout<<"Vous avez acheté une plante!"<<endl;
        }
    }

    void botaniste::vendrePlante(int nbCasePlante){
        for (auto &vec : _plantePossede) {
            for (int i = 0; i < _plantePossede.size(); ++i) {
                if (i==nbCasePlante){
                    if (vec.getEtatPlante()=="mature"){
                        _argent=_argent+30;
                        auto elem_to_remove = _plantePossede.begin() + nbCasePlante;
                        _plantePossede.erase(elem_to_remove);
                        cout<<"Vous avez vendu une plante et gagné 30!"<<endl;
                    }else{
                        cout<<"La plante n'est pas assez mature!"<<endl;
                    }
                }
            }
        }
    }

    void botaniste::acheterEngrais(){
        if(_argent>=20){ 
            _argent=_argent-20;
            _nbEngrais=_nbEngrais+1;
        }else{
            cout<<"Vous n'avez pas assez d'argent."<<endl;
        }
    }

    int botaniste::getNbEngrais(){
        return _nbEngrais;
    }

    int botaniste::getArgent(){
        return _argent;
    }

    vector<plante> botaniste::getListePlante(){
        return _plantePossede;
    }

#endif