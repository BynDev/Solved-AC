#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Meeting {
    int T;
    int P;
};

int main() {
    int N; 
    cin >> N;

    vector<Meeting> Table(N + 1); // 1-based indexing
    for(int i = 1; i <= N; i++) {
        cin >> Table[i].T >> Table[i].P;
    }

    // DP[i] : i일부터 퇴사일까지 낼 수 있는 최대 이익
    vector<int> DP(N + 2, 0); // N + 1일과 N + 2일을 포함

    // 뒤에서부터 계산
    for(int i = N; i >= 1; i--) {
        int endDay = i + Table[i].T - 1;
        if(endDay > N) {
            DP[i] = DP[i + 1]; // 상담 불가능, 다음 날의 최대 이익을 그대로 가져옴
        } else {
            DP[i] = max(DP[i + 1], Table[i].P + DP[endDay + 1]);
        }
    }

    cout << DP[1] << endl;

    return 0;
}