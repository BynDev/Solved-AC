#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

vector<bool>visited(10000,false);

struct DSLR
{
    char func;
    int num;
    string ans;
};

int D(int n) 
{
    n *= 2;
    if(n > 9999)
    {
        n %= 10000;
    }
    return n;
}

int S(int n) 
{
    n = n - 1;
    if(n == -1)
    {
        n = 9999;
    }
    return n;
}

int L(int n) {
    return (n % 1000) * 10 + (n / 1000);
}

int R(int n) {
    return (n % 10) * 1000 + (n / 10);
}

string bfs(int A,int B)
{
    queue<DSLR>q;
    fill(visited.begin(), visited.end(), false);
    
    q.push({' ',A,""});
    visited[A] = true;

    while(!q.empty())
    {
        char now_func = q.front().func;
        int now_num = q.front().num;
        string now_ans = q.front().ans;
        q.pop();
        
        if(now_num == B)
        {
            return now_ans;
        }
        if(visited[D(now_num)] == false)
            {
                visited[D(now_num)] = true;
                q.push({'D',D(now_num),now_ans + 'D'});
            }
        if(visited[S(now_num)] == false)
            {
                visited[S(now_num)] = true;
                q.push({'S',S(now_num),now_ans + 'S'});
            }
        if(visited[L(now_num)] == false)
            {
                visited[L(now_num)] = true;
                q.push({'L',L(now_num),now_ans + 'L'});
            }
        if(visited[R(now_num)] == false)
            {
                visited[R(now_num)] = true;
                q.push({'R',R(now_num),now_ans + 'R'});
            }
        }
    }

int main(){
    int T; cin >> T;
    for(int i = 0; i < T ;i++)
    {
        int A,B; cin >> A >> B;
        cout << bfs(A,B) << endl;
    }
}