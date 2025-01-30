#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

string addStrings(const string &a, const string &b) {
    int carry = 0;
    string result;
    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += (a[i--] - '0');
        if (j >= 0) sum += (b[j--] - '0');
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }
    reverse(result.begin(), result.end());
    return result;
}
string multiplyBy2(const string &s) {
    int carry = 0;
    string result;

    for (int i = s.size() - 1; i >= 0; i--) {
        int prod = (s[i] - '0') * 2 + carry;
        carry = prod / 10;
        result.push_back((prod % 10) + '0');
    }
    if (carry) result.push_back(carry + '0');
    reverse(result.begin(), result.end());
    return result;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    vector<string> DP(251);

    DP[0] = "1";
    DP[1] = "1";

    DP[2] = "3";
    for (int i = 3; i <= 250; i++) {
        string temp = multiplyBy2(DP[i - 2]);
        DP[i] = addStrings(DP[i - 1], temp);
    }

    int n;
    while (true) {
        if (!(cin >> n)) break; 
        cout << DP[n] << "\n";
    }
    return 0;
}