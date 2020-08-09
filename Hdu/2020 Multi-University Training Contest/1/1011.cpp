#include <bits/stdc++.h>

using namespace std;

const int P = 1000000007;
const int N = 1000000 + 10;
// const int P2 = 1000000009;

int add(int a, int b) { return a + b < P ? a + b : a + b - P; }
int sub(int a, int b) { return a - b < 0 ? a - b + P : a - b; }
int mul(int a, int b) { return 1LL * a * b % P; }

long long qpow(long long a, long long k = P - 2) {
    long long res = 1;
    while (k) {
        if (k & 1) res = res * a % P;
        k >>= 1;
        a = a * a % P;
    }
    return res;
}

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

int _pow[N];

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int work(string &s, int st) {
    auto pi = prefix_function(s);
    cout << s << ": ";
    for (auto x : pi) {
        cout << x << ' ';
    } cout << '\n';
    return 0;
}

int main() {
    // freopen("data.in", "r", stdin);
    // freopen("tst.out", "w", stdout);
    _pow[0] = 1;
    for (int i = 1; i < N; i++) _pow[i] = mul(_pow[i - 1], 1112);
    int _;  scanf("%d", &_);
    while (_--) {
        string s;   cin >> s;
        // for (int i = 1; i <= (int)s.size(); i++) {
        //     hs[i] = add(mul(hs[i - 1], 1112), s[i - 1]);
        // }
        vector <string> vs = duval(s);
        int sum = 0, ans = 0;
        for (auto s : vs) {
            ans = add(mul(ans, _pow[(int)s.size()]), work(s, sum));
            sum += (int)s.size();
        }
        printf("%d\n", ans);
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}