#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

bool CountGood(int A, int B,vector<int>X)
{
    for(int i = A; i <= B; i++)
    {
        for(auto&j : X){
            if(i == j)
            {
                return false;
            }
        }
    }
     return true;   
}

int  main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int L {0};
    cin >> L;

    vector<int>S;
    
    for(int i = 0;i < L; i++)
    {
        int num;
        cin >> num;
        S.push_back(num);
    }

    int n{0};
    cin >> n;

    int ans{0};

    for(int i = 1;i<1000;i++)
    {
        for(int j = 1000; j > 1 ;j--)
        {
            if(i <= n && n <= j && i != j)
            {
                if(CountGood(i,j,S))
                {
                    ans++;
                }
            }
        }
    }
    cout << ans;
}