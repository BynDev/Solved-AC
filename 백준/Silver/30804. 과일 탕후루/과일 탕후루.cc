#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int>v(N);
    for(int i = 0; i < N; i++)
    {
        cin >> v[i];
    }

    vector<int>frequent(10,0);
    int chk{0};
    int max{0};
    
    deque<int>d;
    
    for(int i = 0; i < N; i++)
    {
        d.push_back(v[i]);
        if(frequent[v[i]] == 0)
        {
            chk++;
        }
        frequent[v[i]]++;

        while(chk > 2){
            int fruit = d.front();
            d.pop_front();
            frequent[fruit]--;
            if(frequent[fruit] == 0) {
                chk--;
            }
        }
        int sum {0};
        for(auto &i:frequent)
        {
            sum += i;
        }
        if(sum > max)
        {
            max = sum;
        }
    }
    cout << max;
    return 0;
}