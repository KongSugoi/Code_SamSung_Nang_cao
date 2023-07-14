#include "bits/stdc++.h"
using namespace std;
const int MAX = 400005;
long long a[MAX];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
    
	int n,k; 
	cin >> n >> k;
	
	k *= 3;
	for(int i = 1; i <= n ; ++i) 
	
		cin >> a[i];
		
	vector<vector<long long>> dp;
	dp.resize(k + 5);
	
	for(int i = 0 ; i <= k ; ++i)
	{
		dp[i].resize(n + 5);
	}
	for(int i = 0 ; i <= n ; ++i)
	{
		dp[0][i] = 0;
	}
	for(int i = 1; i <= k ; ++i)
	{
		if(i % 3 == 2) 
			dp[i][i] = dp[i - 1][i - 1] - a[i];
		else 
			dp[i][i] = dp[i - 1][i - 1] + a[i];
		for(int j = i + 1; j <= n ; ++j)
		{
			if(i % 3 == 2)  
				dp[i][j] = max(dp[i - 1][j - 1] - a[j],dp[i][j - 1]);
			else 
				dp[i][j] = max(dp[i - 1][j - 1] + a[j],dp[i][j - 1]);
		}
	}
	cout << dp[k][n];
    return 0;
}