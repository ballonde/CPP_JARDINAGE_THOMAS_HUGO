#include "plante.cpp"
#include "botaniste.cpp"
#include "fleur.cpp"
#include "planteCarnivore.cpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main(){
    int choixActionJoueur;
    bool finAction=false;
    bool planteOccupe=true;

    plante planteActuelle("Fougère",100,5);

    plante * plante1 = new plante("Fougère",100,5);
    plante * plante2 = new plante("pepe",30,0);
    plante * plante3 = new plante("lala",60,3);

    fleur * lila = new fleur("lila",40,20);
    planteCarnivore * pyrana = new planteCarnivore("pyranah",20,5);


    vector<plante> plantePossedeBotaniste;
    botaniste * botaniste1 = new botaniste(plantePossedeBotaniste,100);
    botaniste1->acheterPlante();
    botaniste1->acheterPlante();

    cout<<"Argent:"<<botaniste1->getArgent()<<endl;
    cout<<"Engrais:"<<botaniste1->getNbEngrais()<<endl;
    cout<<"Plante:"<<botaniste1->getListePlante().size()<<endl;
    while (finAction==false){
    cout<<"Que voulez vous faire? Acheter de l'engrais (1)? Acheter une plante (2)? Vendre une plante (3)? Vous occupez de vos plante (4)? Dormir (5)?"<<endl; 
    cin>>choixActionJoueur;

        cout<<"Argent:"<<botaniste1->getArgent()<<endl;
        cout<<"Engrais:"<<botaniste1->getNbEngrais()<<endl;
        cout<<"Plante:"<<botaniste1->getListePlante().size()<<endl;

        if (choixActionJoueur==1){
            cout<<"Un engrais coûte 20, Acheter? oui (1), non (0)"<<endl;
            cin>>choixActionJoueur;
            if (choixActionJoueur==1){
                botaniste1->acheterEngrais();
            }
        }

        if (choixActionJoueur==2){
            cout<<"Une plante coûte 10, Acheter? oui (1), non (0)"<<endl;
            cin>>choixActionJoueur;
            if (choixActionJoueur==1){
                botaniste1->acheterPlante();
            }
        }

        if (choixActionJoueur==3){
            cout<<"Quelle plante vendre?"<<endl;
            for (auto &vec : botaniste1->getListePlante()){
                for (int i = 0; i < botaniste1->getListePlante().size(); ++i) {
                cout<<"voulez-vous vendre cette plante? oui (1), non (0)"<<endl;
                cin>>choixActionJoueur;
                if (choixActionJoueur==1){
                    botaniste1->vendrePlante(i);
                    }
                }
            }
        }

        if (choixActionJoueur==4){
            cout<<"Quelle plante vous occuper?"<<endl;
            for (auto &vec : botaniste1->getListePlante()){
                for (int i = 0; i < botaniste1->getListePlante().size(); ++i) {
                cout<<"voulez-vous vous occupez de cette plante? oui (1), non (0)"<<endl;
                cin>>choixActionJoueur;
                if (choixActionJoueur==1){
                    planteActuelle=vec;
                    while(planteOccupe==true){
                        cout<<"que voulez-vous vous faire? taille (1), arroser (2), mettre de l'engrais(3), inspecter(4), annuler(0)"<<endl;
                        cin>>choixActionJoueur;

                        if (choixActionJoueur==1){
                            cout<<"Vous prenez le temps de taillez votre plante."<<endl;
                            planteActuelle.taillePlante();
                        }
                        if (choixActionJoueur==2){
                            cout<<"Vous prenez le temps d'arroser'votre plante."<<endl;
                            planteActuelle.arroserPlante();
                        }
                        if (choixActionJoueur==3){
                            cout<<"Vous prenez le temps de mettre de l'engrais sur votre plante."<<endl;
                            planteActuelle.engraisPlante(botaniste1->getNbEngrais());
                        }
                        if (choixActionJoueur==4){
                            cout<<"Vous inspecter votre plante."<<endl;
                            planteActuelle.inspecterPlante();
                        }

                        if (choixActionJoueur==0){
                            cout<<"annuler"<<endl;
                            planteOccupe=false;
                            }
                        }
                    }
                }
            }
        }

        if (choixActionJoueur==5){
            cout<<"Vous choississez d'aller dormir, une journée passe."<<endl;
            botaniste1->dormir();
        }

    }
    return 0;
}