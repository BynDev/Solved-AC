#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int N;
    cin >> N;
    vector<int> CardNumber(N);

    for (int i = 0; i < N; ++i) {
        cin >> CardNumber[i];
    }
    
    int M;
    cin >> M;
    vector<pair<int, int>> CompareNumber(M);

    for (int i = 0; i < M; ++i) {
        cin >> CompareNumber[i].first;
        CompareNumber[i].second = i;
    }

    sort(CardNumber.begin(), CardNumber.end()); 

    vector<int> AnswerNumber(M, 0);

    for (int j = 0; j < M; j++) {
       
        if (binary_search(CardNumber.begin(), CardNumber.end(), CompareNumber[j].first)) {
            AnswerNumber[CompareNumber[j].second] = 1; 
        }
    }

    for (int k = 0; k < M; k++) {
        cout << AnswerNumber[k] << " ";
    }
    return 0;
}
