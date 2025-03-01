#include <iostream>
#include <queue>
#include <vector>
#include<set>
using namespace std;

struct Shortcut {
    int start, end, length;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    cin >> N >> D;
    vector<Shortcut> shortcuts(N);
    for (int i = 0; i < N; i++)
    {
        cin >> shortcuts[i].start >> shortcuts[i].end >> shortcuts[i].length;
    }
    vector<int>DP(D+1,0); 
    for(int i=1;i <= D;i++)
    {
        DP[i] = i;
    }

    for (int i = 0; i <= D; i++)
    {
        if (i+1 <= D)
        {
            DP[i+1] = min(DP[i]+1, DP[i+1]);
        }
        for (auto& j : shortcuts)
        {
            if (j.end <= D && j.start == i)
            {
                DP[j.end] = min(DP[j.end], DP[j.start] + j.length);
            }
        }
    }

    cout << DP[D];
    return 0;
}
