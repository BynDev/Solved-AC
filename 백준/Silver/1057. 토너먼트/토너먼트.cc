#include<iostream>
#include<cmath>
using namespace std;

int  main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    int Jimin;
    int Hansu;

    cin >> N >> Jimin >> Hansu;
    int Play {0};

    while(Jimin != Hansu)
    {
        Jimin = floor((Jimin+1)/2);
        Hansu = floor((Hansu+1)/2);
        Play++;
    }
    cout << Play;
}