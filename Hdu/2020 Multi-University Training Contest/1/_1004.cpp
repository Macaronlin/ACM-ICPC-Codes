#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;
long long qpow(long long a, long long k = P - 2) {
    long long res = 1;
    while (k) {
        if (k & 1)  res = res * a % P;
        k >>= 1;
        a = a * a % P;
    }
    return res;
}

bool check(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != s[s.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int minv;
int cnt[123];
void dfs(int dps, int lim, string s) {
    if (dps == lim) {
        unordered_set <string> st;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                string t = s.substr(i, j - i + 1);
                if (check(t)) {
                    st.insert(t);
                }
            }
        }
        cnt[st.size()]++;
        return;
    }
    for (int i = 0; i < 26; i++) {
        s.push_back(i + 'a');
        dfs(dps + 1, lim, s);
        s.pop_back();
    }
}

int main() {
    srand(time(0));
    for (int n = 1; n <= 6; n++) {
        memset(cnt, 0, sizeof(cnt));
        
        dfs(0, n, "");
        cout << n << ':';
        for (int j = 0; j < 6; j++) {
            cout << cnt[j] << ' ';
        } cout << endl;
    }
    system("pause");
    return 0;
}