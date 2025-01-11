#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;


int  main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N,M;
    cin >> N >> M;

    vector<int>packages(M);
    vector<int>eachs(M);
    
    for (int i = 0; i < M; i++)
    {
        int package,each;
        cin >> package >> each;
        eachs[i] = each;
        packages[i] = package;
    }

    sort(eachs.begin(),eachs.end());
    sort(packages.begin(),packages.end());

    int MinEachProfit = eachs[0];
    int MinPackagesProfit = packages[0];
    
    int caseA = (N/6 + 1) * MinPackagesProfit;
    int caseB = N * MinEachProfit;
    int caseC = ((N/6) * MinPackagesProfit) + ((N%6) * MinEachProfit);
    
    cout <<  min({caseA,caseB,caseC});
}

