#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> dx = {1, -1, 0, 0, 0, 0};
vector<int> dy = {0, 0, 1, -1, 0, 0};
vector<int> dz = {0, 0, 0, 0, 1, -1};

struct Tomato {
    int z;
    int y;
    int x;
};

int main()
{
    int M, N, H;
    cin >> M >> N >> H;
    
    vector<vector<vector<int>>> basket(H, vector<vector<int>>(N, vector<int>(M, 0)));
    
    for (int z = 0; z < H; z++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                cin >> basket[z][y][x];
            }
        }
    }
    
    queue<Tomato> q;
    
    for (int z = 0; z < H; z++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (basket[z][y][x] == 1) {
                    q.push({z, y, x});
                }
            }
        }
    }
    
    while (!q.empty()) {
        int nowZ = q.front().z;
        int nowY = q.front().y;
        int nowX = q.front().x;
        q.pop();
        
        for (int d = 0; d < 6; d++) {
            int nz = nowZ + dz[d];
            int ny = nowY + dy[d];
            int nx = nowX + dx[d];
            
            if (nx >= 0 && nx < M && ny >= 0 && ny < N && nz >= 0 && nz < H) {
                if (basket[nz][ny][nx] == 0) {
                    basket[nz][ny][nx] = basket[nowZ][nowY][nowX] + 1;
                    q.push({nz, ny, nx});
                }
            }
        }
    }
    
    int ans = 0;
    bool complete = true;

    for (int z = 0; z < H; z++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (basket[z][y][x] == 0) {
                    complete = false;
                }
                ans = max(ans, basket[z][y][x]);
            }
        }
    }
    
    if (!complete)
        cout << -1;
    else
        cout << ans - 1;
    
    return 0;
}