#include <iostream>
#include "Point.h"
#include "Cercle.h"
using namespace std;

int main(){
    Point p(10,10);
    Cercle c(p,1);
    c.affiche();
    cout << "Perimetre : " << c.getPerimetre() << endl << "Surface : " << c.getSurface() << endl;
    c.changeR(c.gerR()*2);
    cout << "Perimetre : " << c.getPerimetre() << endl << "Surface : " << c.getSurface() << endl;
    Point origin(0,0);
    c.changeC(origin);
    Point v(1,1);
    Point v2(3,3);
    cout << c.apparenceInOut(v) << endl;
    cout << c.apparenceInOut(v2) << endl;
    Point p1(0,0);
    Cercle c1(p1,2);
    cout << c.egal(c1) << endl;
}