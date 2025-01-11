#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

vector<int>graph[1001];
vector<bool>visited(1001,false);

int dfs(int v)
{
    queue<int>q;
    q.push(v);
    visited[v] = true;

    while(!q.empty())
    {
        int curr = q.front();
        q.pop();

        for(auto& i : graph[curr])
        {
            if(visited[i] != true)
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M; cin >> N >> M;

    for(int i = 0 ; i < M; i++)
    {
        int u,v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int ans{0};
    for(int i = 1; i <= N; i++) // 정점 번호를 순회해야 함
    {
        if(!visited[i])
        {
            ans += dfs(i);
        }
    }
    cout << ans;
    
    return 0;
}