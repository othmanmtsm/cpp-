#include <iostream>
using namespace std;

class Vector3D{
    int x,y,z;
public:
    Vector3D(int a,int b,int c){
        x = a;
        y = b;
        z = c;
    }
    friend bool coincide(Vector3D,Vector3D);
};

bool coincide(Vector3D v1,Vector3D v2){
    return (v1.x==v2.x)&&(v1.y==v2.y)&&(v1.z==v2.z);
}

int main(){
    Vector3D p1(0,0,0);
    Vector3D p2(0,1,0);
    cout << coincide(p1,p2);
}