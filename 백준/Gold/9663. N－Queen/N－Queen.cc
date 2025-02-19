#include <iostream>
#include <cmath>
using namespace std;

int N, ans = 0;
int col[15];

bool isSafe(int row, int c) {
    for (int i = 0; i < row; i++) {
        if (col[i] == c || abs(col[i] - c) == row - i)
            return false;
    }
    return true;
}

void backtrack(int row) {
    if (row == N) {
        ans++;
        return;
    }
    for (int c = 0; c < N; c++) {
        if (isSafe(row, c)) {
            col[row] = c;    
            backtrack(row + 1); 
        }
    }
}

int main() {
    cin >> N;
    backtrack(0);
    cout << ans << endl;
    return 0;
}