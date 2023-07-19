#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define sz(A) (int) A.size()
#define FOR(i,l,r) for (int i=l;i<=r;i++)

typedef vector<int> data;

const int N = 1e5+5;
int n, q, a[N], L, R, k, res, cnt;
bool found;
data t[4*N], nil;

data combine(data u, data v) {
	data ans = nil;
	int i = 0, j = 0;
	while (i < sz(u) && j < sz(v)) {
		if (u[i] < v[j]) ans.pb(u[i++]);
		else ans.pb(v[j++]);
	}
	while (i < sz(u)) ans.pb(u[i++]);
	while (j < sz(v)) ans.pb(v[j++]);
	return ans;
}

void build(int k, int l, int r) {
	if (l == r) {
		t[k].pb(a[l]);
		return ;
	}
	int m = (l+r)/2;
	build(k*2, l, m);
	build(k*2+1, m+1, r);
	t[k] = combine(t[k*2], t[k*2+1]);
}

void get(int node, int l, int r) {
	if (r < L || R < l) return ;
	if (L <= l && r <= R) {
		int i = 0, j = sz(t[node])-1, pos = -1;
		while (i <= j) {
			int m = (i+j)/2;
			if (t[node][m] <= res) {
				pos = m;
				i = m+1;
			} else j = m-1;
		}
		if (pos == -1) return ;
		cnt += pos + 1;
		if (t[node][pos] == res) found = true, cnt--;
		return ;
	}
	int m = (l+r)/2;
	get(node*2,l,m);
	get(node*2+1,m+1,r);
}

int main() {

	scanf("%d", &n);
	FOR(i,1,n) scanf("%d", a+i);

	build(1,1,n);

	scanf("%d", &q);
	while (q--) {
		scanf("%d%d%d", &L, &R, &k);
		int l = 0, r = sz(t[1]) - 1;
		while (l <= r) {
			int m = (l+r)>>1;
			cnt = 0;
			found = false;
			res = t[1][m];
			get(1,1,n);
			if (cnt == k-1 && found) {
				printf("%d\n", res);
				break;
			}
			if (cnt < k) l = m+1;
			else r = m-1;
		}
	}

	return 0;
}
