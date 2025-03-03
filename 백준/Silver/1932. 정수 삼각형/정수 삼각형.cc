#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<vector<int>>V;

    for (int i = 1; i <= n; i++)
    {
        vector<int>v(i);
        
        for (int j = 0; j < i; j++)
        {
            cin >> v[j];
        }

        V.push_back(v);
    }
    
    vector<vector<int>>DP;
    DP.push_back(V[0]);

    for (int i = 1; i < n; i++)
    {
        vector<int>dp(i+1);
        
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
               dp[j] = V[i][j] + DP[i - 1][j];
            }
            else if (j == i)
            {
                dp[j] = V[i][j] + DP[i - 1][j-1];
            }
            else
            {
                dp[j] = V[i][j] + max(DP[i-1][j],DP[i-1][j - 1]);
            }
        }
        DP.push_back(dp);
    }

    int max{0};

    for (int i = 0; i < n; i++)
    {
        if (DP[n-1][i] > max)
        {
            max = DP[n-1][i];
        }
    }

    cout << max << endl;
    
}