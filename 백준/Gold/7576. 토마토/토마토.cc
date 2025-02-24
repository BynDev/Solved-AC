#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Tomato
{
    int i;
    int j;
    int day;
};
vector<int>dx = {1,-1,0,0};
vector<int>dy = {0,0,1,-1};

int main()
{
    int M,N; cin >> M >> N;
    vector<vector<int>>Basket(N,vector<int>(M,0));
    vector<Tomato>start;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> Basket[i][j];
            if(Basket[i][j] == 1)
            {
                start.push_back({i,j,0});
            }
        }
    }

    queue<Tomato>q;
    for(auto &i : start)
    {
        q.push(i);
    }
    int max{0};
    while(!q.empty())
    {
        int now_i = q.front().i;
        int now_j = q.front().j;
        int now_day = q.front().day;
        q.pop();

        if(max < now_day)
        {
            max = now_day;
        }

        for(int d = 0; d < 4; d++)
        {
            if(now_i + dx[d] >= 0 && now_i + dx[d] < N && now_j + dy[d] >= 0 && now_j + dy[d] < M)
            {
                if(Basket[now_i + dx[d]][now_j + dy[d]] == 0)
                {
                    Basket[now_i + dx[d]][now_j + dy[d]] = 1;
                    q.push({now_i + dx[d],now_j + dy[d], now_day + 1});
                }
            }
        }
    }
    bool clear {true};
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(Basket[i][j] == 0)
            {
                clear = false;
            }
        }
    }
    if(clear == true)
    {
        cout << max;
    }
    else
    {
        cout << -1;
    }
    
}