#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <limits>
using namespace std;

int binary_search(const vector<int>&v, int min, int max, int K, int count)
{
    if (min > max) return max;
    
    int mid = (min + max) / 2;
    long long sum {0};

    for(auto &tree : v)
    {
        if (tree > mid) { sum += tree - mid; }
    }
    if(sum >= K)
    {
        return binary_search(v,mid + 1,max,K,count+1);
    }
    else
    {
        return binary_search(v,min,mid - 1,K,count+1);
    }
    
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M; cin >> N >> M;

    vector<int>v(N);
    
    for(int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    sort(v.begin(),v.end());

    int min = v[0];
    int max = v[v.size()-1];

    int ans = binary_search(v,0,max,M,1);
    cout << ans;
}