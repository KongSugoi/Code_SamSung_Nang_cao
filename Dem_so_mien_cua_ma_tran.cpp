#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define sz size()
#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)
#define vi vector<int>

void Try(int i, int j, vector<vector<int>> &res)
{
    if(i < 0 || j < 0 || j >= res[0].sz || i >= res.sz || !res[i][j]) return;
    res[i][j] = 0;
    Try(i + 1, j, res);
    Try(i - 1, j, res);
    Try(i, j - 1, res);
    Try(i, j + 1, res);
    Try(i + 1, j + 1, res);
    Try(i-1, j - 1, res);
    Try(i + 1, j - 1, res);
    Try(i - 1, j + 1, res);
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        int a[n][m];
        vi v;
        vector<vi> res;
        F(i, 0, n)
        {
            F(j, 0, m)
            {
                scanf("%d", &a[i][j]);
                v.pb(a[i][j]);
            }
            res.pb(v);
            v.clear();
        }
        int cnt = 0;
        F(i, 0, res.sz)
        {
            F(j, 0, res[0].sz)
            {
                if(res[i][j] == 1)
                {
                    ++cnt;
                    Try(i, j, res);
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}