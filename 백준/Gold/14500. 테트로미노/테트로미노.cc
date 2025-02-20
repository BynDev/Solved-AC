#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N, M;
vector<vector<int>> grid;
vector<vector<bool>> visited;
int ans = 0;
vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

void dfs(int r, int c, int count, int sum) {
    if (count == 4) {
        ans = max(ans, sum);
        return;
    }
    for (int d = 0; d < 4; d++) {
        int nr = r + dx[d];
        int nc = c + dy[d];
        if (nr >= 0 && nr < N && nc >= 0 && nc < M && !visited[nr][nc]) {
            visited[nr][nc] = true;
            dfs(nr, nc, count + 1, sum + grid[nr][nc]);
            visited[nr][nc] = false; 
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    grid.assign(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> grid[i][j];
        }
    }
    visited.assign(N, vector<bool>(M, false));
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
   
            visited[i][j] = true;
            dfs(i, j, 1, grid[i][j]);
            visited[i][j] = false;
     
            int sumT = grid[i][j];
            int mini = INT_MAX;
            int cnt = 0;
            for (int d = 0; d < 4; d++){
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (ni >= 0 && ni < N && nj >= 0 && nj < M) {
                    cnt++;
                    sumT += grid[ni][nj];
                    mini = min(mini, grid[ni][nj]);
                }
            }
            if (cnt >= 3) {
               
                if (cnt == 4) sumT -= mini;
                ans = max(ans, sumT);
            }
        }
    }
    
    cout << ans << "\n";
    return 0;
}