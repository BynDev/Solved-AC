#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 내림차순 정렬을 위해 compare 함수 수정
bool compare(int i, int j)
{
    return i > j; // 오름차순 -> 내림차순으로 변경
}

// 랭킹을 구하는 함수
int CheckRanking(const vector<int>& Scores, int MyScores)
{
    // Scores는 내림차순 정렬된 상태라 가정
    int check = Scores[0];
    int ranking = 1;

    for(int i = 0; i < (int)Scores.size(); i++)
    {
        if (Scores[i] < check) 
        {
            ranking = i + 1;   // i번째가 아니라 i+1번째가 실제 등수
            check = Scores[i];
        }
        if (Scores[i] == MyScores)
        {
            return ranking;   // 여기서 바로 return
        }
    }
    // 만약 다 돌았는데도 같은 점수가 없다면 (이론상 거의 없겠지만)
    return Scores.size() + 1;
}

int MyRanking(vector<int>& Scores, int MyScore, int P)
{
    // 현재 랭킹 리스트에 여유가 있는 경우
    if((int)Scores.size() < P)
    {
        Scores.push_back(MyScore);
        sort(Scores.begin(), Scores.end(), compare);
        return CheckRanking(Scores, MyScore);
    }
    else
    {
        // 리스트가 꽉 차있으면, P등(내림차순 정렬 시, Scores[P-1]은 가장 낮은 점수)을 확인
        // 새 점수가 이보다 좋지(크지) 않으면 -1
        if(Scores[P-1] >= MyScore)
        {
            return -1; 
        }
        else
        {
            // 더 좋은 점수면 교체 후 정렬
            Scores[P-1] = MyScore;
            sort(Scores.begin(), Scores.end(), compare);
            return CheckRanking(Scores, MyScore);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, MyScore, P;
    cin >> N >> MyScore >> P;

    vector<int> Scores;
    for(int i = 0; i < N; i++)
    {
        int score;
        cin >> score;
        Scores.push_back(score);
    }

    // 내림차순 정렬
    sort(Scores.begin(), Scores.end(), compare);

    cout << MyRanking(Scores, MyScore, P) << "\n";

    return 0;
}