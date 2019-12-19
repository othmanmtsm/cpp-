#include <iostream>
using namespace std;

class Matrice;
class Vect{
    double x,y,z;
public:
    Vect(double a=0,double b=0,double c=0){
        x = a;
        y = b;
        z = c;
    }
    void affiche(){
        cout << x << " - " << y << " - " << z << endl;
    }
    friend Vect prod(Matrice,Vect);
};

class Matrice{
    double matrice[3][3];
public:
    Matrice(double m[3][3]){
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; i++)
            {
                matrice[i][j] = m[i][j];
            }
        }
    }
    friend Vect prod(Matrice,Vect);
};

Vect prod(Matrice m,Vect v){
    Vect temp;
    double x{0},y{0},z{0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; i++)
        {
            if (j == 0)
            {
                x += m.matrice[i][j]*v.x;
            }
            if (j == 1)
            {
                y += m.matrice[i][j]*v.y;
            }
            if (j == 2)
            {
                z += m.matrice[i][j]*v.z;
            }
        }
    }
    temp.x = x;
    temp.y = y;
    temp.z = z;
    return temp;
}

int main(){
    double tab[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; i++)
        {
            tab[i][j] = 1;
        }
    }
    
    
}