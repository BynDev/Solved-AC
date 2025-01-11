#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
    int N; cin >> N;
    
    vector<long long> Road(N-1);
    vector<long long> Station(N);
    
    for(int i = 0; i < N-1;i++)
    {
        cin >> Road[i];
    }
    for(int i = 0; i < N;i++)
    {
        cin >> Station[i];
    }

    vector<long long> DP(N);

    DP[0] = 0;
    long long num1 = Station[0];
    DP[1] = Road[0] * num1;

    for(int i = 2; i < N; i++)
    {
        if(Station[i-1] < num1)
        {
            num1 = Station[i-1];
        }
        DP[i] = DP[i-1] + (Road[i-1] * num1);
    }

    cout << DP[N-1]; 
}