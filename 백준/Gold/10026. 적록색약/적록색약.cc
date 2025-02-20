#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

vector<int>dx = {1,-1,0,0};
vector<int>dy = {0,0,1,-1};

struct RGB
{
    int i;
    int j;
    char color;
};

int main(){

    int N; cin >> N;

    vector<vector<char>>grid(N,vector<char>(N,' '));
    vector<vector<char>>grid2(N,vector<char>(N,0));
    
    
    for(int i = 0; i < N;i++)
    {
        for(int j = 0; j < N;j++)
        {
            cin >> grid[i][j];
            grid2[i][j] = grid[i][j];
            if(grid[i][j] == 'R')
            {
                grid2[i][j] = 'G';
            }
        }
        
    }

    vector<vector<bool>>visited(N,vector<bool>(N,false));
    vector<vector<bool>>visited2(N,vector<bool>(N,false));
    int ans{0};
    int ans2{0};
    
    for(int i = 0; i < N ;i++)
    {
        for(int j = 0; j < N ;j++)
        {
            if(visited[i][j] == false)
            {
                ans++;
                queue<RGB>q;
                q.push({i,j,grid[i][j]});
                visited[i][j] = true;

                while(!q.empty())
                {
                    int now_i = q.front().i;
                    int now_j = q.front().j;
                    char now_color = q.front().color;
                    
                    q.pop();

                    for(int d = 0; d < 4; d++)
                    {
                        if(now_i + dx[d] >= 0 && now_i + dx[d] < N && now_j + dy[d] >= 0 && now_j + dy[d] < N)
                        {
                            if(visited[now_i + dx[d]][now_j + dy[d]] == false && grid[now_i + dx[d]][now_j + dy[d]] == now_color)
                            {
                                q.push({now_i + dx[d],now_j + dy[d],now_color});
                                visited[now_i + dx[d]][now_j + dy[d]] = true;
                            }
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < N ;i++)
    {
        for(int j = 0; j < N ;j++)
        {
            if(visited2[i][j] == false)
            {
                ans2++;
                queue<RGB>q;
                q.push({i,j,grid2[i][j]});
                visited2[i][j] = true;

                while(!q.empty())
                {
                    int now_i = q.front().i;
                    int now_j = q.front().j;
                    char now_color = q.front().color;
                    
                    q.pop();

                    for(int d = 0; d < 4; d++)
                    {
                        if(now_i + dx[d] >= 0 && now_i + dx[d] < N && now_j + dy[d] >= 0 && now_j + dy[d] < N)
                        {
                            if(visited2[now_i + dx[d]][now_j + dy[d]] == false && grid2[now_i + dx[d]][now_j + dy[d]] == now_color)
                            {
                                q.push({now_i + dx[d],now_j + dy[d],now_color});
                                visited2[now_i + dx[d]][now_j + dy[d]] = true;
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << " " << ans2;
    
    
    return 0;
}
