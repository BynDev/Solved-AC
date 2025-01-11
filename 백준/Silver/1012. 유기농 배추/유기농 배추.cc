#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int BFS(vector<vector<int>>& field, int startY, int startX, int N, int M) {
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    
    queue<pair<int, int>> q;
    q.push({startY, startX});
    field[startY][startX] = 0; 

    while (!q.empty()) {
        auto [y, x] = q.front();
        q.pop();
        
        for (int d = 0; d < 4; ++d) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            if (ny >= 0 && ny < N && nx >= 0 && nx < M && field[ny][nx] == 1) {
                field[ny][nx] = 0; 
                q.push({ny, nx});
            }
        }
    }
    return 1; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        int M, N, K;
        cin >> M >> N >> K;
        
        vector<vector<int>> field(N, vector<int>(M, 0));
      
        for (int i = 0; i < K; ++i) {
            int X, Y;
            cin >> X >> Y;
            field[Y][X] = 1;
        }
        
        int wormCount = 0;
       
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < M; ++x) {
                if (field[y][x] == 1) { 
                    wormCount += BFS(field, y, x, N, M);
                }
            }
        }
        cout << wormCount << "\n";
    }
    
    return 0;
}