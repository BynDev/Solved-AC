#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> diff(N);
    for(int i = 0; i < N; i++){
        long long A, B;
        cin >> A >> B;
        diff[i] = B - A;  
    }
    
    sort(diff.begin(), diff.end());
    
    if(N % 2 == 1) {
        cout << 1 << "\n";
    } 
    else {
        long long m1 = diff[N/2 - 1];
        long long m2 = diff[N/2];
        cout << (m2 - m1 + 1) << "\n";
    }

    return 0;
}

