#include <iostream>
using namespace std;

int main()
{
    long long N;
    int L;
    cin >> N >> L;

    int ans {-1};
    int cnt = L;
    
    for(int k = L; k <= 100; k++)
    {
        long long tmp = N - k*(k-1)/2;

        if(tmp >= 0 && tmp % k == 0)
        {
            ans = tmp / k;
            cnt = k;
            break;
        }
    }
    if(ans == -1)
    {
        cout << -1;
    }
    else{
    for(int i = 0; i < cnt; i++)
    {
        cout << ans + i << ' ';
    }
    }
}

