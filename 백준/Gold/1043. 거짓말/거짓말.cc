#include <iostream>
#include <queue>
#include <vector>
#include<set>
using namespace std;

int main()
{
	int N,M; cin >> N >> M;

	set<int>graph[51]; //그래프 생성
	vector<bool>truth(51,false); //진실을 아는 사람들
	vector<vector<int>>parties(M);
	
	int truthCnt; cin >> truthCnt;
	for (int i = 0; i < truthCnt; i++) {
		int number; cin >> number;
		truth[number] = true;
	}
	
	for (int i = 0; i < M; i++) {
		int num; cin >> num;
		vector<int>nodes(num);
		vector<int>party(num);
		for (int j = 0; j < num; j++)
		{
			cin >> nodes[j];
			party[j] = nodes[j];
		}
		parties[i] = party;
		for (int p = 0; p < num; p++) {
			for (int k = 0; k < num; k++) {
				if (p != k) {  
					graph[nodes[p]].insert(nodes[k]);
				}
			}
		}
	}

	queue<int>q;
	
	for (int i = 1; i <= N; i++)
	{
		if (truth[i])
		{
			q.push(i);
			while (!q.empty())
			{
				int node = q.front();
				q.pop();
				for(auto &nd : graph[node])
				{
					if (truth[nd] == false)
					{
						truth[nd] = true;
						q.push(nd);
					}
				}
			}
		}
	}

	int ans{0};

	for(auto&i:parties)
	{
		bool exaggerate = true;
		for(auto&j:i)
		{
			if (truth[j] == true)
			{
				exaggerate = false;
			}
		}
		if (exaggerate == true)
		{
			ans++;
		}
	}
	cout << ans;
}

