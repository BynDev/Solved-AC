#include <iostream>
#include <vector>
#include <set>
#include <map>
#include<cmath>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int>v(N);
    for(int i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    
    set<int> s(v.begin(), v.end());
    
    map<int, int> index_map;
    int idx = 0;
    for (int x : s)
    {
        index_map[x] = idx++;
    }
    for (int i = 0; i < N; i++)
    {
        cout << index_map[v[i]] << " ";
    }

    return 0;
}