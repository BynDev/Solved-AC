#include <iostream>
#include<queue>
#include<algorithm>
#include <vector>
#include<cmath>
using namespace std;

const int MAX {101};
vector<int>network[MAX];
vector<bool>visited(MAX,false);

int bfs()
{
    queue<vector<int>>q;
    q.push(network[1]);
    visited[1] = true;

    int ans{0};

    while(!q.empty())
    {
        vector<int>v = q.front();
        q.pop();

        for(int i = 0; i < v.size();i++)
        {
            if(visited[v[i]] == false)
            {
                q.push(network[v[i]]);
                visited[v[i]] = true;
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N; cin >> N;
    int pairs; cin >> pairs;

    for(int i = 0; i < pairs; i++)
    {
        int com1,com2; cin >> com1 >> com2;
        network[com1].push_back(com2);
        network[com2].push_back(com1);
    }

    cout << bfs();
    
}