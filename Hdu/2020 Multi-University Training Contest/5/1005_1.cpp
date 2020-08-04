#include <bits/stdc++.h>

using namespace std; 

const int P = 998244353;
const int N = 6000000 + 10;

vector <pair<int, int>> opt;

long long qpow(long long a, long long k = P - 2) {
    long long res = 1;
    while (k) {
        if (k & 1)  res = res * a % P;
        a = a * a % P;
        k >>= 1;
    }
    return res;
}

int fac(int x) {
    int res = 1;
    for (int i = 1; i <= x; i++)    res *= i;
    return res;
}

int n, k, sum, a[210], b[210];
int calc(int *a, int n) {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += (a[i] != i);
    }
    return res * k;
}
void dfs(int dps) {
    if (dps == n + 1) {
        int sz = fac(opt.size());
        for (int i = 1; i <= n; i++)    b[i] = a[i];
        int res = calc(b, n);
        for (int i = 0; i < sz; i++) {
            for (int j = 1; j <= n; j++)    b[j] = a[j];
            for (int j = 0; j < (int)opt.size(); j++) {
                // if (a[1] == 1 && a[2] == 1 && a[3] == 2) {
                //     if (calc(b, n) + j == 1) {
                //         puts("~~~~~~~~~~~~");
                //         for (int _ = 1; _ <= n; _++) {
                //             printf("%d ", a[_]);
                //         } puts("");
                //         for (int _ = 1; _ <= n; _++) {
                //             printf("%d ", b[_]);
                //         } puts("");
                //         for (int _ = 0; _ < j; _++) {
                //             printf("(%d, %d), ", opt[_].first, opt[_].second);
                //         } puts("");
                //         puts("~~~~~~~~~~~~");
                //     }
                // }
                res = min(res, calc(b, n) + j);
                swap(b[opt[j].first], b[opt[j].second]);
                res = min(res, calc(b, n) + j + 1);
            }
            next_permutation(opt.begin(), opt.end());
        }
        // puts("\n____________________");
        // for (int i = 1; i <= n; i++) {
        //     cout << a[i] << ' ';
        // } cout << ", " << res << '\n';
        // puts("____________________");
        sum += res;
        return;
    }
    for (int i = 1; i <= n; i++) {
        a[dps] = i;
        dfs(dps + 1);
        a[dps] = 0;
    }
}

int main() {
    for (n = 1; n <= 5; n++) {
        printf("n = %d, ", n);
        for (k = 1; k <= 2; k++) {
            opt.clear();
            for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    opt.push_back({i, j});
                }
            }
            sum = 0;
            dfs(1);
            printf("(k = %d) (%4d / %4lld = %10lld) ", k, sum, qpow(n, n), sum * qpow(qpow(n, n)) % P);
        } puts("");
    }
    
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}