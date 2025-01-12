#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, R;
    cin >> N >> M >> R;
    vector<vector<int>> arr(N, vector<int>(M));

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> arr[i][j];

    int layers = min(N, M) / 2;

    for (int layer = 0; layer < layers; ++layer) {
        int top = layer;
        int left = layer;
        int bottom = N - layer - 1;
        int right = M - layer - 1;
        
        vector<int> elems;
        for (int j = left; j <= right; ++j) elems.push_back(arr[top][j]);
        for (int i = top + 1; i <= bottom - 1; ++i) elems.push_back(arr[i][right]);
        for (int j = right; j >= left; --j) elems.push_back(arr[bottom][j]);
        for (int i = bottom - 1; i >= top + 1; --i) elems.push_back(arr[i][left]);

        int len = elems.size();
        int rotations = R % len;
        rotate(elems.begin(), elems.begin() + rotations, elems.end());
        
        int idx = 0;
        for (int j = left; j <= right; ++j) arr[top][j] = elems[idx++];
        for (int i = top + 1; i <= bottom - 1; ++i) arr[i][right] = elems[idx++];
        for (int j = right; j >= left; --j) arr[bottom][j] = elems[idx++];
        for (int i = bottom - 1; i >= top + 1; --i) arr[i][left] = elems[idx++];
    }
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}