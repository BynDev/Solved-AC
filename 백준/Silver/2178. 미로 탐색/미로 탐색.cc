#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <vector>
using namespace std;

const int MAX = 101;
int matrix[MAX][MAX];             
bool visited[MAX][MAX] = {0};     
int distance_arr[MAX][MAX] = {0}; 

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int bfs(int N,int M)
{
    queue<pair<int,int>>q;
    visited[1][1] = true;
    distance_arr[1][1] = 1;
    q.push({1,1});
    
    while(!q.empty())
    {
        auto [y, x] = q.front();
        q.pop();

        if(x == M && y ==N)
        {
            return distance_arr[y][x];
        }
        
        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 1 || ny > N || nx < 1 || nx > M) continue;
            
            if(!visited[ny][nx] && matrix[ny][nx] == 1){
                visited[ny][nx] = true;
                distance_arr[ny][nx] = distance_arr[y][x] + 1;
                q.push({ny, nx});
            }

        }
    }
    return -1;
}

int main() {
    int N,M; cin >> N >> M;

    for (int i = 1; i <= N; ++i) {
        string line;
        cin >> line; 
        for (int j = 1; j <= M; ++j) {
            if(line[j-1] == '1')
            {
                matrix[i][j] = 1;
            }
        }
    }

    cout << bfs(N, M) << "\n";
    return 0;
}

