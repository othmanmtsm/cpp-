/**
    Stones game , exercice6.cpp
    Objectif: La gestion des etudiants

    @author Motassim Othman
    01/11/19 
*/
#include <iostream>
#include <ctime>
#include <conio.h>
using namespace std;

struct Player
{
    int type;
    string name;
    bool turn{false};
    int *historique = new int[1];
    int numturns{0};
    bool isWinner{false};
};

int cailloux;
Player players[2];

void checkWinner(Player &p1, Player &p2)
{

    if (p1.turn)
    {
        p1.isWinner = true;
    }
    else
    {
        p2.isWinner = true;
    }
}

void initialiser(int nc, Player &player)
{
    cailloux = nc;
    player.turn = true;
}

void utilisateur_joue(Player &p, int dif)
{

    int nap;

    if (dif == 0)
    {
        do
        {
            do
            {
                cout << "How many stones would u want to pick ? " << endl;
                cin >> nap;
            } while ((nap < 1 || nap > 3));
        } while (nap > cailloux);
    }
    else if (dif == 1)
    {
        clock_t start = clock();
        do
        {
            do
            {

                cout << "How many stones would u want to pick ? " << endl;
                cout << "You have 3 seconds to pick " << endl;

                while (!_kbhit()) //Check for keyboard hit
                {
                    //Check if 3 sec timer expired or not
                    if (((clock() - start) / CLOCKS_PER_SEC) >= 3)
                    {
                        cout << "salina" << endl;
                        nap = 1;
                        goto lkhr;
                    }
                }
                cin >> nap;
            } while ((nap < 1 || nap > 3));
        } while (nap > cailloux);
    }

lkhr:

    cailloux -= nap;
    p.numturns++;
    p.historique = (int *)realloc(p.historique, sizeof(int) * (p.numturns));
    p.historique[p.numturns - 1] = nap;
    p.turn = false;
}

void machine_joue(Player &m, int dif)
{
    int nap;
    if (dif == 0)
    {
        do
        {
            nap = 1 + rand() % 3;
        } while (nap > cailloux);
        cailloux -= nap;
        cout << m.name << " took " << nap << " Stones " << endl;
    }
    else if (dif == 1)
    {
        if ((cailloux - 1) % 4 != 0 && cailloux > 1)
        {
            do
            {
                do
                {
                    nap = 1 + rand() % 3;
                } while (nap > cailloux);
            } while (((cailloux - nap) - 1) % 4 != 0);
        }
        else
        {
            do
            {
                nap = 1 + rand() % 3;
            } while (nap > cailloux);
        }
        cailloux -= nap;
        cout << m.name << " took " << nap << " Stones " << endl;
    }
    m.numturns++;
    m.historique = (int *)realloc(m.historique, sizeof(int) * (m.numturns));
    m.historique[m.numturns - 1] = nap;
    m.turn = false;
}

void showMenu()
{
    cout << "=======================================================================================================" << endl;
    cout << "==================================== Welcome to the game ! ============================================" << endl;
    cout << "=======================================================================================================" << endl;
    cout << "   'Play a game against AI'                  === 1 - Player vs AI                                      " << endl;
    cout << "   'Play a game against another player'      ==== 2 - Player vs Player                                 " << endl;
    cout << "   'Watch two smart machines play'           ===== 3 - AI vs AI                                        " << endl;
    cout << "=======================================================================================================" << endl;
    cout << "                                       Press 0 to exit                                                 " << endl;
    cout << "=======================================================================================================" << endl;
}

void play(Player &plyr1, Player &plyr2, int dif = -1)
{
    int nc, fp;
    cout << "Player 1's name : " << endl;
    cin >> plyr1.name;
    cout << "Player 2's name : " << endl;
    cin >> plyr2.name;
    do
    {
        cout << "Specify the number of stones" << endl;
        cin >> nc;
    } while (nc < 1);

    do
    {
        cout << "Specify first player to play " << endl;
        cout << "1 - " << plyr1.name << endl;
        cout << "2 - " << plyr2.name << endl;
        cin >> fp;
    } while (fp < 1 || fp > 2);

    switch (fp)
    {
    case 1:
        initialiser(nc, plyr1);
        break;
    case 2:
        initialiser(nc, plyr2);
        break;
    }
    players[0] = plyr1;
    players[1] = plyr2;
    while (cailloux > 0)
    {
        for (int i = 0; i < 2; i++)
        {
            if (players[i].turn)
            {
                if (players[i].type == 0)
                {
                    if (i == 0)
                    {
                        players[1].turn = true;
                    }
                    else
                    {
                        players[0].turn = true;
                    }

                    cout << "============================ " << players[i].name << "'s turn : ================================" << endl;
                    cout << "number of stones available : " << cailloux << endl;
                    utilisateur_joue(players[i], dif);
                    if (cailloux == 0)
                        break;
                }
                else
                {
                    if (i == 0)
                    {
                        players[1].turn = true;
                    }
                    else
                    {
                        players[0].turn = true;
                    }
                    cout << "============================ " << players[i].name << "'s turn : ================================" << endl;
                    cout << "number of stones available : " << cailloux << endl;
                    machine_joue(players[i], dif);
                    if (cailloux == 0)
                        break;
                }
            }
        }
    }
    if (cailloux == 0)
    {
        checkWinner(players[0], players[1]);
    }
    for (int i = 0; i < 2; i++)
    {
        if (players[i].isWinner)
        {
            cout << "=======================================================================================================" << endl;
            cout << "\t\tThe winner is : " << players[i].name << endl;
            cout << "=======================================================================================================" << endl;
        }
    }
}

int main()
{
    srand(time(NULL));
    Player winner;
    int nc;
    int fp;
    int choice;

    do
    {
        showMenu();
        cin >> choice;
    } while (choice < 0 || choice > 3);

    switch (choice)
    {
    case 1:
    {
        Player plyr;
        plyr.type = 0;
        Player mchn;
        mchn.type = 1;
        int dif;
        do
        {
            cout << "Chose difficuly \n0 - Easy \n1 - Hard" << endl;
            cin >> dif;
        } while (dif < 0 || dif > 1);
        play(plyr, mchn, dif);
        break;
    }
    case 2:
    {
        Player plyr1;
        plyr1.type = 0;
        Player plyr2;
        plyr2.type = 0;
        play(plyr1, plyr2);
        break;
    }
    case 3:
    {
        Player ai1;
        ai1.type = 1;
        Player ai2;
        ai2.type = 1;
        int dif;
        do
        {
            cout << "Chose difficulty \n0 - Easy \n1 - Hard" << endl;
            cin >> dif;
        } while (dif < 0 || dif > 1);
        play(ai1, ai2, dif);
        break;
    }
    }
}