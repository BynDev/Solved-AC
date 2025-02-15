#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;

    int ans = 0;     
    int count = 0;    

    for (int i = 1; i < M - 1; i++) {
        if (S[i - 1] == 'I' && S[i] == 'O' && S[i + 1] == 'I') {
            count++;   
            if (count == N) {  
                ans++;
                count--;   
            }
            i++;
        } else {
            count = 0;
        }
    }

    cout << ans;
    return 0;
}