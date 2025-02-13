#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> friends(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        friends[a].push_back(b);
        friends[b].push_back(a); 
    }
    
    int answer = 0;
    int minSum = numeric_limits<int>::max();
    
    for (int i = 1; i <= N; i++) {
        vector<int> dist(N + 1, -1);
        queue<int> q;
        
        dist[i] = 0;
        q.push(i);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            for (int nxt : friends[cur]) {
                if (dist[nxt] == -1) { 
                    dist[nxt] = dist[cur] + 1;
                    q.push(nxt);
                }
            }
        }
        
        int sum = 0;
        for (int j = 1; j <= N; j++) {
            sum += dist[j];
        }
        
        if (sum < minSum) {
            minSum = sum;
            answer = i;
        }
    }
    
    cout << answer << "\n";
    return 0;
}