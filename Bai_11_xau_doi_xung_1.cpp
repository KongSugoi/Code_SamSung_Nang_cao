#include<bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)

int main()
{
    int t;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        int dp[41][41] = {};
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        F(i, 0, s.length())
        {
            F(j, 0, tmp.length())
            {
                if(s[i] == tmp[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
                else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        int M = dp[s.length()][tmp.length()];
        cout << s.length() - M << endl;
    }
    return 0;
}