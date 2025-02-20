#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    
    vector<int> board(101);
    for(int i = 1; i <= 100; i++){
        board[i] = i;
    }
    
    for(int i = 0; i < N; i++){
        int start, end;
        cin >> start >> end;
        board[start] = end;
    }
    
    for(int i = 0; i < M; i++){
        int start, end;
        cin >> start >> end;
        board[start] = end;
    }
 
    vector<int> moves(101, -1);
    queue<int> q;
    moves[1] = 0;
    q.push(1);
    
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        
        if(cur == 100) break;
        
        for(int dice = 1; dice <= 6; dice++){
            int next = cur + dice;
            if(next <= 100){
                next = board[next];
                if(moves[next] == -1){
                    moves[next] = moves[cur] + 1;
                    q.push(next);
                }
            }
        }
    }
    
    cout << moves[100];
    return 0;
}