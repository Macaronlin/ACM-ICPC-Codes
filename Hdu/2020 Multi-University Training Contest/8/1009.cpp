#include <bits/stdc++.h>

using namespace std; 

int gcd(int a, int b) { return !b ? a : gcd(b, a % b); }

const int N = 5000000 + 10;
char s[N];
int n, sum[N][26];
vector <int> work() {
    vector <int> res;
    int x = n;
    for (int j = 0; j < 26; j++) {
        if (sum[n][j]) {
            x = gcd(x, sum[n][j]);
        }
    }
    int kx = sqrt(n + 0.5);
    for(int i = 1; i <= kx; i++) {
        if (x % i == 0) {
            res.push_back(i);
            if (x / i > i && i != 1) {
                res.push_back(x / i);
            }
        }
    }
    sort(res.begin(), res.end());
    int minv = -1;
    for (auto d : res) {
        bool flag = true;
        for (int i = 1; i <= n && flag; i += d) {
            for (int j = 0; j < 26; j++) {
                if (sum[i][j] != ((i - 1) / d + 1) * sum[d][j]) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) {
            minv = d;
            break;
        }
    }
    vector <int> res2;
    for (auto d : res) {
        if (d % minv == 0) {
            res2.push_back(d);
        }
    }
    return res2;
}

const int P = 1000000000 + 9;
const int bas = 233;
int mul(int a, int b) { return 1LL * a * b % P; }
int add(int a, int b) { return a + b < P ? a + b : a + b - P; }
int sub(int a, int b) { return a - b < 0 ? a - b + P : a - b; }

int hs[N], hs2[N], _pow[N];
char t[N];

int calc(int *hs, int l, int r) {
    return sub(hs[r], mul(hs[l - 1], _pow[r - l + 1]));
}

int main() {
    _pow[0] = 1;
    for (int i = 1; i < N; i++) _pow[i] = mul(_pow[i - 1], bas);
    int T;  scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        scanf("%s", s + 1);
        if (n == 1) {
            puts("No");
            continue;
        }
        for (int i = 1; i <= n; i++) {
            int c = s[i] - 'a';
            for (int j = 0; j < 26; j++) {
                sum[i][j] = sum[i - 1][j] + (c == j);
            }
            hs[i] = add(mul(hs[i - 1], bas), s[i]);
        }
        vector <int> vec = work();
        bool flag;
        for (auto len : vec) {
            // int k = n / len;
            memcpy(t + 1, s + 1, len);
            memcpy(t + 1 + len, s + 1, len);
            for (int i = 1; i <= 2 * len; i++) {
                hs2[i] = add(mul(hs2[i - 1], bas), t[i]);
            }
            unordered_set <int> ust;
            vector <int> all;
            for (int i = 1; i <= len; i++) {
                ust.insert(calc(hs2, i, i + len - 1));
            }
            flag = true;
            for (int i = 1; i <= n; i += len) {
                if (!ust.count(calc(hs, i, i + len - 1))) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                break;
            }
        }
        puts(flag ? "Yes" : "No");
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}