#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include <cstring>
using namespace std;

int checkNum(vector<int>sequence, int N)
{
    vector<int>DP(N,1);
    for(int i = 1; i < N; i++)
    {
        for(int j = i-1; j >= 0; j--)
        {
            if(DP[j] + 1 > DP[i] && sequence[j] < sequence[i])
            {
                DP[i] = DP[j] + 1;
            }
        }
    }
    return *max_element(DP.begin(), DP.end());
}

int main()
{
    int N; cin >> N;
    vector<int>sequence(N);
    for(int i = 0; i < N; i++)
    {
        cin >> sequence[i];
    }
    cout << checkNum(sequence,N);
}
