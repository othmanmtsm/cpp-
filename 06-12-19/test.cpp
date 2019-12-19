#include <iostream>
using namespace std;

class Vehicule{
    string matricule="AVION";
public:
    string getMatricule(){
        return matricule;
    }
    void affiche(){
        cout << matricule;
    }
};

int main(){
    Vehicule v;
    v.getMatricule()[0] = 'B';
    v.affiche();
}