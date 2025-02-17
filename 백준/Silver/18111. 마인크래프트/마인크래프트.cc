#include <iostream>
#include <vector>
#include<cmath>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M; cin >> N >> M;
    long long B; cin >> B;

    vector<vector<int>>v(N,vector<int>(M,0));
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M ; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<int>height(257);
    for(int i = 0; i < 257; i++)
    {
        height[i] = i;
    }

    int mintime = numeric_limits<int>::max();
    int ansheight = 0;
    
    for(auto &h:height)
    {
        int inventory = B;
        int time {0};
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M ; j++)
            {
                if(v[i][j] < h)
                {
                    inventory -= (h - v[i][j]);
                    time += 1 * (h - v[i][j]);
                }
                else if(v[i][j] > h)
                {
                    inventory += (v[i][j] - h);
                    time += 2 * (v[i][j] - h);
                }
            }
        }
        if(inventory >= 0)
        {
            if(time <=mintime)
            {
                mintime = time;
                ansheight = h;
            }
        }
    }
    cout << mintime << " " << ansheight;
    
}
