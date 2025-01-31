#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int findSquare(vector<string>Square,int N, int M)
{
    int tmp = min(N,M);
    while(true)
    {
        for(int i = 0; i <= N - tmp; i++)
        {
            for(int j = 0; j <= M - tmp ;j++){
                if (Square[i][j] == Square[i + tmp - 1][j] && Square[i][j] == Square[i][j + tmp - 1] && Square[i][j] == Square[i + tmp - 1][j + tmp - 1])
                {
                    return tmp * tmp;
                }
            }
        }
        tmp--;
        if(tmp == 1)
        {
            return 1;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M; cin >> N >> M;
    vector<string>Square(N);
    
    for(int i = 0; i < N ;i++)
    {
        string col; cin >> col;
        Square[i] = col;
    }

    cout << findSquare(Square,N,M);
}