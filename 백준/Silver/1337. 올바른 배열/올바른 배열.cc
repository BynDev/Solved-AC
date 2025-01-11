#include <iostream>       
#include <vector>          
#include <unordered_set>   
#include <algorithm>

using namespace std;

int main() {
    int N; cin >> N;
    vector<long long> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    // A가 비었으면 5개 전부 추가 필요
    if(N == 0) {
        cout << 5 << "\n";
        return 0;
    }

    // set(혹은 unordered_set)로 관리 (중복 없다고 했으니)
    unordered_set<long long> st(A.begin(), A.end());

    long long max_count = 0;

    // 배열 모든 원소 e에 대해 [e-4.. e]를 시작점으로 5연속 구간 검사
    for(auto & e : A){
        for(long long start = e - 4; start <= e; start++){
            if(start < 0) continue; // 음수가 되면 제외 (문제에서 원소는 음이 아닌 정수)
            long long count_in_range = 0;
            // 5연속 구간 [start, start+4]
            for(long long x = start; x <= start+4; x++){
                if(st.find(x) != st.end()){
                    count_in_range++;
                }
            }
            max_count = max(max_count, count_in_range);
        }
    }

    cout << 5 - max_count << "\n";
}
