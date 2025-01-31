#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<int> makePattern(string word)
{
    unordered_map<char, int> visited;
    vector<int> pattern;
    int idx = 0;

    for(char c : word)
    {
        if (visited.find(c) == visited.end()) {
            visited[c] = idx++;
        }
        pattern.push_back(visited[c]);   
    }
        
    return pattern;
}

long long combination(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;

    long long result = 1;
    for (int i = 1; i <= r; i++) {
        result = result * (n - i + 1) / i;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    vector<vector<int>> patterns;
    patterns.reserve(N);

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        patterns.push_back(makePattern(s));
    }

    sort(patterns.begin(), patterns.end());

    long long ans = 0;
    int cnt = 1; 
    for (int i = 1; i < N; i++) {
        if (patterns[i] == patterns[i-1]) {
            cnt++;
        } else {
            ans += combination(cnt, 2);
            cnt = 1; 
        }
    }
    ans += combination(cnt, 2);

    cout << ans << "\n";
}