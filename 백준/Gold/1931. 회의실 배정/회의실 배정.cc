#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main(){
    int N; cin >> N;
    vector<pair<int,int>>v(N);
    for(int i = 0; i < N;i++)
    {
        cin >> v[i].second >> v[i].first;
    }
    sort(v.begin(),v.end());

    int cur = v[0].first;
    int count {1};
    for(int j = 1; j < N ;j++)
    {
        if(cur <= v[j].second)
        {
            cur = v[j].first;
            count++;
        }
    }
    cout << count;
}