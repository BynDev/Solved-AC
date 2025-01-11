#include<iostream>
#include<cmath>
#include<vector>
#include <set>
using namespace std;

void vectorPut(int N, vector<string>&vec)
{
    for(int i = 0; i < N; i++)
    {
        string num;
        cin >> num;
        vec.push_back(num);
    }
}

bool Is_same(const vector<string>& vec) {
    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[i] == vec[j]) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int N;
    cin >> N;
    vector<string>vec;

    vectorPut(N,vec);

    int j = 0;
    while(true)
    {
        vector<string>check;
        for(auto& i : vec)
        {
            int len = i.size();
            check.push_back(i.substr(len - j, j));
        }
        if(!Is_same(check))
        {
            break;
        }
        j++;
    }
    cout << j;
}
