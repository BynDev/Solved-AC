#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

bool In_Circle(int x1, int y1, int x2, int y2, int cx, int cy, int r)
{
    double distance_1 = sqrt(pow(cx - x1,2) + pow(cy - y1,2));
    double distance_2 = sqrt(pow(cx - x2,2) + pow(cy - y2,2));
    if(distance_1 <= r && distance_2 <= r)
    {
        return false;
    }
    else if(distance_1 <= r || distance_2 <= r)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int T; cin >> T;

    for(int i = 0; i < T; i++)
    {
        int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
        int n; cin >> n;
        int ans {0};
        for(int j = 0; j < n; j++)
        {
            int cx,cy,r; cin >> cx >> cy >> r;
            if(In_Circle(x1,y1,x2,y2,cx,cy,r))
            {
              ans++;  
            }
        }
        cout << ans << endl;
    }
    
}

//출발점이 원 안에 있거나 도착점이 원 안에 있거나