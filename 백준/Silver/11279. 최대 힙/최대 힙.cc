#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    priority_queue<long long> pq;
    
    while(N--){
        long long x;
        cin >> x;
        if(x == 0){
            if(pq.empty()){
                cout << 0 << "\n";
            } else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        } else{
            pq.push(x);
        }
    }
    return 0;
}