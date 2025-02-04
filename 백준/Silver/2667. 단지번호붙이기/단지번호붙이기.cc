#include <iostream>
#include<queue>
#include<unordered_map>
#include<algorithm>
#include <vector>
#include<cmath>
using namespace std;

vector<int>height = {0,0,1,-1};
vector<int>width = {1,-1,0,0};

pair<int,vector<int>> bfs(vector<string>v,int N)
{
    queue<pair<int,int>>q;
    vector<int>answers;
    int count{0};
    int ans {0};

    bool check{false};
    for(int i = 0; i < N ; i++)
    {
        for(int j = 0; j < N ; j++)
        {
            if(v[i][j] == '1')
            {
                count++;
                v[i][j] = '0';
                q.push({i,j});
                check = true;
            }
            while(!q.empty())
            {
                int fir = q.front().first;
                int sec = q.front().second;
                ans++;
                q.pop();
                for(int k = 0; k < 4 ; k++)
                {
                    if(fir - height[k] < 0 || sec-width[k] < 0 || fir - height[k] >= N || sec - width[k] >= N)
                    {
                        continue;
                    }
                    if(v[fir - height[k]][sec-width[k]] == '1')
                    {
                        v[fir - height[k]][sec-width[k]] = '0';
                        q.push({fir - height[k],sec - width[k]});
                    }
                }
            }
            if(check)
            {
                answers.push_back(ans);
                ans = 0;
                check = false;
            }
        }
    }
    sort(answers.begin(),answers.end());
    pair<int,vector<int>>print = {count,answers};
    return print;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<string>v;
    
    for(int i = 0; i < N;i++)
    {
        string s; cin >> s;
        v.push_back(s);
    }

    pair<int,vector<int>>print = {bfs(v,N)};

    cout << print.first << endl;
    for(auto&i:print.second)
    {
        cout << i << endl;
    }
}