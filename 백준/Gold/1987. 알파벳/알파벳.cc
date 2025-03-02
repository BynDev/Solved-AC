#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

struct arr {
    int i;
    int j;
    int count;
    int visited; // 현재까지 방문한 알파벳을 비트마스크로 관리 (A: 1<<0, B: 1<<1, ...)
};

vector<int> dx = {1, -1, 0, 0};
vector<int> dy = {0, 0, 1, -1};

int main(){
    int R, C;
    cin >> R >> C;
    
    // 각 행을 한 줄씩 입력받음
    vector<string> v(R);
    for (int i = 0; i < R; i++){
        cin >> v[i];
    }
    
    // 초기 상태: (0,0) 위치, count = 1, 시작 알파벳을 방문 상태에 추가
    stack<arr> s;
    int initVisited = 1 << (v[0][0] - 'A');
    s.push({0, 0, 1, initVisited});
    
    int maxCount = 0;
    
    while (!s.empty()){
        int now_i = s.top().i;
        int now_j = s.top().j;
        int now_count = s.top().count;
        int now_visited = s.top().visited;
        s.pop();
        
        if (maxCount < now_count) {
            maxCount = now_count;
        }
        
        // 4방향 탐색
        for (int d = 0; d < 4; d++){
            int next_i = now_i + dx[d];
            int next_j = now_j + dy[d];
            if (next_i >= 0 && next_i < R && next_j >= 0 && next_j < C){
                int letterBit = 1 << (v[next_i][next_j] - 'A');
                // 방문한 알파벳이 아니라면 이동
                if ((now_visited & letterBit) == 0) {
                    s.push({next_i, next_j, now_count + 1, now_visited | letterBit});
                }
            }
        }
    }
    
    cout << maxCount;
    return 0;
}