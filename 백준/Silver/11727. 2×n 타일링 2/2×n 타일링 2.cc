#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    const int mod = 10007;
    int dp[1001] = {0};
    
    dp[0] = 1;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++){
        dp[i] = (dp[i - 1] + 2 * dp[i - 2]) % mod;
    }
    
    cout << dp[n] << endl;
    return 0;
}