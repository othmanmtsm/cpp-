#include <iostream>
using namespace std;

// class Adherent{
//     string nom,prenom,email;
//     int id;
//     static int cmp;
//     int *sSport = new int[5];
// public:
//     Adherent(string n,string p,string mail){

//     }

// };

// int Adherent::cmp = 0;


bool isMail(string s){
    bool at{false};
    bool sc{false};
    bool sc1{true};
    int test{0};
    int count{0};
    int atPos;

    for (auto c:s)
    {
        if ((c == '@')&&(count != 0)&&(count!=s.length()-1))
        {
            at = true;
            atPos = count;
        }
        count++;
    }

    for (int i = atPos+1; i < s.length(); i++)
    {
        if (s[i]=='.')
        {
            if ((i!=atPos+1)&&(i!=s.length()-1))
            {
                sc = true;
                
            }else
            {
                test++;
            }
            
        }
    }
    return at&&(sc&&(test==0));
}

int main(){
    string s = "@jhasdasd";
    cout << isMail(s);
}