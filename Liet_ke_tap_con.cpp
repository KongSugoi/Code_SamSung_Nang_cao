#include<bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int i = a; i <= b; ++i)
#define FORD(i, a, b) for(int i = a; i >= b; --i)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)

char x[20];
string s;
int n, k;
bool f[20];

void print(int i)
{
    string tmp = "";
    FOR(j, 0, i) tmp += x[j];
    cout << tmp << ' ';
}

void Try(int i, int cnt = 0)
{
    for(int j = i; j < n; ++j)
    {
        x[cnt] = s[j];
        if(!f[j])
        {
            f[j] = 1;
            print(cnt);
            Try(j + 1, cnt + 1);
            f[j] = 0;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        memset(f, 0, 20);
        cin >> n;
        cin >> s;
        Try(0);
        cout << endl;
    }
    return 0;
}