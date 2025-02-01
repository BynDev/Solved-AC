#include <iostream>
#include <vector>
#include <algorithm>
#include<set>
using namespace std;

int N, M;
int arr[9];
bool used[9];
set<vector<int>>answers;

void backtrack(int depth) {
    if(depth == M)
    {
        vector<int>v(M);
        for (int i = 0; i < M; i++) {
            v[i] = arr[i];
        }
        sort(v.begin(),v.end());
        answers.insert(v);
        return;
    }
    for(int i = 1; i <= N; i++)
    {
        if(!used[i])
        {
            arr[depth] = i;
            used[i] = true;
            backtrack(depth+1);
            used[i] = false;
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    backtrack(0);

    for(auto & i : answers)
    {
        for(auto& j : i)
        {
            cout << j << ' ';
        }
        cout << endl;
    }
    
    return 0;
}