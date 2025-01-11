#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include <cstring>

using namespace std;

static const int MAX = 1001;

vector<int>graph[MAX];
bool visited[MAX];

void dfs(int v)
{
    visited[v]=true;
    cout << v << " ";

    for (int next : graph[v])
    {
        if(!visited[next])
        {
            dfs(next);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    visited[start] = true; 
    q.push(start);

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";
        
        for (int next : graph[v]) {
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N,M,V; cin >> N >> M >> V;
    for(int i = 0; i < M; i++)
    {
        int n,m; cin >> n >> m;
        graph[n].push_back(m);
        graph[m].push_back(n);
    }
    for(int i = 1; i <= N; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(V);
    cout << "\n";
    
    memset(visited, false, sizeof(visited));
    bfs(V);
    cout << "\n";
}
