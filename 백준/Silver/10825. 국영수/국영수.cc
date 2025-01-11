#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cmath>
using namespace std;

struct STUDENT
{
    string name;
    int korean;
    int english;
    int math;
};

bool Compare(STUDENT A, STUDENT B)
{
    if(A.korean == B.korean && A.english == B.english && A.math == B.math)
    {
        return A.name < B.name;
    }
    else if(A.korean == B.korean && A.english == B.english)
    {
        return A.math > B.math;
    }
    else if(A.korean == B.korean)
    {
        return A.english < B.english;
    }
    else
    {
        return A.korean > B.korean;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    vector<STUDENT>vec(N);
    
    for(int i = 0; i < N; i++)
    {
        cin >> vec[i].name >> vec[i].korean >> vec[i].english >> vec[i].math;
    }

    sort(vec.begin(),vec.end(),Compare);

    for(int i = 0; i < N; i++)
    {
        cout << vec[i].name << '\n';
    }
}
