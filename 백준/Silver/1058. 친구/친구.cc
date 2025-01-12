#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

static const int MAX = 51;

vector<int>graph[MAX];
int N;

int friendsNum(int v)
{
    vector<bool> visited(MAX, false);
    vector<int> dist(MAX, 0);
    
    stack<int> s;
    visited[v] = true;
    dist[v] = 0;
    s.push(v);
    
    while(!s.empty()) {
        int cur = s.top();
        s.pop();
        
        if(dist[cur] == 2) continue;
        
        for(int next : graph[cur]) {
            if(!visited[next]) {
                visited[next] = true;
                dist[next] = dist[cur] + 1; 
                s.push(next);
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < N; i++) {
        if(i != v && visited[i] && dist[i] <= 2) {
            ans++;
        }
    }
    
    return ans;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i = 0; i < N ;i++)
    {
        string friends; cin >> friends;
        for(int j = 0; j < N; j++)
        {
            if(j != i)
            {
                if(friends[j] == 'Y')
                {
                    graph[i].push_back(j);
                }
            }
        }
    }
    int max {0};
    for(int v = 0; v < N;v++)
    {
        if(max < friendsNum(v))
        {
            max = friendsNum(v);
        }
    }
    cout << max;
}

//dfs로 다시