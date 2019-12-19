#include <iostream>
using namespace std;

class Vehicule{
    string matricule,type,date_sortie;
public:
    string & getMatricule(){
        return matricule;
    }
    string getType(){
        return type;
    }
    string getDateS(){
        return date_sortie;
    }
    void setType(string t){
        type = t;
    }
    void Saisie(){
        cout << "Matricule ?" << endl;
        cin >> matricule;
        cout << "Type ?" << endl;
        cin >> type;
        cout << "Date sortie ?" << endl;
        cin >> date_sortie;
    }
    void affichage(){
        cout << "Vehicule : " << matricule << endl;
        cout << "Type : " << type << endl;
        cout << "date sortie : " << date_sortie << endl;
    }
};

class Personne{
    string nom,CIN,anne_naissance;
    int nbVehicule{0};
    Vehicule *vhs;
public:
    Personne(){
        vhs = new Vehicule[1];
    }
    void saisiePersonne(){
        cout << "Nom ?" << endl;
        cin >> nom;
        cout << "CIN ?" << endl;
        cin >> CIN;
        cout << "Anne de naissance ?" << endl;
        cin >> anne_naissance;
    }
    void ajouterVehicule(){
        Vehicule v;
        v.Saisie();
        if (nbVehicule == 0)
        {
            vhs[0] = v;
        }else
        {
            Vehicule *tmp = new Vehicule [nbVehicule];
            delete vhs;
            Vehicule *vhs = new Vehicule [nbVehicule+1];
            for (int i = 0; i < nbVehicule; i++)
            {
                vhs[i] = tmp[i];
            }
            vhs[nbVehicule] = v;
        }     
    }
    void afficher(){
        cout << "Nom : " << nom << endl;
        cout << "CIN : " << CIN << endl;
        cout << "Annee de naissance : " << anne_naissance;
        for (int i = 0; i < nbVehicule; i++)
        {
            vhs[i].affichage();
        }
    }
    Vehicule *getVhs(){
        return vhs;
    }
    int getNbvhs(){
        return nbVehicule;
    }
};

int main(){
    Personne *personnes = new Personne[6];
    for (int i = 0; i < 6; i++)
    {
        personnes[i].saisiePersonne();
    }
    
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            personnes[i].ajouterVehicule();
        }
    }

    for (int i = 0; i < 6; i++)
    {
        personnes[i].afficher();
    }


    cout << "========================== MOTO ============================" << endl;

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (personnes[i].getVhs()[j].getType() == "Moto")
            {
                personnes[i].afficher();
            } 
        }
    }
    
    cout << "========================== MARRAKECH ============================" << endl;


    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if ((personnes[i].getVhs()[j].getMatricule()[1] == '2') && (personnes[i].getVhs()[j].getMatricule()[2] == '6')){
                personnes[i].afficher();
            }
        }
    }

    cout << "========================== Voitures enregistre ============================" << endl;
    int nbv{0};
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < personnes[i].getNbvhs(); j++)
        {
            if (personnes[i].getVhs()[j].getType() == "voiture")
            {
                nbv++;
            }
        }
    }
    cout << "Le nombre de voitures enregistre" << nbv;

    cout << "========================== AB ============================" << endl;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < personnes[i].getNbvhs(); j++)
        {
            for (int k=0; k < personnes[i].getVhs()[j].getMatricule().length();k++)
            {
                if (personnes[i].getVhs()[j].getMatricule()[k] == 'A')
                {
                    cout << personnes[i].getVhs()[j].getMatricule()[k] << endl;
                    personnes[i].getVhs()[j].getMatricule()[k] = 'B';
                }
                
            }
        }
    }

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < personnes[i].getNbvhs(); j++)
        {
            personnes[i].getVhs()[j].affichage();
        }
    }
}