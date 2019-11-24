/**
    TP c++ , Exercice 1
    Objectif: une classe qui gère un ensemble d’entiers

    @author Motassim Othman - Malainine Ahmed
    15/11/19 
*/

#include <iostream>
using namespace std;

class Ensemble{
    int *en;
    int position{0};
public:
    Ensemble(int n){
        en = new int[n];
    }
    void empty(){
        position = 0;
    }
    void add(int n){
        en[position++] = n;
    }
    void remove(int n){
        int index;
        while (isMember(n))
        {
            for (int i = 0; i < position; i++)
            {
                if (en[i]==n)
                {
                    index = i;
                }
            }
            en[index] = en[position-1];
            position--;
        }
    }
    bool isMember(int n){
        bool test{false};
        for (int i = 0; i < position; i++)
        {
            if (en[i]==n)
            {
                test = true;
            }
        }
        return test;
    }
    void copy(Ensemble e){
        if (position == e.position)
        {
            for (size_t i = 0; i < position; i++)
            {
                en[i]=e.en[i];
            }
        }
    }
    bool isEqual(Ensemble e){
        if (position == e.position)
        {
            for (int i = 0; i < position; i++)
            {
                if (en[i] != e.en[i])
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
    void print(){
        for (int i = 0; i < position; i++)
        {
            cout << en[i] << endl;
        }
    }
};

int main(){
    Ensemble e(5);
    Ensemble e1(4);
    e.add(1);
    e.add(2);
    e.add(9);
    e1.add(1);
    e1.add(2);
    e1.add(3);
    cout << e.isEqual(e1);
}