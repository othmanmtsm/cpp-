#include <iostream>
#include "Point.h"

using namespace std;

Point::Point(){
    x=y=0;
}

Point::Point(float a,float b){
    x = a;
    y = b;
}

void Point::setP(float a, float b){
    x = a;
    y = b;
}
float Point::getX(){
    return x;
}
float Point::getY(){
    return y;
}
void Point::affiche(){
    cout << x << " - " << y << endl;
}