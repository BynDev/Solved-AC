#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;
int main()
{
    int N; cin >> N;
    int M; cin >> M;

    string S; cin >> S;
    
    int ans{0};
    bool is_I = false;
    bool is_O = false;

    for(int i = 0; i <= M - ((2 * N) + 1); i++)
    {
        if(S[i] == 'I')
        {
            is_I = true;
            int tmp{1};
            for(int j = i + 1 ; j < i + ((2 * N) + 1); j++)
            {
                if(S[j] == 'I' && is_O == true)
                {
                    is_I = true;
                    is_O = false;
                    tmp++;
                }
                else if(S[j] == 'O' && is_I == true)
                {
                    is_O = true;
                    is_I = false;
                    tmp++;
                }
                else
                {
                    break;
                }
            }
            if(tmp == (2*N)+1)
            {
                ans++;
            }
            is_O = false;
            is_I = false;
        }
    }
    cout << ans;
    return 0;
}
