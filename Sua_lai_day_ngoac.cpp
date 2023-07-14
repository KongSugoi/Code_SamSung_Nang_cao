#pragma GCC optimize("O2")
#include <bits/stdc++.h>
using namespace std;

void TestCase() {
    string s;
    cin >> s;

    stack<char> st;
    for (auto x : s) {
        if (x == '(')
            st.push(x);
        else {
            if (!st.empty() && st.top() == '(')
                st.pop();
            else
                st.push(x);
        }
    }

    int open = 0, close = 0;
    while (!st.empty()) {
        if (st.top() == '(')
            open++;
        else
            close++;
        st.pop();
    }
    
    int ans = open / 2 + close / 2;
    ans += open % 2 + close % 2;
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        TestCase();
        cout << endl;
    }
    return 0;
}