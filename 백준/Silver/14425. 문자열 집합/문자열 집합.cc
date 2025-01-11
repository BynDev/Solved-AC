#include<iostream>
#include<vector>
#include <algorithm>
#include<string>
using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,M;
    cin >> N >> M;
    vector<string>InputString(N);
    vector<string>CompareString(M);

    for(int i = 0; i < N; i++)
    {
        cin >> InputString[i];
    }
    for(int i = 0; i < M; i++)
    {
        cin >> CompareString[i];
    }

    sort(InputString.begin(), InputString.end());

    int ans = 0;
    
    for(int i = 0; i < M ;i++)
    {
        if(binary_search(InputString.begin(), InputString.end(),CompareString[i]) == true)
        {
            ans++;
        }
    }
    cout << ans;
}
