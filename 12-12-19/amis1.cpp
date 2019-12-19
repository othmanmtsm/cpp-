#include <iostream>
#include <cmath>
using namespace std;

class Cercle;

class Point{
    int x;
    int y;
public:
    Point(int a=0,int b=0){
        x = a;
        y = b;
    }
    void affiche(){
        cout << x << " - " << y << endl;
    }
    friend float calculDistance(Point, Point);
    friend class Cercle;
};

// float calculDistance(Point p1, Point p2){
//     return sqrt(pow(p1.x-p2.x , 2) + pow(p1.y-p2.y , 2));
// }

class Cercle{
    Point centre;
    float rayon;
public:
    Cercle(Point c, float r){
        rayon = r;
        centre = c;
    }
    void affiche(){
        cout << "Rayon : " << rayon << endl;
        cout << "x = " << centre.x << endl << "y = " << centre.y << endl;
    }
    bool isMember(Point p){
        return sqrt(pow(p.x-centre.x , 2) + pow(p.y-centre.y , 2)) == rayon;
    }
};

int main(){
    Point pa(1,2);
    Point pb(4,3);
    Cercle c(pa,5);
    c.affiche();
}