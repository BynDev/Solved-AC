#include <iostream>
#include <vector>
#include<cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N; cin >> N;

    int tmp {static_cast<int>(sqrt(N))};
    vector<int>DP(N+1,0);
    
    for(int i = 1; i <= N; i++)
    {
        int min {DP[i - 1]};
        for(int j = 2; j <= tmp; j++)
        {
            if(i >= j*j)
            {
                if(DP[i - j * j] < min)
                {
                    min = DP[i - j * j];
                }
            }
        }
        DP[i] = min + 1;
    }
    cout << DP[N];
    /*
    for(auto &i:DP)
    {
        cout << i << endl;
    }*/
}
    
    

    /*
    while(true)
    {
        if(N - (tmp * tmp) < 0)
        {
            tmp--;
            continue;
        }
        N -= (tmp * tmp);
        ans.push_back(tmp);
        if(N == 0)
        {
            break;
        }
    }
    cout << ans.size();*/