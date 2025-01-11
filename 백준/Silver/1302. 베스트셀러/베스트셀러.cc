#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct BOOK
{
    string name;
    int count;
};

bool Compare(BOOK A, BOOK B)
{
    if(A.count == B.count)
    {
        return A.name < B.name;
    }
    else
    {
        return A.count > B.count;
    }
}

int  main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    vector<BOOK>vec(N);
    int j = 0;
    
    for(int i = 0; i < N ;i++)
    {
        string bookName;
        cin >> bookName;
        bool is_same = false;
        
        if(i == 0)
        {
            vec[0].name = bookName;
            vec[0].count = 1;
        }
        else
        {
            for(int p = 0; p < j+1; p++)
            {
                if(vec[p].name == bookName)
                {
                    vec[p].count++;
                    is_same = true;
                    break;
                }
            }
            if(is_same == false)
            {
                j++;
                vec[j].name = bookName;
                vec[j].count = 1;
            }
        }
    }
    sort(vec.begin(),vec.end(),Compare);
    
    cout << vec[0].name;
}