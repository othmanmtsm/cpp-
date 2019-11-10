/**
    TP Exercice 16 , ex.cpp
    Objectif: La gestion des etudiants

    @author Motassim Othman - Malainine Ahmed
    09/11/19 
*/
#include <iostream>
#include <string.h>
using namespace std;

struct Etudiant
{
    string nom;
    string prenom;
    float notes[4];
};

void saisieEtudiant(Etudiant &e)
{
    cout << "nom ??" << endl;
    cin >> e.nom;
    cout << "prenom ??" << endl;
    cin >> e.prenom;
    for (int i = 0; i < 4; i++)
    {
        cout << "Donnez la note " << i + 1 << endl;
        cin >> e.notes[i];
    }
}

void afficherEtudiant(Etudiant &e)
{
    cout << "Le nom d'etudiant est : " << e.nom << endl;
    cout << "Le prenom d'etudiant est : " << e.prenom << endl;
    cout << "Les notes de l'etudiant sont : " << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << e.notes[i] << "\t";
    }
    cout << endl;
}

float getMoyenne(float notes[4])
{
    float somme{0};
    for (int i = 0; i < 4; i++)
    {
        somme += notes[i];
    }
    return somme / 4;
}

float getMax(float notes[4])
{
    float max = notes[0];
    for (int i = 0; i < 4; i++)
    {
        if (notes[i] > max)
        {
            max = notes[i];
        }
    }
    return max;
}

float getMin(float notes[4])
{
    float min = notes[0];
    for (int i = 0; i < 4; i++)
    {
        if (notes[i] < min)
        {
            min = notes[i];
        }
    }
    return min;
}

bool estAdmis(Etudiant &e)
{
    return getMoyenne(e.notes) >= 10;
}

Etudiant *addStudent(Etudiant *e, int &size)
{
    Etudiant et;
    saisieEtudiant(et);
    Etudiant *t2 = new Etudiant[size + 1];
    for (int i = 0; i < size; i++)
    {
        t2[i] = e[i];
    }
    t2[size] = et;
    delete e;
    size++;
    return t2;
}

int rechercheEtudiant(Etudiant *e, string nom, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (e[i].nom == nom)
        {
            return i;
        }
    }
    return -1;
}

Etudiant *supprimerEtudiant(Etudiant *e, string nom, int &size)
{
    Etudiant *t2 = new Etudiant[size - 1];
    if (rechercheEtudiant(e, nom, size) != -1)
    {
        e[rechercheEtudiant(e, nom, size)] = e[size - 1];
        for (int i = 0; i < size - 1; i++)
        {
            t2[i] = e[i];
        }
    }
    delete e;
    --size;
    return t2;
}

int main()
{
    int size{2};
    Etudiant *t = new Etudiant[size];
    for (int i = 0; i < size; i++)
    {
        saisieEtudiant(t[i]);
    }
    for (int i = 0; i < size; i++)
    {
        afficherEtudiant(t[i]);
    }
    cout << "Ajouter Etudiant au tableau" << endl;
    t = addStudent(t, size);
    t = addStudent(t, size);
    cout << "Liste apres l'ajout" << endl;
    for (int i = 0; i < size; i++)
    {
        afficherEtudiant(t[i]);
    }
    t = supprimerEtudiant(t, "othman", size);
    cout << "Liste apres suppression" << endl;
    for (int i = 0; i < size; i++)
    {
        afficherEtudiant(t[i]);
    }
}