#include <iostream>
#include <vector>
#include <deque>
#include <string>

using namespace std;

deque<int> string_to_Arr(const string &arr)
{
    deque<int> v;
    string num = "";
    for (int i = 1; i < arr.size()-1; i++)
    {
        if(isdigit(arr[i]))
        {
            num.push_back(arr[i]); 
        }
        else if(arr[i] == ',')
        {
            if(!num.empty())
            {
                v.push_back(stoi(num)); 
                num = "";
            }
        }
    }
 
    if(!num.empty())
    {
        v.push_back(stoi(num));
    }
    return v;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int T; cin >> T;
    for(int i = 0; i < T; i++)
    {
        string function; cin >> function;
        int n; cin >> n;
        string arr; cin >> arr;
        deque<int>d = string_to_Arr(arr);
        bool err = false;
        bool reversed = false;
        for(auto& f : function)
        {
            if(f =='R')
            {
                if(reversed == false)
                {
                    reversed = true;
                }
                else if(reversed == true)
                {
                    reversed = false;
                }
            }
            else if (f =='D')
            {
                if(!d.empty())
                {
                    if(reversed == false)
                    {
                        d.pop_front();
                    }
                    else if(reversed == true)
                    {
                        d.pop_back();
                    }
                }
                else
                {
                    err = true;
                    break;
                }
            }
        }
        if(reversed == true)
        {
            deque<int>outcome;
            for(int o = d.size()-1; o >= 0; o--)
            {
                outcome.push_back(d[o]);
            }
            d = outcome;
            outcome.clear();
        }
        
        if(err == true)
        {
            cout << "error" << endl;
            err = false;
        }
        else
        {
            cout << '[';
            for(int c = 0; c < d.size(); c++)
            {
                if(c != d.size()-1)
                {
                    cout << d[c] << ',';
                }
                else
                {
                    cout << d[c];
                }
            }
            cout << ']' << endl;
        }
    }
}