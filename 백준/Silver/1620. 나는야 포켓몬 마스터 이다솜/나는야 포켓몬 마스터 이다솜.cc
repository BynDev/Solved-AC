#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    vector<string> pokemons(N + 1);
    unordered_map<string, int> name_to_index;
    
    for (int i = 1; i <= N; ++i) {
        cin >> pokemons[i];
        name_to_index[pokemons[i]] = i;
    }
    
    while (M--) {
        string query;
        cin >> query;
        
        // 숫자인지 판별
        if(isdigit(query[0])) {
            // 숫자로 변환하여 인덱스로 사용
            int index = stoi(query);
            cout << pokemons[index] << "\n";
        } else {
            // 이름을 숫자로 변환
            cout << name_to_index[query] << "\n";
        }
    }
    
    return 0;
}