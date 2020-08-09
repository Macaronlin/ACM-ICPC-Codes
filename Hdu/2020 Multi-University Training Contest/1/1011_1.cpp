#include <bits/stdc++.h>

using namespace std;

// duval_algorithm
vector<string> duval(string const& s) {
    int n = s.size(), i = 0;
    vector<string> factorization;
    while (i < n) {
        int j = i + 1, k = i;
        while (j < n && s[k] <= s[j]) {
            if (s[k] < s[j])
                k = i;
            else
                k++;
            j++;
        }
        while (i <= k) {
            factorization.push_back(s.substr(i, j - k));
            i += j - k;
        }
    }
    return factorization;
}

const int N = 2000000 + 10;
const int P = 1000000000 + 7;
const int inv2 = 500000000 + 4;
long long _pow[N], sum[N];

int main() {
    _pow[0] = 1;
    for (int i = 1; i < N; i++) _pow[i] = _pow[i - 1] * 1112 % P;
    for (int i = 1; i < N; i++) sum[i] = (sum[i - 1] + _pow[i]) % P;
    string s;
    while (cin >> s) {
        auto vs = duval(s);
        long long ans = 0;
        for (int i = 0, now = 0; i < (int)vs.size(); now += vs[i++].size()) {
            cout << vs[i] << '\n';
            int L = now + 1, R = now + vs[i].size();
            long long tans = 1LL * (sum[R - 1] - sum[L - 2]) * L % P;
            ans = (ans + tans) % P;
        }
        printf("%lld\n", ans);    
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}