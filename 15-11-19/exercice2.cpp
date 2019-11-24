/**
    TP c++ , Exercice 2
    Objectif: une classe qui permet de représenter des cercles

    @author Motassim Othman - Malainine Ahmed
    15/11/19 
*/
#include <iostream>
#include <cmath>
using namespace std;

class Point{
    float x,y;
public:
    Point(){
        x=y=0;
    }
    Point(float a,float b){
        x = a;
        y = b;
    }
    void setP(float a, float b){
        x = a;
        y = b;
    }
    float getX(){
        return x;
    }
    float getY(){
        return y;
    }
    void affiche(){
        cout << x << " - " << y << endl;
    }
};

class Cercle{
    Point c;
    float r;
public:
    Cercle(Point p, float a){
        c.setP(p.getX(),p.getY());
        r = a;
    }
    float gerR(){
        return r;
    }
    void changeR(float a){
        r=a;
    }
    Point getCentre(){
        return c;
    }
    void changeC(Point a){
        c=a;
    }
    float getSurface(){
        return 3.14*pow(r,2);
    }
    float getPerimetre(){
        return 2*3.14*r;
    }
    bool egal(Cercle e){
        if ((r==e.r)&&((c.getX()==e.c.getX())&&(c.getY()==e.c.getY())))
        {
            return true;
        }
        return false;
    }
    int apparenceInOut(Point e){
        if ((pow(e.getX(),2)+pow(e.getY(),2)) == pow(r,2))
        {
            return 0;
        }else if((pow(e.getX(),2)+pow(e.getY(),2)) < pow(r,2))
        {
            return -1;
        }else
        {
            return 1;
        }
    }
    void affiche(){
        cout << "Le centre : ";
        c.affiche();
        cout << "Le rayon : " << r << endl;
    }
};

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