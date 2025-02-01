#include <iostream>
using namespace std;

int N, M;
int arr[9];     
bool used[9];    

void backtrack(int depth) {
    if (depth == M) {  
        for (int i = 0; i < M; i++) {
            cout << arr[i] << (i == M - 1 ? "\n" : " ");
        }
        return;
    }
 
    for (int i = 1; i <= N; i++) {
        if (!used[i]) {   
            used[i] = true;
            arr[depth] = i;
            backtrack(depth + 1); 
            used[i] = false;       
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    backtrack(0);
    
    return 0;
}