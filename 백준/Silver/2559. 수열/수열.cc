#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int SlidingWindow(int K, vector<int>vec)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    vector<int>vec2;
    for(int i = 0; i <= vec.size() - K; i++)
    {
        int sum {0};
        for(int j = 0; j < K; j++)
        {
            sum += vec[i+j];
        }
        vec2.push_back(sum);
    }
    return *max_element(vec2.begin(), vec2.end());
}

int main()
{
    int N,K; cin >> N >> K;
    vector<int>vec(N);
    for(int i = 0; i < N ;i++)
    {
        cin >> vec[i];
    }
    cout << SlidingWindow(K,vec);
    
}