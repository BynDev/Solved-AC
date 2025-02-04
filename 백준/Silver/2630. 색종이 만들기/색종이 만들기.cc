#include <iostream>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include <vector>
#include<cmath>
using namespace std;

int white{0};
int blue{0};


void cut(int x,int y,int size,const vector<vector<int>>&v)
{
    bool clear {true};
    int chk {v[x][y]};
    for(int i = x; i < x + size; i++)
    {
        for(int j = y; j < y + size; j++)
        {
            if(chk != v[i][j])
            {
                clear = false;
            }
        }
    }
    if(!clear)
    {
        cut(x,y,size/2,v);
        cut(x + size/2,y,size/2,v);
        cut(x,y + size/2,size/2,v);
        cut(x + size/2,y + size/2,size/2,v);
    }
    else
    {
        if(v[x][y] == 1)
        {
            blue++;
        }
        else if(v[x][y] == 0)
        {
            white++;
        }
    }
}

int main()
{
    int N{0}; cin >> N;
    vector<vector<int>>v(N,vector<int>(N,0));
    for(int i = 0; i < N ;i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> v[i][j]; 
        }
    }
    cut(0,0,N,v);
    cout << white << endl;
    cout << blue << endl;
}