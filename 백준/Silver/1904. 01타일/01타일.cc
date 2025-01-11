#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;


int main(int argc, char* argv[])
{
    int N; cin >> N;

    vector<int>DP(N+1);

    DP[0] = 0;
    DP[1] = 1;
    DP[2] = 2;

    for(int i = 3; i < N + 1;i++)
    {
        DP[i] = (DP[i-1] + DP[i-2]) % 15746;
    }
    cout << DP[N];
}
