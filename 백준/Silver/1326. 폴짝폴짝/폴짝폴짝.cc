#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Graph {
    int Stair; // 현재 징검다리 번호
    int Mul;   // 현재 징검다리에 쓰인 값
    int Level; // 점프 횟수
};

int bfs(const vector<pair<int,int>>& v, int a, int b)
{
    int N = v.size() - 1;          // v가 1~N 인덱스 사용
    vector<bool> visited(N+1,false);

    queue<Graph> q;
    // a번 징검다리에서 시작
    q.push({a, v[a].second, 0});
    visited[a] = true;

    while(!q.empty()) {
        int stair = q.front().Stair; // 현재 위치
        int mul   = q.front().Mul;   // 그 위치에 쓰인 값
        int level = q.front().Level;
        q.pop();

        // b번 징검다리에 도달하면 점프 횟수 리턴
        if(stair == b) {
            return level;
        }

        // 모든 징검다리(1 ~ N)를 확인
        // "stair와 next의 거리가 mul의 배수"면 점프 가능
        for(int next = 1; next <= N; next++) {
            if(!visited[next] && (abs(next - stair) % mul == 0)) {
                visited[next] = true;
                q.push({next, v[next].second, level + 1});
            }
        }
    }

    // 큐가 빌 때까지 b를 찾지 못했다면 -1
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int,int>> v(N+1);
    // v[i].first = i (징검다리 번호), v[i].second = 쓰여있는 값
    for(int i = 1; i <= N; i++){
        v[i].first = i;
        cin >> v[i].second;
    }

    int a, b;
    cin >> a >> b;

    cout << bfs(v, a, b) << "\n";
    return 0;
}
