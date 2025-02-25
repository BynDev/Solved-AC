#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int r, c;
vector<vector<int>> min_box = {{0, 1}, {2, 3}}; 

int divide(int N, int i, int j, int cnt)
{
    if(N == 1)
    {
        for(int now_i = 0; now_i < 2; now_i++)
        {
            for(int now_j = 0; now_j < 2; now_j++)
            {
                if(r == now_i + i && c == now_j + j)
                {
                    return cnt + min_box[now_i][now_j];
                }
            }
        }
    }
    int cal = pow(2, N - 1);
    if(r < i + cal && c < j + cal)            // 좌상단 사분면
        return divide(N - 1, i, j, cnt);
    else if(r < i + cal && c >= j + cal)       // 우상단 사분면
        return divide(N - 1, i, j + cal, cnt + cal * cal);
    else if(r >= i + cal && c < j + cal)       // 좌하단 사분면
        return divide(N - 1, i + cal, j, cnt + 2 * cal * cal);
    else                                     // 우하단 사분면
        return divide(N - 1, i + cal, j + cal, cnt + 3 * cal * cal);
}

int main(){
    int N;
    cin >> N >> r >> c;
    cout << divide(N, 0, 0, 0);
}
