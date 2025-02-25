#include <iostream>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int M, N, x, y;
        cin >> M >> N >> x >> y;
        int answer = -1;
        
        for (int k = x; k <= M * N; k += M) {
           
            if (((k - 1) % N + 1) == y) {
                answer = k;
                break;
            }
        }
        
        cout << answer << "\n";
    }
    return 0;
}