#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    int a, b, c;
    cin >> a >> b >> c;
    
    int prevMax[3] = {a, b, c};
    int prevMin[3] = {a, b, c};
    
    for (int i = 1; i < n; i++) {
        cin >> a >> b >> c;
        
        int curMax[3], curMin[3];
        curMax[0] = a + max(prevMax[0], prevMax[1]);
        curMax[1] = b + max({prevMax[0], prevMax[1], prevMax[2]});
        curMax[2] = c + max(prevMax[1], prevMax[2]);
        
        curMin[0] = a + min(prevMin[0], prevMin[1]);
        curMin[1] = b + min({prevMin[0], prevMin[1], prevMin[2]});
        curMin[2] = c + min(prevMin[1], prevMin[2]);
        
        for (int j = 0; j < 3; j++) {
            prevMax[j] = curMax[j];
            prevMin[j] = curMin[j];
        }
    }
    
    int maxScore = max({prevMax[0], prevMax[1], prevMax[2]});
    int minScore = min({prevMin[0], prevMin[1], prevMin[2]});
    
    cout << maxScore << " " << minScore;
    
    return 0;
}
