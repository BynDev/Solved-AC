#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<pair<int, int>>> graph(N+1);
    for (int i = 0; i < M; i++) {
        int s, e, cost;
        cin >> s >> e >> cost;
        graph[s].push_back({e, cost});
    }
    
    int start, end;
    cin >> start >> end;
    
    const long long INF = 1e15;
    vector<long long> dist(N+1, INF);
    dist[start] = 0;
    
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();
        
        if (cost != dist[cur]) continue;
        
        for (auto &edge : graph[cur]) {
            int next = edge.first;
            int nextCost = edge.second;
            
            if (dist[next] > cost + nextCost) {
                dist[next] = cost + nextCost;
                pq.push({dist[next], next});
            }
        }
    }
    
    cout << dist[end] << "\n";
    
    return 0;
}