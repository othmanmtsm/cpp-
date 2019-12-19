#include <iostream>
#include <cmath>
#include "Point.h"
#include "Cercle.h"
using namespace std;

Cercle::Cercle(Point p, float a)
{
    c.setP(p.getX(), p.getY());
    r = a;
}
float Cercle::gerR()
{
    return r;
}
void Cercle::changeR(float a)
{
    r = a;
}
Point Cercle::getCentre()
{
    return c;
}
void Cercle::changeC(Point a)
{
    c = a;
}
float Cercle::getSurface()
{
    return 3.14 * pow(r, 2);
}
float Cercle::getPerimetre()
{
    return 2 * 3.14 * r;
}
bool Cercle::egal(Cercle e)
{
    if ((r == e.r) && ((c.getX() == e.c.getX()) && (c.getY() == e.c.getY())))
    {
        return true;
    }
    return false;
}
int Cercle::apparenceInOut(Point e)
{
    if ((pow(e.getX(), 2) + pow(e.getY(), 2)) == pow(r, 2))
    {
        return 0;
    }
    else if ((pow(e.getX(), 2) + pow(e.getY(), 2)) < pow(r, 2))
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
void Cercle::affiche()
{
    cout << "Le centre : ";
    c.affiche();
    cout << "Le rayon : " << r << endl;
}