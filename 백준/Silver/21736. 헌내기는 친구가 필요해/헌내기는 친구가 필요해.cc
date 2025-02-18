#include <iostream>
#include<string>
#include<queue>
using namespace std;

vector<int>dx = {1,-1,0,0};
vector<int>dy = {0,0,1,-1};

int bfs(vector<vector<char>>campus,int N, int M, pair<int,int>start)
{
    int ans {0};
    vector<vector<bool>>visited(N,vector<bool>(M,false));
    queue<pair<int,int>>q;
    q.push(start);
    visited[start.first][start.second] = true;
    
    while(!q.empty())
    {
        int now_i = q.front().first;
        int now_j = q.front().second;
        q.pop();

        for(int d = 0; d < 4; d++)
        {
            if(now_i-dx[d] >= 0 && now_i-dx[d] < N && now_j-dy[d] >= 0 && now_j-dy[d] < M  )
            {
                if(campus[now_i-dx[d]][now_j-dy[d]] == 'P' && visited[now_i-dx[d]][now_j-dy[d]] == false)
                {
                    q.push({now_i-dx[d],now_j-dy[d]});
                    visited[now_i-dx[d]][now_j-dy[d]] = true;
                    ans++;
                }
                else if(campus[now_i-dx[d]][now_j-dy[d]] == 'O' && visited[now_i-dx[d]][now_j-dy[d]] == false)
                {
                    q.push({now_i-dx[d],now_j-dy[d]});
                    visited[now_i-dx[d]][now_j-dy[d]] = true;
                }
            }
        }
    }

    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M; cin >> N >> M;

    vector<vector<char>>campus(N,vector<char>(M));
    pair<int,int>start;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> campus[i][j];
            if(campus[i][j] == 'I')
            {
                start = {i,j};
            }
        }
    }
    int ans = bfs(campus,N,M,start);
    if(ans == 0)
    {
        cout << "TT";
    }
    else
    {
        cout << ans;
    }
}
