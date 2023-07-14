#include <bits/stdc++.h>
using namespace std;
int n, k, a[40005];
 
void solve()
{
	long long dp[n+1][n+1];
	
	for (int i=0; i<=n; i++)
		dp[0][i]=0;
 
	for (int i=1; i<=3*k; i++)
	{
		if (i>3*k)
			dp[i][i]= max(dp[i-1][i-1], dp[i-1][i]);
		else {
				int x=a[i];
				if (i%3==2)
					x *= -1;
				dp[i][i] = dp[i-1][i-1] + x;
		}
		
		for (int j=i+1; j<=n; j++)
		{
			int x=a[j];
			if (x%3==2)
				x *= -1;
			dp[i][j]=max(dp[i-1][j-1]+x, dp[i][j-1]);
		}
	}
		cout << dp[3*k][n];
}
void read()
{
	cin>>n>>k;
	for (int i=1; i<=n; i++)
		cin>>a[i];
}
int main ()
{
	read();
	solve();
}