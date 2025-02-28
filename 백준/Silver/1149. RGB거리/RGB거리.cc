#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>DP{1001,vector<int>(1001,0)};

struct House
{
    int R;
    int G;
    int B;
};

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    
    int N; cin >> N;
    vector<House>v(N);
    for(int i = 0; i < N ;i++)
    {
        int R,G,B; cin >> R >> G >> B;
        v[i] = {R,G,B};
    }

    DP[0][0] = v[0].R;
    DP[0][1] = v[0].G;
    DP[0][2] = v[0].B;
    
    for(int i = 1; i < N; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(j == 0)
            {
                DP[i][j] = v[i].R + min(DP[i-1][1],DP[i-1][2]);
            }
            else if(j == 1)
            {
                DP[i][j] = v[i].G + min(DP[i-1][0],DP[i-1][2]);
            }
            else if(j == 2)
            {
                DP[i][j] = v[i].B + min(DP[i-1][0],DP[i-1][1]);
            }
        }
    }
    cout << min(DP[N-1][0], min(DP[N-1][1], DP[N-1][2]));
    return 0;
}